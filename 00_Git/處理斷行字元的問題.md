Note:

Windows: CRLF (Carriage Return[Enter] Line Feed)   [\r\n, 0x0D 0x0A]
Linux: LF [\n, 0x0A]

`^M`: ^ stands for Ctrl, Ctrl + M 

vim 用 `^M` 顯示 [\r, 0x0D]

```sh
# [全域]將LF自動轉成CRLF
git config --global core.autocrlf true

# [個別]
在 repo 根目錄下，建立 `.gitattributes`檔案
```

template 

```
# Set the default behavior, in case people don't have core.autocrlf set.
* text=auto

# Explicitly declare text files you want to always be normalized and converted
# to native line endings on checkout.
*.c text
*.h text

# Declare files that will always have CRLF line endings on checkout.
*.sln text eol=crlf

# Denote all files that are truly binary and should not be modified.
*.png binary
*.jpg binary
```