#ifndef SHIP_H
#define SHIP_H

#include "bullet.h"

using namespace std;

class CShip {
	public:
		CShip();
	//	~CShip();
		void printShip()const;
		void clearShip()const;
		void newBullet();
		void moveBullets();
		void shipControll();
		void bulletHit(vector<CObstacle> & obstacles, int & cntObst, int & c_score);
		bool shipHit(vector<CObstacle> & obstacles, int & cntObst);
	private:
		vector<YXPART> ship;
		vector<CBullet> ammo;
		void buildPart(const int & y,const int & x,const char & part);

		int cntBullets;
		int shipLength;
};






#endif