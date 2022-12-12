keywords:  react_ui, golang-url-prefix

---
golangj 的 RESTful api，需要移除prefix。 避免請求的url帶有多餘url

---
case: 
切換react_ui資料夾後, package_lock.json已不一致。
需移除 node_modules and package_lock.json 檔案後， $npm i 再安裝一次

--- FAQ
### Q: Select all child elements 
```js
/* SELECT using PARENT.childNodes */
let allChildren = document.querySelector("#parentSelector").childNodes

/* PRINT */
for(let i=0; i < allChildren.length; i++) {
         console.log("Child #", i + 1, allChildren[i])
}
```

### Q: How to get all the elements by their class-name, after querySelectorAll()
#### Sol:
Failing that, you can look to querySelector and a substring matching attribute selector:

```js
document.querySelectorAll("[class^=page]")
```
… but that will only work if pageSomething is the first listed class name in the class attribute.

document.querySelectorAll("[class*=page]")
… but that will match class attributes which mention "page" and not just those with classes which start with "page" (i.e. it will match class="not-page".

That said, you could use the last approach and then loop over .classList to confirm if the element should match.

#### Example: 
```js
var x = document.querySelectorAll('[id^="entryField"]'),
    empty = 0;

for (var i = 0; i < x.length; ++i) {
    if (x[i].value == "") {
        ++empty;
    }
}
if (empty !== 0 && empty !== x.length) {
    alert("Please enter a value");
}
```

--- 
### DOM on Browser 心得
> Tree, Linked List 無所不在
* DOM, Document Of Model. 是術的結構存在。在Browser上，都是文件，也都是一個Node, 透過階層關係，描述 node 與 node 之間的關聯。
* 可以在 Web API 可窺見
  * querySelector(), querySelectorAll()
  * getElmentById(), getElementsByTagName(), etc...
* querySelectorAll() 返回的是一種稱為NodeList的資料結構，非單純的Array, 所以不適用Arrry.prototype方法
* NodeList 
  * NodeList.length
```js
// All the paragraphs in the document
const items = document.getElementsByTagName("p");
```

---
## current technology
how the problem to the solved
how to improve
how it can be done, some detail info
specific technical 
existing in lab, but not avable in the market
something patentable, 

**implementation** 
* pain points to be solved.
* defined by role, not robot.
* FTO

## UI spec
* 主畫面 (Pages)
  * layout (可參考MiR or 其他idea)
  * modules (leverage WebViz)
  * features (far_simple_ui)

=== long-term reqirement for final product ===
* RWD

1. Nav. to Navigation point and do alignment
2. If not v shape, switch to navigation to the charging point.

communicate with two robots

1. task-list status and sorting and changing.
Ansible 


1. training suit


https://mp.weixin.qq.com/s/K0ukiNcKwDKPD-hURhzvCA
    
M600C和M1000C作为平台型机器人，其顶部支持搭载其他设备，且具备快速手动更换电池能力。机器人和电池均具备CE认证，具有业内首创的主动控制踏板、4个急停按钮、360°激光雷达覆盖、低矮障碍物检测以及超载偏载检测等功能，安全性能大大提升。


在智能性上，支持多种导航方式（激光SLAM、视觉SLAM、视觉二维码等）的灵活选择，满足几乎所有工业场景的需求。同时，智能绕障、智能语音交互等功能极大的提升了人机交互能力。值得一提的是，机器人自身重量均小于100kg，载重最大分别可达700kg和1100kg，做到了能效的最大化。


​[7/30 9:45 PM] Ryan JB Chen
平台型产品设计及专用的组件接口，可支持多种上部定制模块控制，解锁更多应用场景，完美适配以电气/电子制造行业为代表的劳动密集型行业各种物流需求。
​[7/30 9:45 PM] Ryan JB Chen
M1000T标配360°对角激光，最大行驶速度可达1.5m/s
​[7/30 9:46 PM] Ryan JB Chen
据了解，极智嘉全线搬运机器人均配备“智能大脑”机器人管理器（Robot Manager），可在没有调度系统的情况下单独使用，Robot Manager具备极高的易用性和扩展能力，帮助实施人员在15分钟之内进行单机的快速部署，极大的降低了对实施人员的要求并缩短了部署时间，进而降低成本。

Restful API (IT guy)
OPCUA
(first MES and FLM)
3rd party interface, modbus
IO extension, PLC

IPR, should protected by IP


byobu run yaml file, and it show `62;c`, it lacks of tmuxp
$sudo apt install tmuxp


check it's working or not on network


Geek+:
1. 服務器wifi調度
2. 多機器人近場通訊
3. 智能調度
3.1 路徑優化
3.2 壅塞控制
3.3 避免碰撞
4. 智能揀選
4.1 貨架佈局動態調整
4.2 匹配最優貨架組合
5. 多機器人大規模調度(單倉over 1000台)
6. 優化揀貨效率(300-600pcs/hr), 三倍效率人工揀貨。
7. 快速部署。3-4週完成現場實施。1-3月全面實施
8. Multi-layer sorting/Floor-based sorting
