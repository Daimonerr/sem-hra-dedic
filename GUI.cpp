#include "GUI.h"

CGame::CGame(): c_cntBullets(0), c_score(0), c_crntObst(0), c_health(3), c_remainObst(0), c_cntFileObjs(0)
{
	initscr();
	c_nickname[0]='\0';
	c_mapName[0]='\0';
	printw("Enter your nickname: ");
	getnstr(c_nickname, 19);
	
}


CGame::~CGame()
{
	nodelay(stdscr, false);
	for (auto it = 	obstacles.begin() ; it != obstacles.end(); ++it)
		{ delete (*it); }
    obstacles.clear();
    ammo.clear();
	endwin();
}

void CGame::moveBullets()
{
	for (int i = 0; i < c_cntBullets; i++)
	{
		if ( ! ammo[i].moveO())
		{
			deleteBullet(i);
			i--;
		}
		
	}	
}

void CGame::runGame()
{

	startMenu();
	clear();
	noecho();
	nodelay(stdscr,true);
	curs_set(0);
	keypad(stdscr, true);

	drawMap();
	

	while( ! gameOver())
	{

		BattleShip.printO();
		spawnObstacles();

		moveBullets();
		moveObstacles();
		
		refresh();
		checkShip();
		checkBullets();
		if (cntTime.getPlaytime() == 200 )
			break;


//////////////////////////////////////////////
		usleep(20000);
//////////////////////////////////////////////

		BattleShip.clearO();
		printUtilities();
		gameControll();
		cntTime.addTime();
	}

	gameEnding();
}

void CGame::checkShip()
{

	vector<YXPART> shipCPoints(BattleShip.giveCollisionPoints());

	for ( int i = 0; i < 21; i++)
	{
		if (hitShip(shipCPoints[i]))
			return;
	}
}
bool CGame::hitShip(YXPART & shipCPoint)
{
	for( int j = 0; j < c_crntObst; j++)
	{
		if (obstacles[j]->collide(shipCPoint.offsY,shipCPoint.offsX))
		{
			deleteObst(j);
			c_health--;	
			return true;
		}
	}
	return false;
}

void CGame::checkBullets()
{
	for ( int i = 0; i < c_cntBullets; i++)
	{
		YXPART bullet(ammo[i].giveCorePoint());
		
		if( hitBullet(bullet, i))
			return;
	}	
}

bool CGame::hitBullet(YXPART & bullet, const int & cnt)
{
	for( int j = 0; j < c_crntObst; j++)
	{
		if (obstacles[j]->collide(bullet.offsY,bullet.offsX))
		{	
			deleteBullet(cnt);
			deleteObst(j);

			c_score += 20;
			return true;
		}
	}
	return false;
}


void CGame::gameControll()
{
	switch (getch())
	{
		case KEY_UP:
			BattleShip.moveUp();
			break;

		case KEY_DOWN:
			BattleShip.moveDown();
			break;

		case KEY_LEFT:
			BattleShip.moveLeft();
			break;

		case KEY_RIGHT:
			BattleShip.moveRight();
			break;
		
		case 'f':
			ammo.push_back(BattleShip.newBullet());
			c_cntBullets++;
			break;
		case 'l':


			nodelay(stdscr, false);
			mvprintw(34,65,"PAUSED");
			BattleShip.printO();
			getch();

			mvprintw(34,65,"      ");
			BattleShip.clearO();
			nodelay(stdscr, true);
			break;
	}

}


void CGame::drawSquare(const int & height,const int & width, const int & startY, const int & startX, const char & printChar)const
{

	attron(A_BOLD);

	for (int i = startY; i < (height+startY); i++)
	{
		mvaddch(i, startX, printChar);
		mvaddch(i, startX+width, printChar);
	}

	for (int i = startX; i < (width+startX+1); i++)
	{
		mvaddch(startY, i, printChar);
		mvaddch(startY+height, i, printChar);
	}

	attroff(A_BOLD);
}
void CGame::startMenu()
{
	drawSquare(45, 60, 0, 0, (char)219);
	attron(A_BOLD);
	mvprintw(10,13,"PLEASE WRITE NAME OF THE LEVEL FILE");
	attroff(A_BOLD);


	attron(A_UNDERLINE);
	mvprintw(16,5,"SUMMARY:");
	attroff(A_UNDERLINE);

	mvprintw(18,10,"This game is a action-shooter.");
	mvprintw(19,10,"Your main objective is to destroy as many"); 
	mvprintw(20,10,"obstacles as u can and not being hit by them.");					
	mvprintw(21,10,"Game has 10 levels in total.");
	mvprintw(22,10,"Higher levels are going to be harder to survive.");
	mvprintw(23,10,"Each destroyed obstacle gives you +20 score.");
	mvprintw(24,10,"Every 400 points of score will give you random bonus");
	mvprintw(25,10,"(more guns, shield, extra health).");


	attron(A_UNDERLINE);
	mvprintw(27,5,"CONTROLLS:");
	attroff(A_UNDERLINE);

	mvprintw(29,10,"Right Arrow-Key - to move right");
	mvprintw(31,10,"Left Arrow-Key  - to move left");
	mvprintw(33,10,"Upper Arrow-Key - to move up");
	mvprintw(35,10,"Lower Arrow-Key - to move down");
	mvprintw(37,10,"F               - to shoot");
	mvprintw(39,10,"G               - to pause the game");
	move(11,22);

	while ( ! getFile())
	{
		mvprintw(11,22,"                        ");
		mvprintw(13,17,"Invalid file. Try again.");
		move(11,22);
	}

	mvprintw(13,7,"Successfuly loaded. Press any key to continue.");
		
	getch();
}


void CGame::drawMap()const
{
//----------------------------------VYKRESLENI MAPY

	drawSquare(45, 60, 0, 0, (char)219);
	drawSquare(45, 15, 0, 60, (char)219);

//---------------------------------VYKRESLENI PANELU
	
	attron(A_BOLD);
	attron(A_UNDERLINE);
	
	mvprintw(3,66,"TIME");
	mvprintw(7,65,"REMAIN");
	mvprintw(11,66,"SCORE");
//	mvprintw(12,65,"BONUS");
	mvprintw(38,65,"HEALTH");

	attroff(A_UNDERLINE);
	attroff(A_BOLD);
	refresh();
}

void CGame::moveObstacles()
{

	for (int i = 0; i < c_crntObst; i++)
	{
		if( ! obstacles[i]->moveO(cntTime))
		{
			deleteObst(i);
			i--;
		}
	}
}


void CGame::deleteObst(const int & i)
{
	auto it = (obstacles.begin()+i);
	delete (*it);
	obstacles.erase(obstacles.begin()+i);

	c_crntObst--;
}



void CGame::deleteBullet(const int & i)
{
	ammo.erase(ammo.begin()+i);
	c_cntBullets--;
}

void CGame::spawnObstacles()
{
	for (int i = 0; i < c_cntFileObjs; i++)
	{
		if ( file[i].time == cntTime.getPlaytime() && cntTime.getMsec() == 0 )
		{
	
			switch (file[i].type)
			{
				case 'A':
					obstacles.push_back(new CObstacleA(file[i].y,file[i].x, '#',file[i].sp));
					break; 
				case 'B':
					obstacles.push_back(new CObstacleB(file[i].y,file[i].x, '#',file[i].sp));			
					break;
				case 'C':
					obstacles.push_back(new CObstacleC(file[i].y,file[i].x, '#',file[i].sp));			
					break;
			}

			c_crntObst++;
			c_remainObst--;
		}
	}

}

bool CGame::getFile()
{
	int controll;
	int x,time,speed;
	char type;
	FILE *mapFile;
	getnstr(c_mapName,19);

	mapFile = fopen(c_mapName,"r");
	if (mapFile == NULL)
		return false;

	c_cntFileObjs = 0;

	while ( (controll = fscanf(mapFile, "%d %d %d %c", &x, &time, &speed, &type)) != EOF && ( type == 'A' || type == 'B' || type == 'C'))
	{
		if (controll < 3)
		{
			fclose(mapFile);
			return false;
		}
		LOADLEVEL tmp(x,time,speed,type);
		file.push_back(tmp);
		c_cntFileObjs++;

	}


	if (c_cntFileObjs == 0)
		return false;

	c_remainObst = c_cntFileObjs;	
	fclose(mapFile);

	return true;
}


void CGame::printUtilities ()
{
	mvprintw(8,67,"   ");
	mvprintw(8,67,"%d", c_remainObst);
	mvprintw(12,67,"%d", c_score);
	mvprintw(40,67,"%d", c_health);
	mvprintw(4,66,"%s", cntTime.printTime().c_str());	
}

bool CGame::gameOver()
{
	if ( c_health == 0)
		return true;
	return false;
}

void CGame::gameEnding()
{
	clear();
	nodelay(stdscr,false);

	FILE *score = fopen("score.txt","a");
	fprintf(score, "Nickname: %s   Map: %s   Score: %d\n", c_nickname, c_mapName, c_score);
	fclose(score);

	drawSquare(45, 60, 0, 0, (char)219);
	attron(A_BOLD);
	mvprintw(9,18,"END OF THE GAME");
	mvprintw(10,10,"Your score was added to file score.txt");

	attroff(A_BOLD);
	getch();

}