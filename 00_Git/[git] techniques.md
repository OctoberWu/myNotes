keywords: git, git-work-flow, git-large-commit-objects

---
### Git Frequent Usage:

1. init
```sh
$cd <directory>
$git init
```
1-1. clone
```sh
$git clone <repo-url> [<designated directory>]
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

---
### multiple origins
* a project with multiple origins
```shell
# template
$ git remote add <project_alias> <project_address>
# practice 
$ git remote add github https://github.com/Company_Name/repository_name.git

# --- Push main to github ---
# template
$ git remote add <remote_repo> <local_repo>
# practice 
$ git push github master

# --- Push my-branch to github and set it to track github/my-branch ---
# template
$ git remote add <remote_repo> <local_branch>
# practice 
$ git push -u github my-branch

# --- Make some existing branch track github instead of origin ---
# practice 
$ git branch --set-upstream other-branch github/other-branch
```

--- 
### Large File Storage
* Install git lfs
```sh
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
sudo apt-get install git-lfs
git lfs pull
yarn install
```

* 搜尋所有git log中包含 <keywords>(ex."FAR-2000") 的文字。
```shell
git log --grep="FAR-2000"
```

---
### Remove Large Objects in git Commit History 
* exceeds GitHub file size 解決 
Issue:過去歷史commit的檔案太大，上傳失敗。

Error Message Print-out
```shell
remote: Resolving deltas: 100% (18126/18126), done.
remote: error: Trace: d43074b67058616a89febe1b59a18d4ed60d0695b5d5a6c8b8fd666b934f669b
remote: error: See http://git.io/iEPt8g for more information.
remote: error: File server/ros_bridge is 378.39 MB; this exceeds GitHub's file size limit of 100.00 MB
remote: error: GH001: Large files detected. You may want to try Git Large File Storage - https://git-lfs.github.com.
To https://github.com/OctoberWu/john_gui.git
 ! [remote rejected]   V1.0 -> V1.0 (pre-receive hook declined)
error: failed to push some refs to 'https://github.com/OctoberWu/john_gui.git'
```
Solution: 
```shell
$ git filter-branch --tree-filter 'rm -rf server/ros_bridge' HEAD
$ git push <remote_repo> <local_repo>
```


### 讓 git clone 只複製特定的分支資料
### Clone specific branch
* Option 1:
```sh 
$git clone --branch <branchname> <remote-repo-url>
# or
$git clone -b <branchname> <remote-repo-url>
```

* Option 2:
```sh 
$git clone --branch <branchname> --single-branch <remote-repo-url>
# or
$git clone -b <branchname> --single-branch <remote-repo-url>
```

* Example
```sh
$git clone --single-branch --branch dev https://shihchiang@bitbucket.org/farobot/far_amr_ws.git
```
