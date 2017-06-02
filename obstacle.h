#ifndef OBSTACLE_H
#define OBSTACLE_H

//#include <vector>
//#include <ncurses.h>
#include "object.h"


class CObstacle : public CObject {
	public:
		CObstacle(const int & y, const int & x, const char & cChar);
		virtual ~CObstacle(){};
		virtual bool moveO(CTimer & cntTime);
		virtual bool isCollision();
		bool collide(const int & y, const int & x);
//	protected:
//		void buildPart(const int & y,const int & x,const char & part);
		
//		vector<YXPART> obstObj;
//		int health;
//		int obstLength;
//		int c_obstSpeed;
};






#endif