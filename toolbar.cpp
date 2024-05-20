#include "toolbar.h"
#include "game.h"
#include<iostream>

//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	//cout << pGame->gettrails();
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\SIGN.jpg";
	toolbarItemImages[ITM_TREE] = "images\\toolbarItems\\TREE.jpg";
	toolbarItemImages[ITM_HOUSE] = "images\\toolbarItems\\HOUSE.jpg";
	toolbarItemImages[ITM_KEY] = "images\\toolbarItems\\KEY.jpg";
	toolbarItemImages[ITM_DUMPLE] = "images\\toolbarItems\\DUMPLE.jpg";
	toolbarItemImages[ITM_CAR] = "images\\toolbarItems\\CAR.jpg";
	toolbarItemImages[ITM_ARROW] = "images\\toolbarItems\\ARROW.jpg";
	toolbarItemImages[ITM_INCREASE] = "images\\toolbarItems\\INCREASE.jpg";
	toolbarItemImages[ITM_DECREASE] = "images\\toolbarItems\\DECREASE.jpg";
	toolbarItemImages[ITM_HINT] = "images\\toolbarItems\\HINT.jpg";
	toolbarItemImages[ITM_LEVELS] = "images\\toolbarItems\\LEVELS.jpg";
	toolbarItemImages[ITM_REFRESH] = "images\\toolbarItems\\REFRESH.jpg";
	toolbarItemImages[ITM_ROTATE] = "images\\toolbarItems\\ROTATE.jpg";
    toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\SAVE.jpg";
	toolbarItemImages[ITM_LOAD] = "images\\toolbarItems\\LOAD.jpg";
	toolbarItemImages[ITM_DELETE] = "images\\toolbarItems\\DELETE.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\EXIT.jpg";

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
	
	
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE);
	pWind->DrawRectangle(ITM_CNT * config.toolbarItemWidth + 5, 5, config.windWidth,config.toolBarHeight);
	pWind->SetPen(config.penColor, 5);
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->DrawString(ITM_CNT*config.toolbarItemWidth + 5,5,"lives = "+ std::to_string(pG->getlives()));
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth + 5, 20, "score = " + std::to_string(pG->getscores()));
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth + 5, 35, "level = " + std::to_string(pG->getlevels()));


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}


//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

