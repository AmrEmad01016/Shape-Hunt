#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <time.h>
#include <iostream>

using namespace std;

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
	if (activeShape){
		delete activeShape;
	}


	for (int i = 0; i < shapeCount; i++) {
		delete shapeList[i];
	}
	
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
		newShape = nullptr;
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
	activeShape = nullptr;
}

shape* grid::getActiveShape()
{
	return activeShape;
}

void grid::randshapes()
{
	srand(time(0));

	while (this->getshapecount() < (2 * pGame->getlevels() - 1)) {



		shape* shp;
		int x, y, unit, resizetype, type, a;

		x = rand() % 12;
		y = rand() % 12;


		point ref = { x * 30,10 + y * 30 };

		unit = rand() % 2;
		resizetype = 1 + rand() % 2;

		type = rand() % 7;

		int r, g, b;

		a = rand() % 3;
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;

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


		switch (resizetype)
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
		else
		{
			shp->setcolor(0, 0, 0);
		}


		

		for (int i = 0; i < a; i++) {
			shp->rotate();

		}

		bool flag = true;
		if (pGame->getlevels()==2 ) {
			
			for (int i = 0; i < shapeCount; i++) {

				if (abs(shapeList[i]->getRefPoint().x - shp->getRefPoint().x) < (shapeList[i]->getmaxy() + shp->getmaxy()) && abs(shapeList[i]->getRefPoint().y - shp->getRefPoint().y) < (shapeList[i]->getmaxy() + shp->getmaxy())) flag= false;


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
	if (!activeShape)return;
	for (int i = 0; i < shapeCount; i++) {
		int T = shapeList[i]->getType();
		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle(), angle = activeShape->getAngle();
		point R_ref = shapeList[i]->getRefPoint(), A_ref = activeShape->getRefPoint();

		if (activeShape->getType() == T && abs(A_ref.x == R_ref.x)  && abs(A_ref.y == R_ref.y) && activeShape->getUnitlen() == size && (round(sin(angle)) == round(sin(A)) ||(T==6 && sin(angle)*sin(A)!=0)) ) {
			pGame->changeScore(2);

			delete shapeList[i];
			shapeList[i] = nullptr;
			for (int i = 0; i < shapeCount; i++) {

				if (shapeList[i] == nullptr) {
					shapeList[i] = shapeList[i + 1];
					shapeList[i + 1] = nullptr;
				}

			}
			deleteActiveShape();
			shapeCount--;
			if (shapeCount == 0) {
				pGame->inc_level();
			}
			return;
		}

	}
	pGame->changeScore(-1);
}


