#include "game.h"
#include "gameConfig.h"
#include <ctime>


game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
	delete gameToolbar;
}


int game::getlives()
{
	return lives;
}

void game::dec_lives()
{
	lives--;
	if (lives == 0) {


		setlives(5);
		setscore(0);
		setlevels(1);
		cnt = 100;

	}
}

void game::setlives(int l)
{
	lives = l;
}

void game::setlevels(int l)
{
	 level = l;
}

//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

void game::handleKeyPress(char key)
{
	if (!shapesGrid->getActiveShape()) return;
	int step = config.gridSpacing;
	shape* activeshape = shapesGrid->getActiveShape();
	switch (key) {
	case'w':               //move up
		activeshape->move(0, -step);
		shapesGrid->draw();
		gameToolbar->updatescore();
		break;
	case's':                    // move down 
		activeshape->move(0, step);

		shapesGrid->draw();
		gameToolbar->updatescore();
		break;
	case'd':                    // move left
		activeshape->move(step, 0);

		shapesGrid->draw();
		gameToolbar->updatescore();
		break;
	case'a':                    // move right
		activeshape->move(-step, 0);

		shapesGrid->draw();
		gameToolbar->updatescore();
		break;
	case'm':
		shapesGrid->Match();

		shapesGrid->draw();
		gameToolbar->updatescore();
		break;
 
	}

	
}



operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case ITM_TREE :
		op = new addTree(this);
		break;
	case ITM_HOUSE:
		op = new addHouse(this);
		break;
	
	case ITM_KEY:
		op = new addKey(this);
		break;
	case ITM_ARROW:
		op = new addArrow(this);
		break;
	case ITM_DUMPLE:
		op = new addDumple(this);
		break;
	case ITM_CAR:
		op = new addCar(this);
		break;

	case ITM_SAVE:
		op = new operSave(this);
		break;

	case ITM_INCREASE:
		op = new operIncrease(this);
		break;
	case ITM_DECREASE:
		op = new operDecrease(this);
		break;
	case ITM_HINT:
		op = new operHint(this);
		break;
	case ITM_LEVELS:
		op = new operLevels(this);

		op = new selectgamelevel(this);
		break;
	case ITM_REFRESH:
		op = new operRefresh(this);
		break;
	case ITM_ROTATE:
		op = new operRotate(this);
		break;
	case ITM_LOAD:
		op = new operLoad(this);
		break;
	case ITM_DELETE:
		op = new operDelete(this);
		break;
	
	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

int game::getlevels()
{
	return level;
}

void game::inc_level()
{
	level++;
	shapesGrid->randshapes();
}

int game::getscores()
{
	return score;
}

int game::get_cnt()
{
	return cnt;
}

void game::setscore(int s)
{
	score = s;
}

void game::setHintFlag(bool b)
{
	hint_flag = b;
}

void game::setHint(double cnt)
{
	hint_t = cnt;
}

void game::changeScore(int ds)
{
	score += ds;
}

//int game::gettrails()
//{
//	int T=5;
//	if (T>0)
//	trail = T ;
//	return T;
//}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}



////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	

	char key;
	char c;

	bool tim = false;




	printMessage("press t to add a timer, else press any other key");
	pWind->WaitKeyPress(key);

	if (key == 't') {

		tim = true;
	}


	printMessage("Please enter level between 1 and 9 : ");
	
	while (true) {

		

		pWind->WaitKeyPress(c);


		if ('1' > c || c > '9') {
			printMessage("unvalid level number, please enter level between 1 and 9 : ");
			continue;
		}




		int n = int(c) - 48;

		setlevels(n);
		printMessage("the level was entered successfully");
		shapesGrid->randshapes();

		shapesGrid->draw();
		gameToolbar->updatescore();
		break;
	}
	
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	
	/*shapesGrid->randshapes();*/
	toolbarItem clickedItem=ITM_CNT;

	double timer = clock();
	do
	{
		
		while (pWind->GetKeyPress(key)) {
			pWind->FlushKeyQueue();
			handleKeyPress(key);
			
		}
	
		if (clock() - timer > 1000 && cnt >= 0 && tim == true) {
			timer = clock();
			cnt--;
			gameToolbar->setTime(cnt);
			gameToolbar->inc_time();
			if (cnt == 0) {
				dec_lives();
				cnt = 100;
			}

		}

		

		if (pWind->GetMouseClick(x, y)) {	//Get the coordinates of the user click
			//2-Explain the user click
			//If user clicks on the Toolbar, ask toolbar which item is clicked
			
			

			if (y >= 0 && y < config.toolBarHeight)
			{
				clickedItem = gameToolbar->getItemClicked(x);

				//3-create the approp operation accordin to item clicked by the user
				operation* op = createRequiredOperation(clickedItem);
				if (op)
					op->Act();

				delete op;
				op = nullptr;
			

				shapesGrid->draw();         //4-Redraw the grid after each action

				gameToolbar->updatescore(); //phase 1 only

			}
			pWind->FlushMouseQueue();
		}
		if (hint_flag&&level>2) {
			shape** shapeList = getGrid()->getRandShapes();
				if (clock() - hint_t > 2000) {

					shapeList[shapesGrid->getshapecount() - 1]->setcolor(0, 0, 0);
					shapesGrid->draw();
					setHintFlag(false);
				}
			
		}
		
	} while (clickedItem!=ITM_EXIT); 

	      operation* op = new operExit(this);
		  op->Act();

		  delete op; 
		  op = nullptr;
}




