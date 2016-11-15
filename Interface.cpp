#include "Interface.h"
void playingMenu()
{
	system("cls");
	drawFrame(0, 0, 48, 24, '=', '|');//	draw map frame;
	drawFrame(49, 0, 79, 4, '=', '|');//		draw output frame
	drawFrame(49, 4, 79, 16, '=', '|');//		draw score frame
	//drawFrame(49, 14, 79, 20, '=', '|');//	draw operate frame
	drawFrame(49, 16, 79, 24, '=', '|');//	draw other message frame
	
	SetPos(52,6);
	cout<<"	操作方式：";
	SetPos(52,8);
	cout<<"	w,a,s,d键： ";
	SetPos(52,10);
	cout<<"	控制飞机移动";
	SetPos(52,12);
	cout<<"	p键： 暂停游戏";
	SetPos(52,14);
	cout<<"	q键： 退出游戏";
	
	//SetPos(52,18);
	//cout<<"	Life:";
	SetPos(52, 20);
	cout<<"	Score：";
	SetPos(52, 22);
	cout<<"	Name：";
}
int startMenu()
{
	//SetPos(33, 3);
	//cout<<"Plane   Game";
	//drawRow(5, 0, 79, '=');
	//drawRow(7, 0, 79, '=');
	SetPos(28, 7);
	cout<<"P l a n e   G a m e";

	int j=13;
	SetPos(13, j);
	cout<<">>";
	SetPos(16, 13);
	cout<<"1. 低级模式";
	SetPos(16, 15);
	cout<<"2. 高级模式";
	
	SetPos(48, 13);
	cout<<"敌机移动速度较慢";

	drawRow(11, 11, 64, '=');
	//SetPos(51, 13);
	//cout<<"敌人移动速度较慢";
	//drawRow(22, 0, 79, '=');
	//drawRow(24, 0, 79, '=');
	//SetPos(50, 23);
	//cout<<"@版权所有，盗版必究";
	SetPos(55,21);
	cout<<"W 和 S 上下选择，L 确定";
	string str2 = "Designer: NJUCS Silence";
	for(int i = 0; i < str2.length(); i++)
	{
		SetPos(i+55, 23);
		cout<<str2[i];
		Sleep(100);
	}

	//drawFrame(45, 9, 79, 17, '=', '|');

	while(1)
	{	if( _kbhit() )
		{	
			char x=_getch();
			switch (x)
			{
			case 'w' :
					{	
						if( j == 15)
						{
							SetPos(13, j);
							cout<<"　";
							SetPos(48, j);
							cout<<"                         ";
							j = 13;
							SetPos(13, j);
							cout<<">>";
							//SetPos(51, 13);
							//cout<<"　　　　　　　　　　　　";
							SetPos(48, 13);
							cout<<"敌机移动速度较慢";
							//SetPos(51, 13);
							//cout<<"简单敌人有着较慢的移动速度。";
						}
						break;
					}
			case 's' :
					{	
						if( j == 13 )
						{
							SetPos(13, j);
							cout<<"　";
							SetPos(48, j);
							cout<<"                         ";

							j = 15;
							SetPos(13, j);
							cout<<">>";
							//SetPos(51, 13);
							//cout<<"　　　　　　　　　　　　　　";
							SetPos(48, 15);
							cout<<"敌机移动速度较快";
							//SetPos(51, 13);
							//cout<<"冷酷的敌人移动速度较快。";
						}
						break;
					}
			case 'l' :
					{	
						return j;
					}
			}
		}
	}
}
void welcomeMenu()
{
	system("cls");
	HideCursor();
	string str1 = "Welcome to Plane Game";
	for(int i = 0; i < str1.length(); i++)
	{
		SetPos(i+28, 12);
		cout<<str1[i];
		Sleep(100);
	}
	Sleep(1000);
	/*
	string str2 = "Designer: NJUCS Silence";
	for(int i = 0; i < str2.length(); i++)
	{
		SetPos(i+40, 12);
		cout<<str2[i];
		Sleep(100);
	}*/
	SetPos(56,24);
	cout<<"点击L键进入游戏......";
	while(1)
	{
		char x = _getch(); 
		if(x == 'l')
			break;
	}
	 
	
	/*SetPos(28,10);
	cout<<"Welcome to Plane Game";
	Sleep(2000);
	SetPos(26, 20);
	cout<<"Designed by NJUCS Silence";*/

	//setPos();

}

