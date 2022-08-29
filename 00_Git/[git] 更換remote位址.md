Git 更換遠端伺服器倉庫網址URL

1.確認目前Git遠端伺服器網址： git remote -v

git remote -v
origin  https://github.com/USERNAME/REPOSITORY.git (fetch)
origin  https://github.com/USERNAME/REPOSITORY.git (push)
2.更換Git遠端伺服器位網址，使用：git remote set-url

git remote set-url origin https://github.com/USERNAME/OTHERREPOSITORY.git
3.再次確認Git遠端伺服器網址

git remote -v
origin  https://github.com/USERNAME/OTHERREPOSITORY.git (fetch)
origin  https://github.com/USERNAME/OTHERREPOSITORY.git (push)
如果是使用SSH的存取網址，指令一樣是使用git remote set-url，再接上新的SSH URL就可以更換，指令如下：

git remote set-url origin git@github.com:USERNAME/OTHERREPOSITORY.git
不管是要HTTP/HTTPS跟SSH，二種存取網址都是可以直接做更換，然後下次git push/ git fetch 就會到新設定的網址去了唷。