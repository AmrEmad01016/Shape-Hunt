#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 62.5,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = BLACK,			//color used to draw borders/write messages
			fillColor = BLACK,			//shapes fill color (Default)
			bkGrndColor= WHITE ,		//Screen Background color
			statusBarColor = GRAY;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,

	//Sign shape item
	ITM_TREE,
	ITM_HOUSE,
	ITM_KEY,
	ITM_DUMPLE,
	ITM_ARROW,
	ITM_CAR,

	ITM_INCREASE,
	ITM_DECREASE,
	ITM_HINT,
	ITM_LEVELS,
	ITM_REFRESH,
	ITM_ROTATE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_DELETE,
	ITM_EXIT,

	//Exit item
	//TODO: Add more items names here

	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};



