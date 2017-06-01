#include "obstacleB.h"


CObstacleB::CObstacleB(const int & y, const int & x, const int & sp):CObstacle(), c_obstSpeed(sp), c_direction(0), c_flip(1)
{
	buildPart(y,x, '/');
	buildPart(y,x+1, '#');
	buildPart(y,x+2, '\\');
	buildPart(y+1,x, '#');
	buildPart(y+1,x+1, '#');
	buildPart(y+1,x+2, '#');
	buildPart(y+2,x, '\\');
	buildPart(y+2,x+1, '#');
	buildPart(y+2,x+2, '/');
}


bool CObstacleB::moveO(CTimer & cntTime)
{	
	if (cntTime.getMsec() % c_obstSpeed == 0 && cntTime.getMsec() != 0)
	{	
		if (isOnEdge()) return false;
		clearO();
		for (int i = 0; i < c_objLength; i++)
		{
			if (c_flip == 1 )
				parts[i].posX++;
			else
				parts[i].posX--;

			parts[i].posY += 1;
		}

		c_direction++;
		if (c_direction == 3 && c_flip == 1)
		{
			c_direction = 0;
			c_flip=0;
		}
		if (c_direction == 3 && c_flip == 0)
		{
			c_direction = 0;
			c_flip=1;
		}

		printO();
	}
	return true;
}