#ifndef OBJECT_H
#define OBJECT_H

//#include "bullet.h"

#include <vector>
#include <ncurses.h>

using namespace std;

struct YXPART{
	YXPART(const int & y, const int & x, const char & c);
	int posY;
	int posX;
	char partChar;
};

class CObject {
	public:
		CObject();
		CObject(const int & oLength);
		void printO()const;
		void clearO()const;
		virtual void moveO();
		
		void buildPart(const int & y,const int & x,const char & part);
	
	//	void newBullet();
	//	void moveBullets();
	//	void bulletHit(vector<CObstacle> & obstacles, int & cntObst, int & c_score);
	//	bool shipHit(vector<CObstacle> & obstacles, int & cntObst);
	protected:
		vector<YXPART> parts;
//		vector<CBullet> ammo;
		
	//	int cntBullets;
		int c_objLength;
};






#endif