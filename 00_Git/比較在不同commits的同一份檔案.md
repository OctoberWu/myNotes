### How to diff the same file between two different commits on the same branch ?

From the git-diff manpage:
git diff [--options] <commit> <commit> [--] [<path>...]
For instance, to see the difference for a file "main.c" between now and two commits back, here are three equivalent commands:

```sh
git diff HEAD^^ HEAD main.c
git diff HEAD^^..HEAD -- main.c
git diff HEAD~2 HEAD -- main.c
```


### How to diff 2 files on the same branch, the same commit