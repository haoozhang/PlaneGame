#include <iostream>
using namespace std;
#include <string>
#include <Windows.h>
//#include "Core.h"
#include "Interface.h"

#define firstSpeed 30
#define secondSpeed 15


//class Bullet;
//class Enemy;
class Plane
{
friend class ConsoleGame;
//friend void playing(Plane &p, Bullet &b, Enemy &e);
//friend void shoot(Bullet &b, Plane &p);
//friend void checkPlane(Plane &p, Enemy &e);
public:
	Plane( );
	COORD getPosition (int index);
	void drawPlane( );
	void drawPlaneToNull( );
	void planeMove(char command);
	void shoot();
private:
	COORD position[5];
};

class Bullet
{
friend class ConsoleGame;
//friend void playing(Plane &p, Bullet &b, Enemy &e);
//friend void shoot(Bullet &b, Plane &p);
//friend void checkEnemy(Bullet &b, Enemy& e);
private:
	COORD bullet[10];
public:
	int timeOfBullet;
	Bullet();
	void drawBullet();
	void bulletMove();
	void drawBulletToNull();
	void drawOneBulletToNull(COORD c);
};

class Enemy
{
friend class ConsoleGame;
//friend void playing(Plane &p, Bullet &b, Enemy &e);
//friend void checkEnemy(Bullet &b, Enemy& e);
//friend void checkPlane(Plane &p, Enemy &e);

//friend void GameOver(Enemy& e);
protected:
	Frame enemy[8];
	
public:
	int timeOfEnemy;
	Enemy();
	void enemyMove();
	void drawEnemy();
	void drawEnemyToNull();
	void drawOneEnemyToNull(Frame f);
};

class ConsoleGame
{
private:
	int levelOfGame;
	int score;
	string name;
	//int life;
public:
	ConsoleGame();
	void setLevelOfGame(int l);
	void printScore();
	void shoot(Bullet &b, Plane &p);
	void checkEnemy(Bullet &b, Enemy &e);
	void checkPlane(Plane &p, Enemy &e, Bullet &b);
	void playingCtrl();
	void GameOver(Plane &p,  Enemy& e,Bullet &b);
	void pause();
};


