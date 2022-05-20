keywords: Object.keys(), Object.values, Object.entries(), shallow-copy, deep-copy


--- 
### Quick Note:
將 JS 物件轉成其他資料結構，所以需要迭代物件中的所有 property，過去會用 for-in 陳述句，但只想列舉 own property，就必須用 hasOwnProperty() 才能解決。後來 ES5 新增的 Object.keys() 解決了非 own property 的問題，但還是要手動透過 property name 來存取 value，不方便！終於在 ES2017 (ES8) 新增了 Object.values() 和 Object.entries()，可以直接取得 property value 了！

* Object.keys():  將 JSON Object中的所有key值拿出，組成一個陣列。

* Object.values(): 將 JSON Object中的所有values值拿出，組成一個陣列。 

* Object.entries():  將 JSON Object中的所有<key>:<value> 的pair拿出，組成一個陣列。


### references:
* [JavaScript 之旅 (4)：Object.keys() & Object.values() & Object.entries()](https://ithelp.ithome.com.tw/articles/10239942)
* [JS 中的淺拷貝 (Shallow copy) 與深拷貝 (Deep copy) 原理與實作](https://www.programfarmer.com/articles/javaScript/javascript-shallow-copy-deep-copy)

---
### Convert JSON Object into a flat JSON array

* raw data 
```js
{
 "country": "Country A",
 "_id": "1"
 "regions": [
	 {
			"region": "region A1",
			"cities": [
				{
					"city": "city A11"
				},
				{
					"city": "city A12"
				}
			]
		},
		{
			"region": "region A2",
			"cities": [
				{
					"city": "city A21"
				},
				{
					"city": "city A22"
				}
			]
		}
	]
}
```

* processed data
```js
[
	{
		"country": "Country A",
		"region":"Region A1",
		"city": "City A11"
	},
	{
		"country": "Country A",
		"region":"Region A1",
		"city": "City A12"
	}
]
```

#### solution:
```js
const country = {
  "country": "Country A",
  "_id": "1",
  "regions": [
    {
      "region": "region A1",
      "cities": [
        {
          "city": "city A11"
        },
        {
          "city": "city A12"
        }
      ]
    },
    {
      "region": "region A2",
      "cities": [
        {
          "city": "city A21"
        },
        {
          "city": "city A22"
        }
      ]
    }
  ]
};

const flat = country.regions.flatMap(({region, cities}) =>
  cities.map(({city}) => ({country: country.country, region, city})
));

console.log(flat);
```

* output
```js
[
  {
    "country": "Country A",
    "region": "region A1",
    "city": "city A11"
  },
  {
    "country": "Country A",
    "region": "region A1",
    "city": "city A12"
  },
  {
    "country": "Country A",
    "region": "region A2",
    "city": "city A21"
  },
  {
    "country": "Country A",
    "region": "region A2",
    "city": "city A22"
  }
]
```

#### references:
* [Convert JSON object into a flat JSON Array](https://stackoverflow.com/questions/53713291/convert-json-object-into-a-flat-json-array)