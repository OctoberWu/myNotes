* 實機的位置及其碰撞預測及模擬。
* 接上時機/模擬環境訊號的模擬，由於以加上物理限制，所以只需物理引擎，作碰撞偵測及紀錄。
* 純模擬的app中，需要考量穿越的問題。

Architecture:
	* Coordinator < Router < Kinematics < actuators (PID Control)
	* collision prediction
	* negotiation
	* simulation