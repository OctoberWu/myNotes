
### ROS version check
```sh
$rosversion -d
# or
$echo $ROS_DISTRO
```
---

### Ubuntu version check
```sh
$lsb_release -a
```

---

### Set hotkey to change languages
On Unbuntu 18.04LTS with GNOME desktop from **gnome-tweaks**
1. Installation
2. Select `Keyboard & Mouse` tab
3. Click `Additional Layout Options` button
4. Expand `Switching to another layout`
5. Select the intended combination(Ctrl+Shift)

``` sh
$sudo apt-get intall gnome-tweaks
$gnome-tweaks
```

---

### Check ttyUSB device
```sh
$ls /dev | grep ttyUSB
```

### Change authentication of folders
```sh
$sudo chmod -R 777 <folder_name>
```

---

### apt-search & add-apt-repository
* apt-cache: 命令可顯示 APT 內部資料庫裡的多種資訊。這些資訊是從 sources.list 檔案內聚集不同來源的快取。於執行 apt update 運作時產生的。
```sh
# To search for a particular package by name or description:
$apt-cache search <keyword>
```

* apt search
> Using **aptitude**, **apt-cache**, and **apt** all format the output differently. (None of these require the use of sudo when searching for a package.) I prefer using apt for its readability. It highlights the package name and puts a space between the different packages. It also has [installed] listed next to each package that is already installed. Usage:
```sh
$apt search <package-name>
```

* Add & Remove PPA(Personal Package Archives)
```sh
# 1. Add repo
$sudo add-apt-repository ppa:ppa:使用者名稱/PPA名稱
$sudo add-apt-repository ppa:nginx/stable

# 2. Update & Install repo
$sudo apt-get update
$sudo apt-get install nginx

# 3. Remove repo
## Remove all packages installed from ppa
$sudo apt-get --purge remove nginx
$sudo apt-get --purge autoremove
## Remove the package
$sudo add-apt-repository --remove ppa:nginx/stable
```

---

### What's snapd
> ***Background service that manages and maintains installed snaps***
Note: you do not need to install snapd manually if you already have snap installed.

> Snaps are app packages for desktop, cloud and IoT that update automatically, are easy to install, secure, cross-platform and dependency-free. They're being used on millions of Linux systems every day.

---

### wifi driver on Ubuntu
spec: Intel wifi6 AX201 160MHz

```sh 
$sudo apt-get upgrade
$sudo apt install linux-generic-hwe-18.04-edge
```
这将安装Ubuntu 19.10中使用的5.3内核。
linux-generic-hwe-18.04（不带Edge）提供5.3内核后，就可以替换元数据包。
明年某个时间linux-generic-hwe-18.04-Edge将拉出下一个内核，而linux-generic-hwe-18.04将拉出5.3。如果您不想切换到新的主要内核版本，则始终可以删除linux-generic-hwe-18.04-Edge并稍后安装linux-generic-hwe-18.04。


### Zsh 
* ZSH Installation:
```sh
sudo apt install zsh
sudo apt-get install powerline fonts-powerline
```

* Oh-My-Zsh Installation:
```sh
git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
```

* Set Zsh as the default Shell:
```sh
chsh -s /bin/zsh
Install additional plugins (syntax highlight, auto complete):
git clone https://github.com/zsh-users/zsh-autosuggestions.git ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
```

* Enable the plugins:
Open the file ~/.zshrc, locate the line that says: plugins=(git). And replace it as: plugins=(git zsh-autosuggestions zsh-syntax-highlighting)
If you want to change back to Bash:
```sh
chsh -s /bin/bash
```