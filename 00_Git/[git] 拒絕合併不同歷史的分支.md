### Git pull refusing to merge unrelated histories
今天在git pull時，發生fatal: refusing to merge unrelated histories，解決方式如下。

狀況是我在Github建立了一個新的repository及預設的README.md。然後在本地又init一個git專案並commit了一些東西，然後才upstream本地到遠端的同名分支(master)。

```sh
$ git branch --set-upstream-to=origin/master
//Branch 'master' set up to track remote branch 'master' from 'origin'
```

$ git status
On branch master
Your branch and 'origin/master' have diverged,
and have 1 and 1 different commits each, respectively.
  (use "git pull" to merge the remote branch into yours)

nothing to commit, working tree clean
然後在git pull時就出現錯誤訊息。

$ git pull
fatal: refusing to merge unrelated histories

原因是本地和遠端的commit歷程不一致，仍被視為是分開的不同專案，因此使用git pull origin master --allow-unrelated-histories指令來合併。

```sh
$ git pull origin master --allow-unrelated-histories
From https://github.com/matt/demo
 * branch            master     -> FETCH_HEAD
Merge made by the 'recursive' strategy.
 README.md | 2 ++
 1 file changed, 2 insertions(+)
 create mode 100644 README.md
```

合併後檢視log。

```sh
$ git log --all --graph --decorate --oneline
*   73096b7 (HEAD -> master, origin/master) Merge branch 'master' of https://gith.com/matt/crm
|\
| * 823456e Initial commit
* f2092c0 Start
```


Ref: 
1. https://matthung0807.blogspot.com/2020/04/git-pull-refusing-to-merge-unrelated.html
2. https://github.com/doggy8088/Learn-Git-in-30-days/issues/31