#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <iostream>



#include <fstream>
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

	grid* pGrid = pGame->getGrid();
	shape** shp = pGrid->getRandShapes();
	ofstream Datafile;
	Datafile.open("saveddata\\data.txt");
	Datafile << pGame->getlevels() << "\t\t" << pGame->getlives() << "\t\t" << pGame->getscores() << "\t\t"<<pGrid->getshapecount()<<"\n";
	for (int i = 0; i < pGrid->getshapecount(); i++) {
		shp[i]->save(Datafile);
		Datafile << shp[i]->getColor1()  <<"\t"<< shp[i]->getColor2() <<"\t" << shp[i]->getColor3() << "\n";
	}
	Datafile.close();

	pGame->printMessage("you have clicked save");
}
operLoad::operLoad(game* r_pGame) : operation(r_pGame)
{

}

void operLoad::Act() {

	int typ, color1, color2, color3;  double x, y, angl, unit;

	

	grid* pGrid = pGame->getGrid();

	pGrid->~grid();

	shape** shp = pGrid->getRandShapes();
	pGame->printMessage("you have clicked Load");
	ifstream data;
	data.open("saveddata\\data.txt");
	int le, li, z,c;
	data >> le >> li >> z>>c;
	pGame->setlevels(le); pGame->setlives(li); pGame->setscore(z); pGrid->setshapecount(c);
	for (int i = 0; i < pGrid->getshapecount(); i++) {
		
		data >> typ >> x >> y >> angl >> unit >> color1 >> color2 >> color3;
		
		switch (typ)
		{
		case(0):
			shp[i] = new Sign(pGame, { x,y });
			break;
		case(1):
			shp[i] = new dumbel(pGame, { x,y });
			break;
		case(3):
			shp[i] = new house(pGame, { x,y });
			break;
		case(2):
			shp[i] = new car(pGame, { x,y });
			break;
		case(5):
			shp[i] = new arrow(pGame, { x,y });
			break;
		case(6):
			shp[i] = new tree(pGame, { x,y });
			break;
		case(4):
			shp[i] = new key(pGame, { x,y });
			break;
		default:
			break;
		}
		for (int x = 0; x < angl/(3.14 / 2); x++) {
			shp[i]->rotate();
		}
		for (int z = 0; z < (unit/10); z++) {
			if((unit/10) >1)
				shp[i]->resizeup();

			else if ((unit / 10) <1)
			shp[i]->resizedown();
			 
		}
		shp[i]->setcolor(color1, color2, color3);
		
	}

		
	data.close();
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

	if (pGame->getlives() == 1) {
		pGame->printMessage("you can't refresh any more");
		return;

	}

	pGame->printMessage("you have clicked refresh");

	grid* pgird = pGame->getGrid();

	shape** shp = pgird->getRandShapes();

	for (int i = 0; i < pgird->getshapecount(); i++) {
		delete shp[i];
		shp[i] = nullptr;
	}

	pgird->setshapecount(0);

	pgird->randshapes();

	pGame->dec_lives();
	
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



selectgamelevel::selectgamelevel(game* r_pGame): operation (r_pGame)
{
}

void selectgamelevel::Act()
{
	pGame->printMessage("Enter valid level: ");
	window *pwind = pGame->getWind();
	grid* pgird = pGame->getGrid();
	char c;

	pwind->WaitKeyPress(c);
	

	if ('1' > c || c > '9') {
		pGame->printMessage("unvalid level number");
		return;
	}

	shape** shp = pgird->getRandShapes();

	for (int i = 0; i < pgird->getshapecount(); i++)
		delete shp[i];

	pgird->setshapecount(0);

	int n = int(c) - 48;

	pGame->setlevels(n);
	pGame->printMessage("the level was entered successfully");
	pgird->randshapes();
}

operExit::operExit(game* r_pGame): operation(r_pGame)
{
}

void operExit::Act()
{
	grid* pGrid = pGame->getGrid();
	shape** shp = pGrid->getRandShapes();
	ofstream Datafile;
	Datafile.open("saveddata\\data.txt");
	Datafile << pGame->getlevels() << "\t\t" << pGame->getlives() << "\t\t" << pGame->getscores() << "\t\t" << pGrid->getshapecount() << "\n";
	for (int i = 0; i < pGrid->getshapecount(); i++) {
		shp[i]->save(Datafile);
		Datafile << shp[i]->getColor1() << "\t" << shp[i]->getColor2() << "\t" << shp[i]->getColor3() << "\n";
	}
	Datafile.close();

	pGame->printMessage("you have clicked exit and if y didnot save , it is auto sava");
}
	


