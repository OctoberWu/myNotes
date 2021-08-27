出現artifact 無法啟動的狀況。
從啟動後，仍然出現'multi-cast socket'的錯誤

將far_artifact_ws的路徑下的
install/far_rmt_agent
build/far_rmt_agent
資料夾刪除後，重新build即可。

根本原因是，library更新，要重新連結。