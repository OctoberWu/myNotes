keywords: await-ahead-a-array

--- 
## 在 Array 的高階函數前面 await

面試問題
```js
await arr.forEach( async sec => await wait(sec) )
console.log('done')
// done
// 1 seconds pass
// 2 seconds pass
// 3 seconds pass
// 5 seconds pass
```

Q1. 為什麼 done 會先跑出來？
Ans:
await 只會去看後面是不是回傳 Promise ，才會去等，顯然 forEach 並不是 Promise 啦！

（雖然裡頭跑的是 async ，但那僅是丟進去 forEach 裡頭的 callback 喲）

Q2. 為啥沒有按照順序呀，而且總共好像才花五秒左右？
Ans:
forEach 所做的是只是一個一個抽出來丟到 callback 罷了，他們之間的回呼沒有等待的關係喲。

```js
// 你以為的
[  口     口    口    口  ]
-> cb 
      -> cb 
            -> cb 
                  -> cb 
// 實際上
[  
(1s) 口 -> cb
(3s) 口 -> -> -> cb
(5s) 口 -> -> -> -> -> cb
(2s) 口 -> -> cb
]
// 結果根本沒依序
```

### Sol 1: by tranditional way, for-loop
```js
for(let i of arr){
  await wait(i)
}
console.log('done')
```

### Sol 2: by advanced Function, reduce()
forEach 的 callback 之間沒有啥互相牽制的關係，但是 reduce 就不一樣了，reduce 的 callback 所 return 的變數，會成為下一個 callback 所拿到的參數。另外最後 reduce 的結果會 assign 出去。

```js
const sum = [1,3,5,2].reduce((prev,next)=>{
  console.log(prev, next);
  return prev+next;
})
// 1 3
// 4 5
// 9 2
console.log(sum); 
// 11
```

那麼既然可以累加並丟給下一位，我們是不是也能丟一個…Promise 讓下一個人去 await 呢？

很好，這個想法就對了！

```js
[1,3,5,2].reduce( async (_prev,next) => {
  const prev = await Promise.resolve(_prev);
  prev!=='DO_NOT_CALL' && await wait(prev);
  await wait(next);
  return Promise.resolve("DO_NOT_CALL");
});
```