#include	<Windows.h>	
#include	<math.h>

#define	NUM	1000	//point点的数量
#define	π	(3.14159)	//圆周率π值

LRESULT	CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);	//声明窗口过程

int	WINAPI	WinMain(	//代码入口
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	PSTR	szCmdLine,
	int	iCmdShow
)
{
	static TCHAR	szClassName[] = TEXT("powerfulgun");
	HWND	hwnd;
	MSG	msg;
	WNDCLASS	wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClassName;

	RegisterClass(&wndclass);

	hwnd = CreateWindow(	//建立窗口
		szClassName, TEXT("Sine Wave Using Polyline"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);

	UpdateWindow(hwnd);

	while (GetMessage(&msg,NULL,0,0))	//接受窗口消息循环
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return	msg.wParam;
}

LRESULT	CALLBACK	WndProc(	//窗口过程定义
	HWND	hwnd,
	UINT	message,
	WPARAM	wParam,
	LPARAM	lParam
)
{
	static int	cxClient, cyClient;
	HDC	hdc;
	PAINTSTRUCT	ps;
	POINT	Point[NUM];

	switch (message)
	{
	case WM_SIZE:	//窗口大小变化消息
		cxClient = LOWORD(lParam);	//记录客户区水平大小
		cyClient = HIWORD(lParam);	//记录客户区垂直大小
		return	0;

	case WM_PAINT:	//窗口客户区绘制消息
		hdc = BeginPaint(hwnd, &ps);
		//先在垂直一半处画一条水平直线
		MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, cxClient, cyClient / 2);
		//按照正弦y=sin（x） 设置NUM个point坐标
		for (int i = 0; i < NUM; i++)
		{
			Point[i].x = i*cxClient / NUM;
			Point[i].y = (int)(cyClient / 2 * (1 - sin(2 * π*i / NUM)));	//乘以（cyclient/2）为了最大和最小值是客户区边界
		}
		Polyline(hdc, Point, NUM);	//将NUM个point用折线画出，如果NUM够多则看上去就是曲线
		EndPaint(hwnd, &ps);
		return	0;

	case WM_DESTROY:	//窗口销毁消息
		PostQuitMessage(0);
		return	0;
	}
	return	DefWindowProc(hwnd, message, wParam, lParam);	//其余窗口消息交由系统函数自动处理
}