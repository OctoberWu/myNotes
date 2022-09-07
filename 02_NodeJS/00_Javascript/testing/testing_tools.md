keywords: testing, test-cafe

---

### TestCafe

#### tutorial video:
* [Test Automation](https://testautomationu.applitools.com/testcafe-tutorial/chapter7.7.html)

#### tutorial repo:
* [moatazeldebsy/TestCafe-TAU ](https://github.com/moatazeldebsy/TestCafe-TAU)


#### Write some testing cases by `testcafe`  (https://github.com/DevExpress/testcafe)

### testcafe reflections:
1. use debug() 
```js
await t.debug()
```

2. To check the existence of the DOM element 
3. When the DOM element is overlapped, use `dispatchEvent()`
```js
const target = Selector(`#delete-flow-${randomName}`);
await t
	.click('#flow-back')
	.setNativeDialogHandler(() => true)
	.dispatchEvent(target, 'click')
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^ alternative event dispatchment
	.wait(1000)
	.expect(Selector(`#flowbar-${randomName}`).exists).notOk({ message: 'Flow still exist!' });
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DOM existence check
```

