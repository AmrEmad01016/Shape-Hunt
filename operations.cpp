#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <iostream>



using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();
	pGame->printMessage("you have clicked sign");
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	
}

addTree::addTree(game* r_pGame): operation(r_pGame)
{
}
void addTree::Act() {
	pGame->printMessage("you have clicked tree");
	window* pw = pGame->getWind();
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point treeShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new tree(pGame, treeShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
addHouse::addHouse(game* r_pGame) : operation(r_pGame)
{
}
void addHouse::Act() {
	pGame->printMessage("you have clicked house");
	window* pw = pGame->getWind();
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point houseShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new house(pGame, houseShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
addKey::addKey(game* r_pGame) : operation(r_pGame)
{
}
void addKey::Act() {
	pGame->printMessage("you have clicked key");
	window* pw = pGame->getWind();
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point keyShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new key(pGame, keyShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

addArrow::addArrow(game* r_pGame) : operation(r_pGame)
{
}
void addArrow::Act() {
	pGame->printMessage("you have clicked Arrow");
	window* pw = pGame->getWind();
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point arrowShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new arrow(pGame, arrowShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
addDumple::addDumple(game* r_pGame) : operation(r_pGame)
{
	
}
void addDumple::Act() {
	pGame->printMessage("you have clicked Dumple");
	window* pw = pGame->getWind();
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point dumbelShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new dumbel(pGame, dumbelShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}

addCar::addCar(game* r_pGame) : operation(r_pGame)
{

}
void addCar::Act() {
	pGame->printMessage("you have clicked CAR");
	window* pw = pGame->getWind();
	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point carShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new car(pGame, carShapeRef);
	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}

operSave::operSave(game* r_pGame) : operation(r_pGame)
{
}
void operSave::Act() {
	pGame->printMessage("you have clicked save");

}
 operIncrease::operIncrease(game* r_pGame):operation(r_pGame)
{
}
void operIncrease::Act() {
	shape* shp;
	grid* pGrid = pGame->getGrid();
	shp = pGrid->getActiveShape();
	pGame->printMessage("you have clicked rotate");


	if (shp) shp->resizeup();
}
operDecrease::operDecrease(game* r_pGame) : operation(r_pGame)
{
	
}
void operDecrease::Act() {

	shape* shp;
	grid* pGrid = pGame->getGrid();
	shp = pGrid->getActiveShape();
	pGame->printMessage("you have clicked rotate");

	
	if(shp) shp->resizedown();
}
operHint::operHint(game* r_pGame) : operation(r_pGame)
{
}
void operHint::Act() {
	pGame->printMessage("you have clicked hint");

}
operLevels::operLevels(game* r_pGame) : operation(r_pGame)
{
}
void operLevels::Act() {
	pGame->printMessage("you have clicked levels up");

}
operRefresh::operRefresh(game* r_pGame) : operation(r_pGame)
{
}
void operRefresh::Act() {
	pGame->printMessage("you have clicked refresh");



	grid* pgrid = pGame->getGrid();

	shape* shp;
	int x, y, unit, r, s;
	srand(time(0));

	x =  rand() % (400);
	y = 80 + rand() % (config.windHeight - 80 + 1);

	point ref = { x,y };

	unit =  rand() % 2;
	r = 1 + rand() % 2;

	s = rand() % 6;




	switch (s)
	{
	case(0):
		shp = new Sign(pGame, ref);
		break;
	case(1):
		shp = new dumbel(pGame, ref);
		break;
	case(2):
		shp = new house(pGame, ref);
		break;
	case(3):
		shp = new car(pGame, ref);
		break;
	case(4):
		shp = new arrow(pGame, ref);
		break;
	case(5):
		shp = new tree(pGame, ref);
		break;
	/*case(6):
		shp = new key(pGame, ref);
		break;*/
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


	
	

	pgrid->addShape(shp);
	shp = nullptr;
}

operRotate::operRotate(game* r_pGame) : operation(r_pGame)
{
}
void operRotate::Act() {
	shape* shp;
	grid* pGrid = pGame->getGrid();
	shp = pGrid->getActiveShape();
	pGame->printMessage("you have clicked rotate");
	
	if (shp) shp->rotate();
	
}

operDelete::operDelete(game* r_pGame): operation(r_pGame)
{
	
}
void operDelete::Act() {
	pGame->printMessage("you have clicked delete");
	grid* pGrid = pGame->getGrid();
	pGrid->deleteActiveShape();

}

//randshap::randshap(game* r_pGame):operation(r_pGame)
//{
//	
//
//
//}
