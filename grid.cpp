#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <time.h>


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
			if (shapeList[i])
				shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail

	if (!newShape->checkboundries()) { 
		delete newShape;
		return false; }





	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}

void grid::deleteActiveShape()
{
	delete activeShape;
	activeShape = 0;
}

shape* grid::getActiveShape()
{
	return activeShape;
}

void grid::randshapes()
{
	srand(time(0));

	while ( this->getshapecount() < (2*pGame->getlevels() -1)) {



		shape* shp;
		int x, y, unit, a, type;
		
		x = rand() % 12;
		 y =  rand() % 12;
		

		point ref = { x*30,10+y*30 };

		unit = rand() % 2;
		a = 1 + rand() % 2;

		type = rand() % 6;

		int r, g, b;


		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;

		switch (type)
		{
		case(0):
			shp = new Sign(pGame, ref);
			break;
		case(1):
			shp = new dumbel(pGame, ref);
			break;
		case(3):
			shp = new house(pGame, ref);
			break;
		case(2):
			shp = new car(pGame, ref);
			break;
		case(5):
			shp = new arrow(pGame, ref);
			break;
		case(6):
			shp = new tree(pGame, ref);
			break;
		case(4):
				shp = new key(pGame, ref);
				break;
		default:
			break;
		}


		switch (a)
		{
		case(1):
			for (int i = 0; i < unit; i++)
				shp->resizeup();
			break;
		case(2):
			for (int i = 0; i < unit; i++)
				shp->resizedown();
			break;
		default:
			break;
		}

		if (pGame->getlevels() < 3) {

			shp->setcolor(r, g, b);
		}

		bool flag = true;
		if (pGame->getlevels()==2 ) {
			
			point ref1, ref2; double maxy1, maxy2;
			for (int i = 0; i < shapeCount; i++) {
				ref1 = shapeList[i ]->getRefPoint();
				ref2 = shp->getRefPoint();
				maxy1 = shapeList[i ]->getmaxy();
				maxy2 = shp->getmaxy();
				if (abs(ref1.x - ref2.x) < (maxy1 + maxy2) || abs(ref1.y - ref2.y) < (maxy1 + maxy2)) {
					flag = false;
					
					}
			}

		}

		if (flag == true) {
			this->addShape(shp);
			shp = nullptr;

		}
		else
		{
			delete shp;
			shp = nullptr;
		}


		
	}
}

void grid::setshapecount(int n)
{
	shapeCount = n;
}

shape** grid::getRandShapes()
{
	return shapeList;
}

void grid::Match()
{

	for (int i = 0; i < shapeCount; i++) {
		int T = shapeList[i]->getType();
		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle(), angle = activeShape->getAngle();
		point R_ref = shapeList[i]->getRefPoint(), A_ref = activeShape->getRefPoint();

		if (activeShape->getType() == T && abs(A_ref.x - R_ref.x) < 100 && abs(A_ref.y - R_ref.y) < 100 && activeShape->getUnitlen() == size && sin(angle) == sin(A)) {
			pGame->changeScore(2);
			
			delete shapeList[i];
			shapeList[i] = nullptr;
			for (int i = 0; i < shapeCount - 1; i++) {

				if (shapeList[i] == nullptr) {
					shapeList[i] = shapeList[i + 1];
					shapeList[i + 1] = nullptr;
				}

			}
			deleteActiveShape();
			shapeCount--;
			
		}
		else {
			pGame->changeScore(-1);
			
		}
	}

}


