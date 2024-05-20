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
	rc = r; gc = g; bc = b;

	fillColor = color(r, g, b);

	borderColor = fillColor;
}


void shape::setAngle(double a) {

	angle = a;
}


int shape::getColor2()
{
	return gc;
}

int shape::getColor3()
{
	return bc;
}

int shape::getColor1()
{
	return rc ;
}

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

double shape::getAngle()
{
	return angle;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

void shape::setunitlen(int n)
{
	unitlen = n;
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
	f << getType() << "\t\t" << RefPoint.x << "\t" << RefPoint.y << "\t\t" << getAngle() << "\t\t" << unitlen << "\t\t" ;
}

void shape::load(ifstream& f)
{
	
	/*int typ, color1, color2, color3;  double x, y, angl, unit;
	while (f >> typ >> x >> y >> angl >>unit >>color1 >> color2 >> color3) {
		   setRefPoint({ x,y });
		   setAngle(angl);
		   setunitlen(unit);
		   setcolor(color1, color2, color3);
	}*/
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
