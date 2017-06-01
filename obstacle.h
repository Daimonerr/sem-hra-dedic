#ifndef OBSTACLE_H
#define OBSTACLE_H

//#include <vector>
//#include <ncurses.h>
#include "timer.h"


class CObstacle {
	public:
		CObstacle(const int & y, const int & x, const int & sp);
		void printObst()const;
		void clearObst()const;
		bool moveObst(CTimer & cntTime);
		bool isOnEdge()const;
		bool collide(const int & y, const int & x)const;
	private:
		void buildPart(const int & y,const int & x,const char & part);
		
		vector<YXPART> obstObj;
		int health;
		int obstLength;
		int speed;
};






#endif