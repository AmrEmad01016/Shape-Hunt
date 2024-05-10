//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	double hght, wdth;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, double r_hght, double r_wdth);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();



};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	double rad;
public:	
	circle(game* r_pGame, point ref, double r);	//add more parameters for the constructor if needed
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();

};


class EquiTri :public shape
{
	double sidelen;         //side length of the triangle
	double angle = 3.14/2;	
public:
	EquiTri(game* r_pGame, point ref, double r_sidelen);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();


};
