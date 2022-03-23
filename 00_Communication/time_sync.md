使用遠程通訊，須考量 time synchronization issue. 

情境： 在客戶端發送一個指令，如何確保指令的時效性，以及作到time sync.

可能需求：
1. 超時fail的command.
2. 須在時間內完成該指令，並返回結果。

換言之，即是訊息的時效性。 expiry check