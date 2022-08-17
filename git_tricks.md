### keywords: git

---
#### quick note:

* 搜尋所有git log中包含 <keywords>(ex."FAR-2000") 的文字。
```shell
git log --grep="FAR-2000"
```
---
* a project has multiple origins
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