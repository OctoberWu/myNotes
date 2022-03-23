### 測試sink ROS message sink到DB的方式
1. get all active tasks, updating 1% per second.
2. get 1 active tasks update state to `FAIL` per 60s
3. add 2 tasks

### 設計軟體架構時，須考量到系統架構的限制，使用情境。
* 根據使用情境 > 設計系統架構 > 分析系統架構的限制 > 設計系統架構 > 評估。
* 根據限制的usecase, 作保護(protection)。

### protections
* mocking programs
* boomerang test

### Table update

| Tables Relation  | Operation |
| ---------------- | --------- |
| TableA > TableB  | Delete    |
| TableA < TableB  | Create    |
| TableA == TableB | Update    |