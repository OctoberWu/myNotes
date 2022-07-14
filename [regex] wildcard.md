keywords: regex, wildcard

--- 
regex debugger:
與JSON非常類似，在解析資料時，作分流或串流的pipeline.
根據特殊符號的規則，建構出解析文字的功能。
網路上，有些網站,提供可視化，協助建構出特定規則的解析。連結如下：
[Debuggerex](https://www.debuggex.com/)

嘗試過使用其來限制，輸入值在某個區間，但效果不佳。
故改採偵測string 是否含有某個不想包含的字元，進一步再作解析。
另外，更深一層來說。可以使用lexer相關的套件來作更細緻的驗證。
如nodejs中的ohm [ohm.js](https://ohmjs.org/)