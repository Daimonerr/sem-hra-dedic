
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
	LOADLEVEL(const int & a, const int & tik, const int & speedo)
	{
		y=2;
		x=a;
		time=tik;
		sp = speedo;
	}
	int y;
	int x;
	int time;
	int sp;
};

class CGame {
	public:
		CGame();
		~CGame();
		void runGame();
		void drawMap();

	private:
		void moveObstacles();
		void deleteObst(const int & i);
		void spawnObstacles();
		void drawSquare(const int & height, 
						const int & width, 
						const int & startY, 
						const int & startX, 
						const char & printChar);
		void startMenu();
		bool getFile();
		void printUtilities();
		bool gameOver();
		void gameEnding();
//		int mapX,mapY;
		vector<CObstacle> obstacles;
		int c_score, c_cntObst, c_health, c_remainObst;
		char c_nickname[20],c_mapName[20];
		CTimer cntTime;
		CShip BattleShip;	


		///////////////
		vector<LOADLEVEL> file;
		int c_cntFileObjs;
};






#endif