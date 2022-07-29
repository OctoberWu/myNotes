keywords: capitalized words

---
### capticalized the very first word in a string
```javascript
$(document).find('.card-title > span').each(function () {
	// --- font-text, font-family spec. ---
	let title = $(this).text().trim().toLowerCase();
	// $(this).text(title[0].toUpperCase() + title.slice(1));
	title = title.replace(/\b\w/g, l => l.toUpperCase())
	$(this).text(title)
	$(this).css("font-family", "Arial");
});
```

### capticalized words in a string
```javascript
$(document).find('.card-title > span').each(function () {
	// --- font-text, font-family spec. ---
	let title = $(this).text().trim().toLowerCase();
	// $(this).text(title[0].toUpperCase() + title.slice(1));
	title = title.replace(/\b\w/g, l => l.toUpperCase())
	$(this).text(title)
	$(this).css("font-family", "Arial");
});
```
