keywords: workspace-storage

---

### VS Code installation
* First, update the packages index and install the dependencies by typing:
```console
$sudo apt update
$sudo apt install software-properties-common apt-transport-https wget
```
* Next, import the Microsoft GPG key using the following wget command:
```console
$wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
```
And enable the Visual Studio Code repository by typing:
```console
$sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
```
Once the apt repository is enabled, install the latest version of Visual Studio Code with:
```console
$sudo apt update
$sudo apt install code
```

** ref **
[VS Code Installation](https://linuxize.com/post/how-to-install-visual-studio-code-on-ubuntu-18-04/)

---
### VS Code Workspace storage
> Directly remove the folder 
```text
directory: 
/home/sc/.config/Code/User/workspaceStorage/
```