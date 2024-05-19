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
	const int type = 0;
public:
	//void calculations();

	double getAngle();
	double getUnitlen();
	int getType();
	Sign(game* r_pGame, point ref);
	~Sign();
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	bool checkboundries() const;
	//void move(int x , int y);
	void save(ofstream& f);
	/*void load(ifstream& f);*/
	//void Match() override;
};


class dumbel :public shape
{
	circle *Rcircle, *Lcircle;
	Rect *handle;
	double angle=0;
	const int type = 1;

public:
	//void calculations();

	double getAngle();
	double getUnitlen();
	int getType();
	dumbel(game* r_pGame,point ref);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	bool checkboundries() const;
	//void move(int x, int y);
	void save(ofstream& f);
	//void load(ifstream& f);
	//void Match() override;

};

class car :public shape {
	circle* frontWheel, * backWheel;
	Rect* lwrBody;
	Rect* uprBody;
	EquiTri* tri1;
	EquiTri* tri2;
	double angle = 0;
	const int type = 2;

public:
	//void calculations();
	double getAngle();
	double getUnitlen();
	int getType();
	car(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	bool checkboundries() const;
	//void move(int x, int y);
	void save(ofstream& f);
	/*void load(ifstream& f);*/
	//void Match() override;

};

class house :public shape {
	Rect* Rbuild, * Lbuild, *Mbuild;
	EquiTri* top;
	double angle=0;
	const int type = 3;

public:
	//void calculations();

	double getAngle();
	double getUnitlen();
	int getType();
	house(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	bool checkboundries() const;
	//void move(int x, int y);
	void save(ofstream& f);
	/*void load(ifstream& f);*/
	//void Match() override;

};

class key :public shape {
	Rect* main;
	circle* hand;
	EquiTri*Stooth, * Btooth;
	double angle = 0;
	const int type = 4;

public:
	//void calculations();

	double getAngle();
	double getUnitlen();
	int getType();
	key(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	//void move(int x, int y);
	void save(ofstream& f);
	/*void load(ifstream& f);*/
	//void Match() override;

};

class arrow :public shape {
	Rect* tail;
	EquiTri* head;
	double angle = 3.14/2;
	const int type = 5;

public:
	//void calculations();

	double getAngle();
	double getUnitlen();
	int getType();
	arrow(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	bool checkboundries() const;

	//void move(int x, int y);
	void save(ofstream& f);
	/*void load(ifstream& f);*/
	//void Match() override;

};

class tree :public shape {
	Rect* root;
	EquiTri* tri1, *tri2, *tri3;
	double angle = 0;
	const int type = 6;

public:
	//void calculations();

	double getAngle();
	double getUnitlen();
	int getType();
	tree(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate();
	virtual void resizeup();
	virtual void resizedown();
	bool checkboundries() const;

	//void move(int x, int y);
	void save(ofstream& f);
	/*void load(ifstream& f);*/
	//void Match() override;

};
