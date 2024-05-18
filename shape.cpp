#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <cstdlib>
#include <time.h>

double shape::getUnitlen()
{
	return unitlen;
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



bool shape::checkboundries() const
{
	return false;
}

void shape::Match()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();
	int shapeCount = pGrid->getshapecount();
	shape** shapeList = pGrid->getRandShapes();
	for (int i = 0; i < shapeCount; i++) {
		int T = shapeList[i]->getType();
		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle(), angle = activeShape->getAngle();
		point R_ref = shapeList[i]->RefPoint, A_ref = activeShape->RefPoint;

		if (activeShape->getType() == T && A_ref.x == R_ref.x && A_ref.y == R_ref.y && unitlen == size && sin(angle)  == sin(A) ) {
			pGame->changeScore(2);
			delete shapeList[i];
			pGrid->deleteActiveShape();
		}
		else { 
			pGame->changeScore(-1); 
			
		}
	}
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
