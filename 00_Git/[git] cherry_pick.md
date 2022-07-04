keywords: cherry-pick

--- 
### quick note: 
* use cherry-pick to pick the certain changes from the existing commit.
```sh
git cherry-pick <commit_id> | <tag_name>  
```

* Since cherry-pick will keep the commit author and date by the picked commit, so if trying to <b>update the commit time</b>, then could be conducted by the following command:
```sh
// --- the commit time will be updated to NOW ---
git commit --amend --reset-author
```
