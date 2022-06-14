keywords: element-contains-class, query-selector

---
### quick note:

```javascript
const div = document.querySelector('div');
div.classList.contains('error'); // false
```

### comparison:
> DOM type determines the interface
type | querySelector | jquery 
div | textContent | .text()
input | value | .val()

### methods:
#### method 1:
```javascript
document.getElementById('textbox_id').value // to get the value of desired box
// ex.
document.getElementById("searchTxt").value;
```

#### method 2:
```javascript
document.getElementsByClassName('class_name')[whole_number].value // returns a Live HTMLCollection
// ex.
document.getElementsByClassName("searchField")[0].value;
```

#### method 3:
```javascript
document.getElementsByTagName('tag_name')[whole_number].value // returns a live HTMLCollection
// ex.
document.getElementsByTagName("input")[0].value;
```

#### method 4:
```javascript
document.getElementsByName('name')[whole_number].value // which also >returns a live NodeList
// ex.
document.getElementsByName("searchTxt")[0].value;
```

#### method 5:
```javascript
document.querySelector('selector').value // which uses a CSS selector to select the element
// ex.
document.querySelector('#searchTxt').value;         // selected by id
document.querySelector('.searchField').value;       // selected by class
document.querySelector('input').value;              // selected by tagname
document.querySelector('[name="searchTxt"]').value; // selected by name
```

#### method 6:
```javascript
document.querySelectorAll('selector')[whole_number].value //which also uses a CSS selector to select elements, but it returns all elements with that selector as a static Nodelist.
// ex.
document.querySelectorAll('#searchTxt')[0].value;         //selected by id
document.querySelectorAll('.searchField')[0].value;       //selected by class
document.querySelectorAll('input')[0].value;              //selected by tagname
document.querySelectorAll('[name="searchTxt"]')[0].value; //selected by name
```

### references:
* [How do I get the value of text input field using JavaScript?](https://stackoverflow.com/questions/11563638/how-do-i-get-the-value-of-text-input-field-using-javascript)