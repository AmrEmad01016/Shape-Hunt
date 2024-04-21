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

addTraffic::addTraffic(game* r_pGame) : operation(r_pGame)
{
}
void addTraffic::Act() {
	pGame->printMessage("you have clicked traffic");

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
	pGame->printMessage("you have clicked increase");

}
operDecrease::operDecrease(game* r_pGame) : operation(r_pGame)
{
}
void operDecrease::Act() {
	pGame->printMessage("you have clicked drcrease");

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

}

operRotate::operRotate(game* r_pGame) : operation(r_pGame)
{
}
void operRotate::Act() {
	pGame->printMessage("you have clicked rotate");

}

operDelete::operDelete(game* r_pGame): operation(r_pGame)
{
}
void operDelete::Act() {
	pGame->printMessage("you have clicked delete");

}
