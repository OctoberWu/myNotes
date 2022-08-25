keywords: import, require, es6

---
### The difference between "require(x)" and "import(x)"
This simple diagram will help you understand the difference between require and import.

![](./common_es6.png)

Apart from that,

You can't selectively load only the pieces you need with require but with import, you can selectively load only the pieces you need, which can save memory.

Loading is synchronous(step by step) for require on the other hand import can be asynchronous(without waiting for previous import) so it can perform a little better than require.
