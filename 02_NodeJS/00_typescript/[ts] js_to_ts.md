keywords: js_to_ts

---
### conversion tricks:
* 遇到不明的type, 宣告為`any` 等同fallback 到原始javascript,不作任何型別檢查。

* yaml
```ts
let ret: any = yaml.load(<file_dir>);
let data:string : ret.toString();
```

* Object.entries(), keys(), values() 
> 先宣告一次型別，先再作一次賦值。即可通過型別檢查。
```ts
	Object.entries(obj_json.root.BehaviorTree.Sequence).forEach(([item_key, item_val]) => {
		if (item_key == "SetBlackboard") {
			console.log(item_key, item_val);
			if (Array.isArray(item_val)) {
				item_val.forEach(function (SetBlackboard_item, SetBlackboard_index) {
					SetBlackboard_list.push(SetBlackboard_item._attributes);
				});
			} else {
				let itemVal: any = item_val;
				SetBlackboard_list.push(itemVal._attributes);
			}
		}
	}
```

* Date 
```ts
let aTime = new Date();
let bTime = new Date();
let delta:number = Number(bTime) - Number(aTime);
```

### function argument callback 

Argument of type '() => void' is not assignable to parameter of type '() => {}'.
  Type 'void' is not assignable to type '{}'