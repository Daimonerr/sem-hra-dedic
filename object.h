#ifndef OBJECT_H
#define OBJECT_H

//#include "bullet.h"

#include <vector>
#include <ncurses.h>
#include "timer.h"
#include <vector>

using namespace std;

struct YXPART{
	YXPART(const int & y, const int & x, const char & c);
	int offsY;
	int offsX;
	char offsChar;
};

class CObject {
	public:
		CObject();
		CObject(const int & y, const int & x, const char & coreC);
		virtual ~CObject(){};
		void printO()const;
		void clearO()const;
		virtual bool isCollision()=0;
		vector<YXPART> giveCollisionPoints();
		YXPART giveCorePoint();
//		virtual bool moveO(CTimer & cntTime);
		
		void buildOffset(const int & y,const int & x,const char & oChar);
	
	//	void newBullet();
	//	void moveBullets();
	//	void bulletHit(vector<CObstacle> & obstacles, int & cntObst, int & c_score);
	//	bool shipHit(vector<CObstacle> & obstacles, int & cntObst);
	protected:
		int c_posY;
		int c_posX;
		int c_coreChar;
		vector<YXPART> offset;
		int c_offsLen;
};






#endif