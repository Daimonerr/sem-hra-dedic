#include "obstacleA.h"


CObstacleA::CObstacleA(const int & y, const int & x, const int & sp):CObstacle(), c_obstSpeed(sp)
{
	buildPart(y,x, '#');
	buildPart(y,x+1, '#');
	buildPart(y+1,x, '#');
	buildPart(y+1,x+1, '#');
	buildPart(y,x+2, '#');
	buildPart(y+1,x+2, '#');
}


bool CObstacleA::moveO(CTimer & cntTime)
{	
	if (cntTime.getMsec() % c_obstSpeed == 0 && cntTime.getMsec() != 0)
	{	
		if (isOnEdge()) return false;
		clearO();
		for (int i = 0; i < c_objLength; i++)
		{
			parts[i].posY += 1;
		}
		printO();
	}
	return true;
}