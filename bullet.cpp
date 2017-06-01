#include "bullet.h"

CBullet::CBullet(const int & y, const int & x): c_posY(y), c_posX(x), c_bulletChar('*')
{} 

bool CBullet::moveBullet()
{
	mvaddch(c_posY,c_posX, ' ');
	c_posY -= 1;
	
	if (c_posY == 1)
	{
		mvaddch(c_posY, c_posX, ' ');
		return false;
	}else
		mvaddch(c_posY,c_posX, c_bulletChar);
	return true;
}

bool CBullet::collision(vector<CObstacle> & obstacles, int & cntObst)
{
	for ( int i = 0; i < cntObst; i++)
	{
		if ( obstacles[i].collide(c_posY, c_posX))
		{
			obstacles[i].clearObst();
			obstacles.erase(obstacles.begin()+i);           //111111111111111111111111111111
			cntObst--;


			return true;
		}
	}

	return false;
}

void CBullet::clearBullet()
{
	mvaddch(c_posY, c_posX, ' ');
}