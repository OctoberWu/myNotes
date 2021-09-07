在vis-network中，繪製機器人的sprite在canvas時候。

調用afterDrawing() 事件函數，在裡面使用 new Image()致使，效能不佳。

在200ms貞的更新頻率下，來不及繪製，造成renderer失效，進入下一貞。故而畫面閃動。


###### tags: 'flickering'