#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <cstdlib>
#include <time.h>
#include<fstream>
#include<iostream>
double shape::getUnitlen()
{
	return unitlen;
}

point shape::getRefPoint()
{
	return RefPoint;
}

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

void shape::setunitlen(int n)
{
	unitlen *= n;
}

void shape::move(int x, int y)
{
	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
	if (!this->checkboundries()) {
		setRefPoint({ RefPoint.x - x, RefPoint.y - y });
		return;
	}
}


void shape::save(ofstream& f)
{
	
		f << getType() << "\t" << RefPoint.x << "," << RefPoint.y << "\t" << getAngle() << "\t" << unitlen <<"\t\n";
	
}



bool shape::checkboundries() const
{
	return false;
}




//void shape::increase()
//{
//	unitlen *= 2;
//}

//void shape::resizeUp()
//{
//	unitlen *= 2;
//}
//
//void shape::resizeDown()
//{
//	unitlen /= 2;
//
//}
void shape::resizedown()
{
	unitlen /= 2;

}
