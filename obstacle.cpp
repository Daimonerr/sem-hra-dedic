#include "obstacle.h"

YXPART::YXPART(const int & y, const int & x, const char & c)
{
	posY = y;
	posX = x;
	partChar = c;
}

CObstacle::CObstacle(const int & y, const int & x, const int & sp): health(3), obstLength(6), speed(sp)
{
	buildPart(y,x, '#');
	buildPart(y,x+1, '#');
	buildPart(y+1,x, '#');
	buildPart(y+1,x+1, '#');
	buildPart(y,x+2, '#');
	buildPart(y+1,x+2, '#');
}

void CObstacle::printObst()const
{
	for (int i = 0; i < obstLength; i++)
		mvaddch(obstObj[i].posY, obstObj[i].posX, obstObj[i].partChar);
	
}

void CObstacle::clearObst()const
{
	for (int i = 0; i < obstLength; i++)
		mvaddch(obstObj[i].posY, obstObj[i].posX, ' ');
	
}

bool CObstacle::moveObst(CTimer & cntTime)
{	
	if (cntTime.getMsec() % speed == 0 && cntTime.getMsec() != 0)
	{	
		if (isOnEdge()) return false;

		clearObst();
		for (int i = 0; i < obstLength; i++)
		{
			obstObj[i].posY += 1;
		}
		printObst();
	}


	return true;
}


void CObstacle::buildPart(const int & y,const int & x,const char & part)
{
	YXPART tmp(y,x,part);
	obstObj.push_back(tmp);
}

bool CObstacle::isOnEdge()const
{
	if(obstObj[2].posY == 44)
	{
		clearObst();
		return true;	
	}
	return false;
}

bool CObstacle::collide(const int & y, const int & x)const
{
	for (int i = 0; i < obstLength; i++)
	{
		if ( obstObj[i].posY == y && obstObj[i].posX == x)
			return true;
	}

	return false;
}