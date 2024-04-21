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
	int angle;
public:
	Sign(game* r_pGame, point ref);
	~Sign();
	virtual void draw() const;
	void rotate();

};


class dumbel :public shape
{
	circle *Rcircle, *Lcircle;
	Rect *handle;
public:
	dumbel(game* r_pGame,point ref);
	virtual void draw() const;



};

class car :public shape {
	circle* frontWheel, * backWheel;
	Rect* lwrBody, * uprBody;
public:
	car(game* r_pGame, point ref);
	virtual void draw() const;

};

class house :public shape {
	Rect* Rbuild, * Lbuild, *Mbuild;
	EquiTri* top;
public:
	house(game* r_pGame, point ref);
	virtual void draw() const;
};

class key :public shape {
	Rect *main, *square, *Stooth, *Btooth;
public:
	key(game* r_pGame, point ref);
	virtual void draw() const;
};

class arrow :public shape {
	Rect* tail;
	EquiTri* head;
public:
	arrow(game* r_pGame, point ref);
	virtual void draw() const;
};

class tree :public shape {
	Rect* root;
	EquiTri* tri1, *tri2, *tri3;
public:
	tree(game* r_pGame, point ref);
	virtual void draw() const;
};
