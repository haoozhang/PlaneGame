#include <Windows.h>
#include <iostream>
using namespace std;

struct Frame
{
	COORD position[2];
	int flag;
};

// 设置光标
void SetPos(COORD a) ;
void SetPos(int i, int j);

// 隐藏光标
void HideCursor();

// 把第y行，(x1, x2) 之间的坐标填充为 ch
void drawRow(int y, int x1, int x2, char ch);
// 在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
void drawRow(COORD a, COORD b, char ch);

// 把第x列，[y1, y2] 之间的坐标填充为 ch
void drawCol(int x, int y1, int y2, char ch);
// 在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch
void drawCol(COORD a, COORD b, char ch);

//左上角坐标、右下角坐标、用row填充行、用col填充列
void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
void drawFrame(COORD a, COORD  b, char row, char col);
void drawFrame(Frame frame, char row, char col);

//在[a, b)之间产生一个随机整数
int random(int a, int b);
COORD random(COORD a, COORD b);

bool  judgeCoordInFrame(Frame frame, COORD spot);

void printCoord(COORD a);
void printFrameCoord(Frame a);
