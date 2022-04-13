### Hotkeys
The code formatting is available in Visual Studio Code through the following 
shortcuts:

On Windows : Shift + Alt + F
On Mac : Shift + Option + F
On Linux : Ctrl + Shift + I

### VSCode Configuration

```json
{
    // Controls if the editor should automatically format the line after typing
    "beautify.onSave": true,

    "editor.formatOnSave": true,

    // You can auto format any files based on the file extensions type.
    "beautify.JSfiles": [
        "js",
        "json",
        "jsbeautifyrc",
        "jshintrc",
        "ts"
    ]
}

```