### JQuery + Select2 

擴展原生的select with options，使其具備更多功能(features)
* multiple select
* Dropdown option groups
* Hierarchical options
* Disabling options


適用於太多的options時，用來分組分群，提供使用者更好的選項體驗。
同時，能夠加入關鍵字搜尋，來過濾選項

更多詳細使用資訊，參考以下連結
* ref: [Select2](https://select2.org/)

### tricks
1. Disable opening dropdown menu
```js
  $(selNode).on('select2:open', function (e) {
    $(selNode).select2('close');
  });
```

* 需要獲取選到option的值
```js
// === primitive way 1 ===
// 在select(2)中，data的格式以JSON格式表示，獲取陣列的值，可由以下獲得。
  // directive
  $('<selector>').val();
  // result
  ['value_1', 'value_2', ..., 'value_n']

// === select2 way 1 ===
  $('<selector>').on('change', function (e) {
    let selId = e.target.id;                        // 得到select widget的id
    // 'conn1'
    let selVal2 = $(`#${selId}`).find(':selected'); // 獲取完整資料，含optgroup的資料。
    // ['map_1, cell_1', 'map_1, cell_2', 'map_2, cell_3']

  });

// === select2 way 2 ===
  $(selNode).on('select2:select', function (e) {
    let data = e.params.data; // 得到當次選取的值
    // {id: 'a_temp_cell', text: 'a_temp_cell', selected: true} 
    e.params.data['disabled'] = true; // disable 選項
    $('<selector>').trigger('change');
  })


// [SELECT2] get selected text
// method 1 
var category = $('.category').find(':selected').text();

// method 2
var category = $('.category').select2("data");
console.log(category.map(x => x.text));

// [SELECT2] get selected value
// method 1
var category = $('.category').select2("val");

// method 2
var category = $('.category').val();

```