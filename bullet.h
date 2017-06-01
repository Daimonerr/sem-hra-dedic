#ifndef BULLET_H
#define BULLET_H

#include "obstacle.h"


class CBullet {
	public:
		CBullet(const int & y, const int & x);
		bool moveBullet();
		bool collision(vector<CObstacle> & obstacles, int & cntObst);
		void clearBullet();
	private:	
		int c_posY;
		int c_posX;
		int c_bulletChar;
};






#endif