#include	<Windows.h>	
#include	<math.h>

#define	NUM	1000	//point�������
#define	��	(3.14159)	//Բ���ʦ�ֵ

LRESULT	CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);	//�������ڹ���

int	WINAPI	WinMain(	//�������
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

	hwnd = CreateWindow(	//��������
		szClassName, TEXT("Sine Wave Using Polyline"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);

	UpdateWindow(hwnd);

	while (GetMessage(&msg,NULL,0,0))	//���ܴ�����Ϣѭ��
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return	msg.wParam;
}

LRESULT	CALLBACK	WndProc(	//���ڹ��̶���
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
	case WM_SIZE:	//���ڴ�С�仯��Ϣ
		cxClient = LOWORD(lParam);	//��¼�ͻ���ˮƽ��С
		cyClient = HIWORD(lParam);	//��¼�ͻ�����ֱ��С
		return	0;

	case WM_PAINT:	//���ڿͻ���������Ϣ
		hdc = BeginPaint(hwnd, &ps);
		//���ڴ�ֱһ�봦��һ��ˮƽֱ��
		MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, cxClient, cyClient / 2);
		//��������y=sin��x�� ����NUM��point����
		for (int i = 0; i < NUM; i++)
		{
			Point[i].x = i*cxClient / NUM;
			Point[i].y = (int)(cyClient / 2 * (1 - sin(2 * ��*i / NUM)));	//���ԣ�cyclient/2��Ϊ��������Сֵ�ǿͻ����߽�
		}
		Polyline(hdc, Point, NUM);	//��NUM��point�����߻��������NUM��������ȥ��������
		EndPaint(hwnd, &ps);
		return	0;

	case WM_DESTROY:	//����������Ϣ
		PostQuitMessage(0);
		return	0;
	}
	return	DefWindowProc(hwnd, message, wParam, lParam);	//���ര����Ϣ����ϵͳ�����Զ�����
}