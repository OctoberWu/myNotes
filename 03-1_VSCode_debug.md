
#### Change Background Color
0. change leader key(,)
1. change background color(blue)

---

#### Vim plugins (easymotion,etc.)

*TBD*
+ how to add easymotion plugin
+ easymotion (leader key, hotkeys)

---

#### c_cpp_properties.json
```json
{
  "configurations": [
  {
    "name": "Linux",
    "includePath": [
      "${workspaceFolder}/**",
      "/opt/ros/foxy/include"
    ],
    "defines": [],
    "compilerPath": "/usr/bin/gcc",
    "cStandard": "c11",
    "cppStandard": "c++17",
    "intelliSenseMode": "clang-x64",
    "compileCommands": "${workspaceFolder}/build/compile_commands.json",
    "compilerArgs": [],
    "browse": {
      "path": [
        "${workspaceFolder}/**"
      ],
    "limitSymbolsToIncludedHeaders": true
    }
  }
],
  "version": 4
}
```
* Note: 其中/opt/ros/foxy/include爲ROS相關標頭檔案所在的路徑，此時可能仍然找不到ros/ros.h和std_msgs/String.h，繼續執行以下命令即可在build資料夾下生成compile_commands.json檔案
> catkin_make -DCMAKE_EXPORT_COMPILE_COMMANDS=1
然後就可以找到ros/ros.h和std_msgs/String.h了


#### launch.json
```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) Launch",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/*",
      "args": [],
      "stopAtEntry": true,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ]
    },
  ]
}
```

#### task.json
```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "source",
			"type": "shell",
			"command": "source /opt/ros/melodic/setup.bash;"
		},
		{
			"label": "catkin_make",
			"type": "shell",
			"command": "echo $PATH; source /opt/ros/melodic/setup.bash; echo $PATH;whereis catkin_make; catkin_make",
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"dependsOrder": "sequence",
			"dependsOn": [
				"source"
			],
			"problemMatcher": []
		}
	]
}
```

#### .devcontainer
```Dockerfile
# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.134.0/containers/cpp/.devcontainer/base.Dockerfile
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && apt-get -y install vim
```
```json
{
	"name": "C++",
	"build": {
		"dockerfile": "../Dockerfile",
		// Update 'VARIANT' to pick an Debian OS version: buster, stretch
		"args": { "VARIANT": "buster" }
	},
	"runArgs": [ "--cap-add=SYS_PTRACE", "--security-opt", "seccomp=unconfined"],

	// Set *default* container specific settings.json values on container create.
	"settings": { 
		"terminal.integrated.shell.linux": "/bin/bash"
	},

	// Add the IDs of extensions you want installed when the container is created.
	"extensions": [
		"ms-vscode.cpptools"
	],

	// Use 'forwardPorts' to make a list of ports inside the container available locally.
	// "forwardPorts": [],

	// Use 'postCreateCommand' to run commands after the container is created.
	// "postCreateCommand": "gcc -v",

	// Comment out this line to run as root instead.
	"remoteUser": "vscode"

}

```


