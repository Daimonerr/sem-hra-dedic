
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <unistd.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include "ship.h"

using namespace std;

struct LOADLEVEL{
	LOADLEVEL(): y(0), x(0), time(0), sp(0)
	{}
	LOADLEVEL(const int & a, const int & tik, const int & speedo, const char & typeO)
	{
		y=3;
		x=a;
		time=tik;
		sp = speedo;
		type=typeO;
	}
	int y;
	int x;
	int time;
	int sp;
	char type;
};

class CGame {
	public:
		CGame();
		~CGame();
		void runGame();
		void drawMap()const;
		void moveBullets();
		void gameControll();
		void checkShip();
		void checkBullets();

	private:
		void moveObstacles();
		void deleteObst(const int & i);
		void deleteBullet(const int & i);
		void spawnObstacles();
		void drawSquare(const int & height, 
						const int & width, 
						const int & startY, 
						const int & startX, 
						const char & printChar)const;
		void startMenu();
		bool getFile();
		void printUtilities();
		bool gameOver();
		void gameEnding();
		bool hitBullet(YXPART & bullet, const int & cnt);
		bool hitShip(YXPART & shipCPoint);

		vector<CObstacle*> obstacles;
		vector<CBullet> ammo;

		int c_cntBullets;
		int c_score, c_crntObst, c_health, c_remainObst;
		char c_nickname[20],c_mapName[20];
		CTimer cntTime;
		CShip BattleShip;	


		///////////////
		vector<LOADLEVEL> file;
		int c_cntFileObjs;
};






#endif