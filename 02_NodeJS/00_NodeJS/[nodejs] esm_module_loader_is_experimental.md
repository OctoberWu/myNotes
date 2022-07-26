keywords: ExperimentalWarning, The_ESM_module_loader_is_experimental

---
#### postcss
過新版本的postcss造成，載入錯誤。
出現 (node:1121148) ExperimentalWarning: The ESM module loader is experimental.

* rollback 到更早的版本即可。
* 測試到的版本紀錄: postcss ^10.4.7 > ^8.3.1