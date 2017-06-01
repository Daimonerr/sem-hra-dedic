#include "object.h"

YXPART::YXPART(const int & y, const int & x, const char & c)
{
	posY = y;
	posX = x;
	partChar = c;
}

CObject::CObject(): c_objLength(0)
{}

void CObject::buildPart(const int & y,const int & x,const char & part)
{
	YXPART tmp(y,x,part);
	parts.push_back(tmp);
	c_objLength++;
}

void CObject::printO()const
{
	for (int i = 0; i < c_objLength; i++){
		mvaddch(parts[i].posY, parts[i].posX,parts[i].partChar);
	}
}

void CObject::clearO()const
{
	for (int i = 0; i < c_objLength; i++){
		mvaddch(parts[i].posY, parts[i].posX,' ');
	}
}
/*
bool CObject::moveO(CTimer & cntTime)
{
	return true;
}*/