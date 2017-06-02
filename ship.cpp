#include "ship.h"



CShip::CShip ():CObject(41,28,'A')
{
	buildOffset(-1,-1,'/');
	buildOffset(-1,1,'\\');
	buildOffset(-1,0,'|');

	buildOffset(0,-2,'/');
	buildOffset(0,-1,'#');
	buildOffset(0,1,'#');
	buildOffset(0,2,'\\');

	buildOffset(1,3,'/');
	buildOffset(1,2,'/');
	buildOffset(1,1,'O');
	buildOffset(1,0,'|');
	buildOffset(1,-1,'O');
	buildOffset(1,-2,'\\');
	buildOffset(1,-3,'\\');

	buildOffset(2,3,'^');
	buildOffset(2,2,'^');
	buildOffset(2,1,'^');
	buildOffset(2,0,'^');
	buildOffset(2,-1,'^');
	buildOffset(2,-2,'^');
	buildOffset(2,-3,'^');
}

CBullet CShip::newBullet()
{
	CBullet newB(c_posY-1, c_posX, '*');

	return newB;
}



void CShip::moveLeft()
{
	if (c_posX - 3 == 1 )
		return;
	c_posX -= 2;
}

void CShip::moveRight()
{
	if (c_posX + 3 == 59 )
		return;
	c_posX += 2;
}

void CShip::moveUp()
{
	if (c_posY - 1 == 1 )
		return;
	c_posY--;
}

void CShip::moveDown()
{
	if (c_posY + 2 == 44 )
		return;
	c_posY ++;
}

bool CShip::isCollision()
{
	return false;
}

/*
void CShip::bulletHit(vector<CObstacle*> & obstacles, int & c_cntObst, int & c_score)
{
	for (int i = 0; i < cntBullets; i++)
	{

		if(ammo[i].collision(obstacles, c_cntObst))
		{
			cntBullets--;
			ammo[i].clearBullet();
			ammo.erase(ammo.begin()+i);            //111111111111111111111111111111
			i--;
			c_score += 20;

		}
	}
}
*/

/*
bool CShip::shipHit(vector<CObstacle*> & obstacles, int & cntObst)
{
	for ( int i = 0; i < c_objLength; i++)
	{
		for( int j = 0; j < cntObst; j++)
		{
			if (obstacles[j]->collide(parts[i].posY,parts[i].posX))
			{
				obstacles[j]->clearO();					
				auto it = (obstacles.begin()+j);
				delete (*it);
				obstacles.erase(obstacles.begin()+j);
				cntObst--;

				return true;
				

			}
		}
	}
	return false;
}
*/