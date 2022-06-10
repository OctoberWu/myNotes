keywords: list_conflicted_files

---
### quick note:
#### Use `git diff`
* `name-only`: to show only the names
* `diff-filter=U`: to include 'Unmerged' files
* `relative`: to show paths relative to current working directory

```sh
git diff --name-only --diff-filter=U --relative
```