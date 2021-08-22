#### pyenv installation
1. Pre-requisite
```console
sudo apt update
sudo apt-get install python-pip git make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev
```

2. pyenv installation
```console
sudo apt-getinstall curl git-core
curl -L https://raw.github.com/yyuu/pyenv-installer/master/bin/pyenv-installer | bash
Under ~/.bashrc
export PYENV_ROOT="${HOME}/.pyenv"
if [ -d "${PYENV_ROOT}" ]; then
export PATH="${PYENV_ROOT}/bin:${PATH}"
eval "$(pyenv init -)"
fi
$source ~/.zshrc
```

3. Pre-requisite
** Install Specific Version Python **
```console
pyenv install –list
pyenv install 3.6.8
```

