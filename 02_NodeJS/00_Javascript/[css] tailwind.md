keywords: tailwind, webpack

---
### npm vs npx
> npx 可以臨時性的安裝非全局性必要的套件，省下許多安裝及使用的流程與步驟、省下了磁碟空間，也避免了長期汙染
> 提供了更簡便的方式使用套件，可以執行 Github 的 gists 和 repositories
> 可以指定套件版本，解決了不同項目不同版本的問題
 
```sh
# npm 永久安裝，npx 安裝後即移除
# 使用 npx 安裝，安裝的套件在執行完後就會刪掉。

$npx webpack 
#^^^ 執行node_modules中的模組

$npx -D webpack-cli
$npx webpack-cli init
$npx webpack -w webpack.config.js
#            ^^ watch

$npm -D tailwind@latest autoprefixer post-cli@8.3.1
#                                    ^^^^^^^^^^^^^^ latest verversion is conflicted with NodeJS v.12

# generate tailwind.config.js
$npx tailwindcss init 

# generate postcss.config.js
$npx tailwind init -p .
#                  ^^ postcss
```

---
### CSS 規劃
```css
`float`: [DOM] child node > parent node
`text-align`: [DOM] parent node > child node 
```

* reflection: css 修飾子。施作目標，根據層級，可分為 parent node, children nodes, or itself node