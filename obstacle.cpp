#include "obstacle.h"


CObstacle::CObstacle():CObject()
{}

bool CObstacle::moveO(CTimer & cntTime)
{
	return true;
}


bool CObstacle::isOnEdge()const
{
	if(parts[2].posY == 44)
	{
		clearO();
		return true;	
	}
	return false;
}

bool CObstacle::collide(const int & y, const int & x)const
{
	for (int i = 0; i < c_objLength; i++)
	{
		if ( parts[i].posY == y && parts[i].posX == x)
			return true;
	}

	return false;
}