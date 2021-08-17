### Git Sub-Module

#### to add submodule (new submodule)
$git add submodule

1. Update submodule
* Pulll all submodules by `foreach`
```sh
$git submodule foreach --recursive git pull origin master
```

2. Remove submodule

```sh
$git rm --cached /path/to/files
$rm -rf /path/to/files
```

3. Pull all submodules while doing `clone`
```sh
$git submodule init
$git submodule update --recursive
# or
$git submodule update --init --recursive
```

* Note
git submodule init：根據 .gitmodules 的名稱和 URL，將這些資訊註冊到 .git/config 內，可是把 .gitmodules 內不用的 submodule 移除，使用這個指令並沒辦法自動刪除 .git/config 的相關內容，必須手動刪除；
git submodule update：根據已註冊（也就是 .git/config ）的 submodule 進行更新，例如 clone 遺失的 submodule，也就是上一段講的方法，所以執行這個指令前最好加上 --init；
git submodule sync：如果 submodule 的 remote URL 有變動，可以在 .gitmodules 修正 URL，然後執行這個指令，便會將 submodule 的 remote URL 更正。

* While the repository is with submodules
```sh
$git clone --recursive
```
#### If the submodule is empty, fetch them by
```sh
$git submodule update --init
```

#### Update submodule
```sh
$cd <submodule>
$git pull
```


