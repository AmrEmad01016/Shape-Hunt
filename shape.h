#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;
};

enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign

	//TODO: Add more types
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	double unitlen = 10;    //all dimensions of shapes are calculated related to that unit length
public:
    shape(game* r_pGame, point ref);
    virtual void draw() const=0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	virtual void resizeup()=0;
	virtual void resizedown()=0;
	void setunitlen(int n);
	virtual void move(int x , int y ) =0;
	virtual void save(ofstream &f)=0 ;
	/*virtual void load(ifstream& f) =0;*/
								  
							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	virtual void rotate()=0;	//Rotate the shape

	
	virtual bool checkboundries() const;
	//virtual void resize() = 0;	//Resize the shape
	//virtual void move() = 0;		//Move the shape
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




