#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};
class addTree :public operation
{
public :
	addTree(game* r_pGame);
	virtual void Act();

};
class addHouse :public operation
{
public:
	addHouse(game* r_pGame);
	virtual void Act();

};
class addKey :public operation
{
public:
	addKey(game* r_pGame);
	virtual void Act();

};
class addArrow :public operation
{
public:
	addArrow(game* r_pGame);
	virtual void Act();

};
class addDumple :public operation
{
public:
	addDumple(game* r_pGame);
	virtual void Act();

};
class addCar :public operation
{
public:
	addCar(game* r_pGame);
	virtual void Act();

};

class operSave :public operation
{
public:
	operSave(game* r_pGame);
	virtual void Act();

};
class operIncrease:public operation
{
public:
	operIncrease(game* r_pGame);
	virtual void Act();

};
class operDecrease:public operation
{
public:
	operDecrease(game* r_pGame);
	virtual void Act();

};

class operHint :public operation
{
public:
	operHint(game* r_pGame);
	virtual void Act();

};
class operLevels :public operation
{
public:
	operLevels(game* r_pGame);
	virtual void Act();

};
class operRefresh :public operation
{
public:
	operRefresh(game* r_pGame);
	virtual void Act();

};
class operRotate :public operation
{
public:
	operRotate(game* r_pGame);
	virtual void Act();

};
class operDelete :public operation
{
public:
	operDelete(game* r_pGame);
	virtual void Act();

};
//class randshap:public operation{
//public:
//	randshap(game* r_pGame);
//	
//};




