#ifndef OBSTACLE_H
#define OBSTACLE_H

//#include <vector>
//#include <ncurses.h>
#include "object.h"


class CObstacle : public CObject {
	public:
		CObstacle();
		virtual ~CObstacle(){};
//		void printObst()const;
//		void clearObst()const;
		virtual bool moveO(CTimer & cntTime);
		bool isOnEdge()const;
		bool collide(const int & y, const int & x)const;
//	protected:
//		void buildPart(const int & y,const int & x,const char & part);
		
//		vector<YXPART> obstObj;
//		int health;
//		int obstLength;
//		int c_obstSpeed;
};






#endif