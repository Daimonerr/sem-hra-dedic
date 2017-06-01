#include "ship.h"



CShip::CShip (): cntBullets(0), shipLength(21)
{
	buildPart(40,27,'|');
	buildPart(40,29,'|');

	buildPart(41,26,'/');
	buildPart(41,27,'#');
	buildPart(41,28,'A');
	buildPart(41,29,'#');
	buildPart(41,30,'\\');

	buildPart(42,25,'/');
	buildPart(42,26,'/');
	buildPart(42,27,'O');
	buildPart(42,28,'|');
	buildPart(42,29,'O');
	buildPart(42,30,'\\');
	buildPart(42,31,'\\');

	buildPart(43,25,'^');
	buildPart(43,26,'^');
	buildPart(43,27,'^');
	buildPart(43,28,'^');
	buildPart(43,29,'^');
	buildPart(43,30,'^');
	buildPart(43,31,'^');
}

void CShip::buildPart(const int & y,const int & x,const char & part)
{
	YXPART tmp(y,x,part);
	ship.push_back(tmp);
}

void CShip::printShip()const
{
	for (int i = 0; i < shipLength; i++){
		mvaddch(ship[i].posY, ship[i].posX,ship[i].partChar);
	}
}

void CShip::clearShip()const
{
	for (int i = 0; i < shipLength; i++){
		mvaddch(ship[i].posY, ship[i].posX,' ');
	}
}

void CShip::newBullet()
{
	CBullet tmp(ship[4].posY -1, ship[4].posX);

	ammo.push_back(tmp);
	cntBullets++;
}

void CShip::moveBullets()
{
	for (int i = 0; i < cntBullets; i++)
	{
		if ( ! ammo[i].moveBullet())
		{
			cntBullets--;
			ammo.erase(ammo.begin()+i);
			i--;
		}
	}	


}

void CShip::shipControll()
{
	int direction = getch();

	switch (direction)
	{
		case KEY_UP:
			if (ship[0].posY == 1 )
				break;

			for (int i = 0; i < 21; i++)
			{
				ship[i].posY -= 1;
			}
			break;
		case KEY_DOWN:
			if (ship[14].posY == 44 ) break;
			
			for (int i = 0; i < 21; i++){
				ship[i].posY += 1;
			}
			
			break;
		case KEY_LEFT:
			if (ship[14].posX == 1 ) break;
			for (int i = 0; i < 21; i++)
			{
				ship[i].posX -= 2;
			}
			break;
		case KEY_RIGHT:
			if (ship[20].posX == 59 ) break;
			for (int i = 0; i < 21; i++)
			{
				ship[i].posX += 2;
			}
			break;
		case 'f':
			newBullet();
		case 'l':
			return;
	}



}


void CShip::bulletHit(vector<CObstacle> & obstacles, int & c_cntObst, int & c_score)
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

bool CShip::shipHit(vector<CObstacle> & obstacles, int & cntObst)
{
	for ( int i = 0; i < shipLength; i++)
	{
		for( int j = 0; j < cntObst; j++)
		{
			if (obstacles[j].collide(ship[i].posY,ship[i].posX))
			{
				obstacles[j].clearObst();
				obstacles.erase(obstacles.begin()+j);           //111111111111111111111111111111
				cntObst--;
				return true;
				

			}
		}
	}
	return false;
}