#include "object.h"


CObject::CObject(): c_objLength(1)
{}

CObject::CObject(const int & oLength )
{
	c_objLength = oLength;
}

void CObject::buildPart(const int & y,const int & x,const char & part)
{
	YXPART tmp(y,x,part);
	parts.push_back(tmp);
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

void CObject::moveO()
{}