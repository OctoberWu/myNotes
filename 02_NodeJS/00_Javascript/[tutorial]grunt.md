keywords: grunt

---
### Grunt：任务自动管理工具 (Quick Start)
1. Installation
```sh
sudo npm install grunt-cli -g

# template
npm install grunt --save-dev
npm install grunt-contrib-jshint --save-dev
npm install grunt-contrib-concat --save-dev
npm install grunt-contrib-uglify --save-dev
npm install grunt-contrib-watch --save-dev
```

2. 命令脚本文件Gruntfile.js
> SCRIPT template
```js
module.exports = function(grunt) {

  // 配置Grunt各种模块的参数
  grunt.initConfig({
    jshint: { /* jshint的参数 */ },
    concat: { /* concat的参数 */ },
    uglify: { /* uglify的参数 */ },
    watch:  { /* watch的参数 */ }
  });

  // 从node_modules目录加载模块文件
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-watch');

  // 每行registerTask定义一个任务
  grunt.registerTask('default', ['jshint', 'concat', 'uglify']);
  grunt.registerTask('check', ['jshint']);

};
```

### references:
  * [Grunt：任务自动管理工具](https://javascript.ruanyifeng.com/tool/grunt.html)