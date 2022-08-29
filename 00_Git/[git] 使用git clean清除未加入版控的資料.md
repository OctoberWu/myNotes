## git clean命令用來從你的工作目錄中刪除所有沒有tracked過的檔案

git clean經常和git reset –hard一起結合使用. 記住reset隻影響被track過的檔案, 所以需要clean來刪除沒有track過的檔案. 結合使用這兩個命令能讓你的工作目錄完全回到一個指定的<commit>的狀態

### 用法: 

```sh
# 是一次clean的演習, 告訴你哪些檔案會被刪除. 記住他不會真正的刪除檔案, 只是一個提醒
git clean -n

# 刪除當前目錄下所有沒有track過的檔案. 他不會刪除.gitignore檔案裡面指定的資料夾和檔案, 不管這些檔案有沒有被track過
git clean -f

# 刪除指定路徑下的沒有被track過的檔案
git clean -f <path>

# 刪除當前目錄下沒有被track過的檔案和資料夾
git clean -df

# 刪除當前目錄下所有沒有track過的檔案. 不管他是否是.gitignore檔案裡面指定的資料夾和檔案
git clean -xf
```

### 討論:

git reset –hard和git clean -f是一對好基友. 結合使用他們能讓你的工作目錄完全回退到最近一次commit的時候

git clean對於剛編譯過的專案也非常有用. 如, 他能輕易刪除掉編譯後生成的.o和.exe等檔案. 這個在打包要釋出一個release的時候非常有用

### 例子:

下面的例子要刪除所有工作目錄下面的修改, 包括新新增的檔案. 假設你已經提交了一些快照了, 而且做了一些新的開發

```sh
git reset --hard
git clean -df
```

執行後, 工作目錄和快取區回到最近一次commit時候一摸一樣的狀態，git status會告訴你這是一個乾淨的工作目錄, 又是一個新的開始了！

ref: 
1. https://dotblogs.com.tw/larrynung/2012/12/20/85834
2. https://www.osarea.com/git-clean-usage
