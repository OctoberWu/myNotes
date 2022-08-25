keywords: git-work-flow

---
### Git flow:

1. init
```sh
$cd <directory>
$git init
```

2. create `.gitignore` file
```sh
$touch .gitignore
```

3. stage the changes 
```
$git add .
$git commit -m <commit_message>
```

4. push to the remote 
```sh
$ git remote add orgin git@github.com:YourUsername/new-notes-repo.git
$ git push --set-upstream origin master
```
