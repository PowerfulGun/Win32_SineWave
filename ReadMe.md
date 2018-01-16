Win32_SineWave程序：在windows窗体上画一个正弦函数
![image]=(https://github.com/PowerfulGun/Win32_SineWave/blob/master/SineWave.png)
核心API函数：MoveToEx(hdc,xbeg,ybeg,lpPOINT)
作用：设置绘制起始点
参数：
in	hdc--Long，设备环境句柄
in	xbeg--Long，起始点x坐标
in	ybeg--Long，起始点y坐标
out	lpPOINT--指向POINT结构体的指针，用来返回上个绘制起始点

核心API函数：LineTo(hdc,xEnd,yEnd)
作用：从绘制起始点画一条直线到x、y处
参数：
in	hdc--设备环境句柄
in	xEnd--目标x坐标
in	yEnd--目标Y坐标

核心API函数：PolyLine(hdc,lpPOINT,nCount)
作用：将lpPOINT指向的坐标用直线连接起来，形成折线
参数：
in	hdc ------------ Long，要在其中绘图的设备场景
in	lpPoint -------- 指向POINT数组
in	nCount --------- Long，lpPoint数组中的点数。会从第一个点到第二个点画一条线，以次类推
