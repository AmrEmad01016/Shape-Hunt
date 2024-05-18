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

	if (!newShape->checkboundries()) return false;





	
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

	while ( this->getshapecount() < (2*pGame->getlevels() -1)) {



		shape* shp;
		int x, y, unit, r, type;
		//srand(time(0));

		x = rand() % (400); y = 80 + rand() % (config.windHeight - 80 + 1);

		point ref = { x,y };

		unit = rand() % 2;
		r = 1 + rand() % 2;

		type = rand() % 6;




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


		switch (r)
		{
		case(1):
			for (int i = 0; i < unit; i++)
				shp->resizeup();
		case(2):
			for (int i = 0; i < unit; i++)
				shp->resizedown();
		default:
			break;
		}




		this->addShape(shp);
		shp = nullptr;
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


