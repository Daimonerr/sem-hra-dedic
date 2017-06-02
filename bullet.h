#ifndef BULLET_H
#define BULLET_H

#include "obstacleB.h"


class CBullet : public CObject {
	public:
		CBullet(const int & y, const int & x, const char & bChar);
		bool moveBullet();
		virtual bool isCollision();
//		void clearBullet();
//	private:	
//		int c_posY;
//		int c_posX;
//		int c_bulletChar;
};






#endif