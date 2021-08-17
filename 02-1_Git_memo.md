### How to checkout remote git branch/origin
1. how to know the branch is set up-stream or not?
2. how to check the upstream remote address?


### How to start git in a new folder
1. init
```
$cd <directory>
$git init
```
2. create `.gitignore` file
3. create commit
```
$git add .
$git commit -m <commit_message>
```

```sh
$ git remote add orgin git@github.com:YourUsername/new-notes-repo.git
$ git push --set-upstream origin master
```


### Recover a branch after its deletion in git
```sh
$git reflog [--no-abbrev]
$git branch -b <branch> <sha>
```

### How to add submodule into an existing workspace (Add submodule)
1. create a space on `Bitbucket`
2. add submodule link into `.gitmodule`
```sh
$git submodule add <Bitbucket url> <folder directory>
#ex
$git submodule add https://bitbucket.org/farobot/far_traffic_editor/ ./src/far_traffic_editor/
```
Also, modify the `.gitmodules` file is ok

#### work-flow
1. create a repo
2. add the repo to submodule




### Plan to develop
1. create a fake **WMS trigger** signal, sending the coord.(x, y, yaw) to FLM.
 - send coord. in string type 
2. FLM receive the position request, fill in the task template.
3. After the task is fulfilled, send this to AMR.
4. AMR runs. 

1. UI <> WMS <> FLM <> AMR <> FLM <> WMS



### VSCode plugins 
- devcontainer(remote-container)
- c_cpp pulgin

### Configuration folder (dot folder)
- .devcontainer
  * devcontainer.json
  * Dockerfile(default)

- .vscode

| config. files         | Roles         |
| --------------------- | ------------- |
| settings.json         | vscode system |
| c_cpp_properties.json | c_cpp         |
| launch.json           | ROS           |
| tasks.json            | scripts       |


### map server
nav2 map server
https://github.com/ros-planning/navigation2/tree/main/nav2_map_server

ref:
https://github.com/ros-planning/navigation2/issues/864


### TODOs: 
 [] mobile device, phone.  
 [] RWD
 [] lab UI view

### nlohmann_json
What:
 - C/C++ read json files
 
```cmake
    find_package(nlohmann_json CONFIG REQUIRED)
    target_link_libraries(main PRIVATE nlohmann_json nlohmann_json::nlohmann_json)

# This works
set(CMAKE_PREFIX_PATH "/home/ros/vcpkg/packages/nlohmann-json_x64-linux/share/nlohmann_json;${CMAKE_PREFIX_PATH}"
```

### [VSCode][hidden folders]
VSCode > Settings > "file exclude"


### git list conflict files
- When
  - To merge project on git

```sh
$git diff --name-only --diff-filter=U
```

### Sub-Module

#### Add submodule (new submodule)
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

4. Add existing folder into submodule
```
$git submodule add <dir_to_folder>
```
Then can see in `.git/modules` folder



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



### git merge workflow
// fetch remote branches
$git fetch 
$git checkout <to_be_merged_branch>
$git pull
$git checkout <master>
$git merge <to_be_merged_branch>

$git add .
$git commit -m "<comments>"
$git push

Q: checkout 會清空 working area and/or staging area

- unstage files from the index
$git reset HEAD -- /path/to/file

$git checkout -b <new_branch>

$git push -u origin johnny_dev //將目前推到remote分支

$git checkout <existing_branch>

// 還原檔案內容
$git checkout -- <file_name>

// 還原檔案狀態
$git reset HEAD -- <file_name>


// 刪除 1 個commit
$git reset --hard HEAD^
$git reset --hard HEAD~1

$git push --force

// 顯示所有遠端分支
$git ls-remote
$git checkout remote <branch_name>

// 獲取遠端的分支
$git fetch

### Frequently use
$git checkout -b dev origin/dev

$git branch -m <new_branch_name> // modify local branch name

$git push origin --delete <existing_branch>
// delete <existing_branch> on remote branch

$git clone -b <remote_branch_name> <url>
// clone remote branch to local

// list remote branches
$git branch -r 


$git checkout -t origin/<branch_name>



### Quick Note:
- indicator-cpufreq

- yaml file needs to add namespace first
```yaml
namespace:
  param1: value1
  param2: value2
    sub_param1: value3


fb_0:
  ...
```


### Git submodules pratice
#### Usefule commands
- Clone repository with submodules automatically:
```sh
$git clone --recursive git@github.com:name/repo.git
```
- Initialize submodules after regular cloning:
```sh
$git submodule update --init
```




### 認證儲存機制
ssh : 設定金鑰認證
http :

```sh
$git config --global credential.helper store
```
Refs:

1. [如何透過 Git Credential 管理透過 HTTP 通訊協定存取儲存庫的帳號密碼](https://blog.miniasp.com/post/2018/05/28/Git-Credential-Howto)

2. [git-credential-store](https://git-scm.com/docs/git-credential-store)

### Create a new branch
$ git checkout -b  <new_branch>

### Create a new branch from remote to local
$ git checkout -b <new_local_branch> origin/<branch>



### push pull
detach and create new branch 
create a new branch 

```sh
$git checkout master
$git reset --hard HEAD
```

### Push code to Bitbucket
```sh
$git add -all
$git commit -m '<commit_message>'
$git push
```

---

### To add new repository to BitBucket
1. Create a repository on Bitbuck
2. copy the `git clone` link.
3. Go to local `repos` by terminal
4. paste(Ctrl+Shift+V) the link to copy/download the project to local
5. copy all the intended files in the folder.
6. git commands as follows
``` sh
($git add -all)
$git commit -am "Initial commit"
$git pull origin master (in case of that origin version is newer than master)
$git push origin master
```

ref [BitBucket tutorial](https://www.atlassian.com/git/tutorials/learn-git-with-bitbucket-cloud#copy-and-add-files) 

### To manage repositories by project
1. Go to projects
2. add existing repositories

### git submodule
```sh
$submodule update
```

