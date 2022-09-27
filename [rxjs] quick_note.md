keywords: rxjs

---
### quick note:
1. refCount(): 用來獲取訂閱數

2. @Injectable()
```ts
// globales.service.ts
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class GlobalesService {

  constructor() { }
}
```
> 在過去我們需要將 service 註冊到 NgModule 內的 providers 屬性才可使用，現在裝飾器 Injectable 增加了 providedIn 屬性，預設值為 root 表示該 service 會自動被註冊到根模組(AppModule)內，這應該算是單例模式的實作，讓整個專案共用同一個 service。

3. subject 與 observable 的差異點。subject 僅允許一個。 observable 允許多個。

4. subject 的種類
  * pure subject
  * behavior subject: 拿最後一個
  * async subject
  * replay subject: 拿最後的幾個

5. map 種類
  * switchMap()
	* concatMap()
	* mergeMap()