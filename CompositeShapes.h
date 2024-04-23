#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
	double angle=0;
public:
	Sign(game* r_pGame, point ref);
	~Sign();
	virtual void draw() const;
	virtual void rotate();

};


class dumbel :public shape
{
	circle *Rcircle, *Lcircle;
	Rect *handle;
	double angle=0;
public:
	dumbel(game* r_pGame,point ref);
	virtual void draw() const;
	virtual void rotate();


};

class car :public shape {
	circle* frontWheel, * backWheel;
	Rect* lwrBody, * uprBody;
	double angle = 0;
public:
	car(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();

};

class house :public shape {
	Rect* Rbuild, * Lbuild, *Mbuild;
	EquiTri* top;
	double angle=0;
public:
	house(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
};

class key :public shape {
	Rect *main, *square, *Stooth, *Btooth;
	double angle = 0;
public:
	key(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
};

class arrow :public shape {
	Rect* tail;
	EquiTri* head;
	double angle = 3.14/2;
public:
	arrow(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
};

class tree :public shape {
	Rect* root;
	EquiTri* tri1, *tri2, *tri3;
	double angle = 0;
public:
	tree(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
};
