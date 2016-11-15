#include "Game.h"


Plane::Plane()
{
	//        
	//        4
	//        0
	//     1 2 3 
	COORD centren={39, 22};  // 0的坐标
	position[0].X=position[2].X=position[4].X = centren.X;
	position[1].X=centren.X-1;	
	//position[].X=position[6].X=centren.X-1;
	position[3].X=centren.X+1;
	//position[4].X=centren.X+2;
	position[0].Y = centren.Y;
	for(int i=1; i<=3; i++)
		position[i].Y=centren.Y + 1;
	//for(int i=6; i<=8; i++)
	//	position[i].Y=centren.Y+1;
	position[4].Y=centren.Y-1;
	//position[9].Y=centren.Y-2;
}
void Plane::drawPlane()
{
	for(int i=0; i<5; i++)
	{
		SetPos(position[i]);
		if(i!=4)
			cout<<"W";
		else
			cout<<"A";		
	}
}
void Plane::drawPlaneToNull()
{
	for(int i=0; i<5; i++)
	{
		SetPos(position[i]);
		cout<<" ";
	}	
}
void Plane::planeMove(char x)
{
	switch(x)
	{
	case 'w':
		if(position[4].Y != 3)
			for(int i=0; i<=4; i++)
				position[i].Y -= 1;
		break;
	case 'a':
		if(position[1].X != 1)
			for(int i=0; i<=4; i++)
				position[i].X -= 1;
		break;
	case 's':
		if(position[3].Y != 23)
			for(int i=0; i<=4; i++)
				position[i].Y += 1;
		break;
	case 'd':
		if(position[3].X != 47)
			for(int i=0; i<=4; i++)
				position[i].X += 1;
		break;
	default:
		break;
	}
}
COORD Plane::getPosition(int index)
{
	return position[index];
}

Bullet::Bullet()
{
	for(int i=0; i<10; i++)
		bullet[i].Y = 30;
	timeOfBullet = 0;
}
void Bullet::drawBullet()
{
	for(int i=0; i<10; i++)
	{
		if( bullet[i].Y != 30)
		{
			SetPos(bullet[i]);
			cout<<"*";	
		}
	}
}
void Bullet::drawBulletToNull()
{
		for(int i=0; i<10; i++)
			if( bullet[i].Y != 30 )
				{
					COORD pos={bullet[i].X, bullet[i].Y};
					SetPos(pos);
					cout<<" ";
				}	
}
void Bullet::drawOneBulletToNull( COORD c)
{
	SetPos(c);
	cout<<" ";
}
void Bullet::bulletMove()
{
	for(int i=0; i<10; i++)
	{
		if( bullet[i].Y != 30)
		{
			bullet[i].Y -= 1;
			if( bullet[i].Y == 1 )
			{
				COORD pos={bullet[i].X, bullet[i].Y+1};
				drawOneBulletToNull(pos);
				bullet[i].Y=30;
			}	
		}
	}
}

Enemy::Enemy()
{
	COORD a={1, 1};
	COORD b={45, 15};
	for(int i=0; i<8; i++)
	{
		enemy[i].position[0] = random(a, b);
		enemy[i].position[1].X = enemy[i].position[0].X + 2;
		enemy[i].position[1].Y = enemy[i].position[0].Y + 1;
	}

	timeOfEnemy = 0;
}
void Enemy::drawEnemy()
{
	for(int i=0; i<8; i++)
		drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');
}
void Enemy::drawEnemyToNull()
{
	for(int i=0; i<8; i++)
		drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');
}
void Enemy::drawOneEnemyToNull(Frame f)
{
	drawFrame(f,' ',' ');
}
void Enemy::enemyMove()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<2; j++)
			enemy[i].position[j].Y++;

		if(24 == enemy[i].position[1].Y)
		{
			COORD a={1, 1};
			COORD b={45, 3};
			enemy[i].position[0] = random(a, b);
			enemy[i].position[1].X = enemy[i].position[0].X + 2;
			enemy[i].position[1].Y = enemy[i].position[0].Y + 1;
		}
	}
}

ConsoleGame::ConsoleGame()
{
	levelOfGame = firstSpeed;
	score = 0;
	name = "";
}
void ConsoleGame::setLevelOfGame(int l)
{
	levelOfGame = l;
}
void ConsoleGame::shoot(Bullet &b, Plane &p)
{
	for(int i=0; i<10; i++)
		if(b.bullet[i].Y == 30)
		{
			b.bullet[i].X = p.position[4].X;
			b.bullet[i].Y = p.position[4].Y-1;
			break;
		}
}
void ConsoleGame::checkEnemy(Bullet &b, Enemy &e)
{
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 10; j++)
			if( judgeCoordInFrame(e.enemy[i], b.bullet[j]) )
			{
				score += 1;
				e.drawOneEnemyToNull( e.enemy[i] );
				COORD x={1, 1};
				COORD y={45, 3};
				e.enemy[i].position[0] = random(x, y);
				e.enemy[i].position[1].X = e.enemy[i].position[0].X + 2;
				e.enemy[i].position[1].Y = e.enemy[i].position[0].Y + 1;

				b.drawOneBulletToNull( b.bullet[j] );
				b.bullet[j].Y = 30;
			}
}
void ConsoleGame::printScore()
{
	if(score >=0 && score <10)
		name = "扬州江少";
	else if(score >= 10 && score <20)
		name = "中央大学";
	else if(score >= 20 && score <30)
		name = "交通大学";
	else if(score >= 30 && score <40)
		name = "长春一汽";
	else if(score >= 40 && score <50)
		name = "上海市长";
	else if(score >= 50 && score <60)
		name = "市委书记";
	else if(score >= 60 && score <70)
		name = "临危受命";
	else if(score >= 70 && score <80)
		name = "九八抗洪";
	else if(score >= 80 && score <90)
		name = "三个代表";
	else
		name ="长者续秒";

	//SetPos(64,18);
	//cout<<life;
	SetPos(64, 20);
	cout<<score;
	SetPos(64, 22);
	cout<<name;
	


	
}
void ConsoleGame::checkPlane(Plane &p, Enemy &e, Bullet &b)
{
	for(int i = 0; i < 8; i++)
		for(int j=0; j<5; j++)
			if(judgeCoordInFrame(e.enemy[i], p.position[j]))
			{
				SetPos(62, 2);
				cout<<"坠毁";
				drawFrame(e.enemy[i], '+', '+');
				Sleep(1000);
				GameOver(p,e,b);
				break;
				
			}
}
void ConsoleGame::GameOver(Plane &p, Enemy& e,Bullet &b )
{
	system("cls");				
	COORD p1={28,9};
	COORD p2={53,15};
	drawFrame(p1, p2, '~', '|');
	SetPos(32,12);
	string str="还是要提高姿势水平";
	for( int i=0; i<str.size(); i++ )
	{
		Sleep(80);
		cout<<str[i];
	}
	Sleep(1000);
	system("cls");
	drawFrame(p1, p2, '=', '|');
	SetPos(31, 11);
	cout<<"击落敌机："<<score<<" 架";
	SetPos(31, 12);
	cout<<"得　　分："<<score*10<<"分";
	SetPos(31, 13);
	cout<<"获得称号："<<name;
	SetPos(30, 16);
	Sleep(1000);
	cout<<"继续？ 是（y）| 否（n）";

	char x=_getch();
	while(x == 'y' || x == 'n')
	{
		if (x == 'y')
		{
			//exit(0);
			system("cls");
			int temp = startMenu();
			//drawMenu();
			if(temp == 15)
				levelOfGame = secondSpeed ;
			system("cls");
			playingMenu();
			playingCtrl();
		}
		else
			exit(0);
	}
}
void ConsoleGame::pause()
{
	SetPos(61,2);
	cout<<"               ";
	SetPos(61,2);
	cout<<"暂停中...";
	char c=_getch();
	while(c!='p')
		c=_getch();
	SetPos(61,2);
	cout<<"         ";
}
void ConsoleGame::playingCtrl()
{
	Plane p;
	Enemy e;
	Bullet b;

	p.drawPlane();
	e.drawEnemy();
	while(1)
	{
		Sleep(8);
		if(_kbhit())
		{
			char x = _getch();
			if ( x == 'a' || x == 's' || x == 'd' || x == 'w')
			{
				p.drawPlaneToNull();
				p.planeMove(x);
				p.drawPlane();
			}
			else if(x == 'l')
			{
				shoot(b, p);
			}
			else if(x == 'p')
			{
				pause();
			}
			else if(x == 'q')
			{
				GameOver(p,e,b);
			}

		}
		
		if( b.timeOfBullet == 0 )
		{
			b.drawBulletToNull();
			b.bulletMove();
			b.drawBullet();
			checkEnemy(b, e);
		}			
		b.timeOfBullet++;
		if( 5 == b.timeOfBullet )
			b.timeOfBullet = 0;

		if(e.timeOfEnemy == 0)
		{
			e.drawEnemyToNull();
			e.enemyMove();			
			e.drawEnemy();
			checkPlane(p, e, b);
		}
		e.timeOfEnemy++;
		if(e.timeOfEnemy >= levelOfGame)
			e.timeOfEnemy = 0;
		printScore();

		
	}
}


