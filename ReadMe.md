Win32_SineWave������windows�����ϻ�һ�����Һ���
![image]=(https://github.com/PowerfulGun/Win32_SineWave/blob/master/SineWave.png)
����API������MoveToEx(hdc,xbeg,ybeg,lpPOINT)
���ã����û�����ʼ��
������
in	hdc--Long���豸�������
in	xbeg--Long����ʼ��x����
in	ybeg--Long����ʼ��y����
out	lpPOINT--ָ��POINT�ṹ���ָ�룬���������ϸ�������ʼ��

����API������LineTo(hdc,xEnd,yEnd)
���ã��ӻ�����ʼ�㻭һ��ֱ�ߵ�x��y��
������
in	hdc--�豸�������
in	xEnd--Ŀ��x����
in	yEnd--Ŀ��Y����

����API������PolyLine(hdc,lpPOINT,nCount)
���ã���lpPOINTָ���������ֱ�������������γ�����
������
in	hdc ------------ Long��Ҫ�����л�ͼ���豸����
in	lpPoint -------- ָ��POINT����
in	nCount --------- Long��lpPoint�����еĵ�������ӵ�һ���㵽�ڶ����㻭һ���ߣ��Դ�����
