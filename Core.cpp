#include "Core.h"

// ����pos
void SetPos(COORD a) 
{
	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}
void SetPos(int i, int j)
{
	COORD a={i, j};
	SetPos(a);
}
// ���ع��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(out, &cursor_info);
}

// �ѵ�y�У�(x1, x2) ֮����������Ϊ ch
void drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1,y);
	for(int i = 0; i <= (x2-x1); i++)
		cout<<ch;
}
// ��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
void drawRow(COORD a, COORD b, char ch)
{
	if(a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else
	{
		SetPos(0, 25);
		cout<<"Error 01��������������겻���, �޷�����У�";
		system("pause");
	}
}

// �ѵ�x�У�[y1, y2] ֮����������Ϊ ch
void drawCol(int x, int y1, int y2, char ch)
{
	int y=y1;
	while(y!=y2+1) // �����Ҫÿ��ѭ����Ҫȷ��λ�õģ���ΪϵͳĬ���ǰ��д�ӡ��������Ҫ���д�ӡ
	{
		SetPos(x, y);
		cout<<ch;
		y++;
	}
}
// ��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
void drawCol(COORD a, COORD b, char ch)
{
	if(a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else
	{
		SetPos(0, 25);
		cout<<"Error 02��������ĺ����겻��ȣ��޷�����У�";
		system("pause");
	}
}

//���Ͻ����ꡢ���½����ꡢ��row����С���col�����
void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a={x1, y1};
	COORD b={x2, y2};
	drawFrame(a, b, row, col);
}
void drawFrame(COORD a, COORD  b, char row, char col)
{
	drawRow(a.Y, a.X+1, b.X-1, row);
	drawRow(b.Y, a.X+1, b.X-1, row);
	drawCol(a.X, a.Y+1, b.Y-1, col);
	drawCol(b.X, a.Y+1, b.Y-1, col);
}
void drawFrame(Frame frame, char row, char col)
{
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	drawFrame(a, b, row, col);
}

//��[a, b)֮�����һ���������
int random(int a, int b)
{
	int c= (rand() % (a-b))+ a;
	return c;
}
COORD random(COORD a, COORD b)
{
	int x=random(a.X, b.X);
	int y=random(a.Y, b.Y);
	COORD c={x, y};
	return c;
}
bool  judgeCoordInFrame(Frame frame, COORD spot)
{
	if(spot.X>=frame.position[0].X)
		if(spot.X<=frame.position[1].X)
			if(spot.Y>=frame.position[0].Y)
				if(spot.Y<=frame.position[1].Y)
					return true;
	return false;
}

void printCoord(COORD a)
{
	cout	<<"( "<<a.X<<" , "<<a.Y<<" )";
}
void printFrameCoord(Frame a)
{
	printCoord(a.position[0]);
	cout	<<" - ";
	printCoord(a.position[1]);
}
