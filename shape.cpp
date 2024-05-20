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

void shape::setcolor(int r, int g, int b)
{

	fillColor = color(r, g, b);

	borderColor = fillColor;

	rc = r; gc = g; bc = b;

}

int shape::getColor()
{
	return rc ,gc , bc ;
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
	
		f << getType() << "\t\t" << RefPoint.x <<"\t" << RefPoint.y << "\t\t" << getAngle() << "\t\t" << unitlen << getColor()<< "\t\n";
	
}

void shape::load(ifstream& f)
{
	/*int levels , lives , score, type ,x,y,angle ,color1 , color2; 
	while(f)
		Ref*/
}



bool shape::checkboundries() 
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
