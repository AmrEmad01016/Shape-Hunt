#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <cstdlib>
#include <time.h>

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
