### How to append text to a file when using sudo command on Linux or Unix
```sh
sudo sh -c 'echo my_text >> file1'
sudo -- bash -c 'echo "some data" >> /my/path/to/filename.txt'

The -c option passed to the bash/sh to run command using sudo.
```