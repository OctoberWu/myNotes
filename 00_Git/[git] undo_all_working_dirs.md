keywords: undo all working dir changes including new files

---
### remove all directories and file while `git reset --hard`
```shell
# reset, but it doesn't delete new untracked files created since last commit 
git checkout -f

# removes staged and working directory changes
git reset --hard

# remove untracked (better opposite of adding a new untracked file)
git clean -f -d  

# CAUTION: as above but removes ignored files like config.
git clean -f -x -d 

# CAUTION: as above, but cleans untracked and ignored files through the entire repo (without :/, the operation affects only the current directory)
git clean -fxd :/ 
```

To see what will be deleted before-hand, without actually deleting it, use `-n` flag(test-run)
```shell
git clean -nfd
```
When we are sure what should be deleted, remove `-n` flag

`git clean -fxd` can actually be REALLY dangerous if you don't know what you're doing. You may end up permanently deleting some very important untracked files, such as your database, etc. Use caution.

#### another perspective
```shell
# Revert modified files
git checkout -f

# Remove untracked files 
git clean -fd
```