#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#include <cmath>
using namespace std;

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, double r_hght, double r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}

void Rect::rotate()
{
	int t;
	t=hght;
	hght = wdth;
	wdth = t;
}

void Rect::resizeup()
{
	hght *= 2;
	wdth *= 2;
}
void Rect::resizedown()
{
	hght /= 2;
	wdth /= 2;
}
void Rect::move(int x , int y)
{
	
	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
}

void Rect::save(ofstream& f)
{
}

//void Rect::load(ifstream& f)
//{
//}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, double r):shape(r_pGame,ref)
{
	pGame = r_pGame;
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
	
}

void circle::rotate()
{
}

void circle::resizeup()
{
	rad *= 2;
}
void circle::resizedown()
{
	rad /= 2;
}
void circle::move(int x , int y )
{

	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
}
void circle::save(ofstream& f)
{
}

//void circle::load(ifstream& f)
//{
//
//}




////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here

EquiTri::EquiTri(game* r_pGame, point ref, double r_sidelen):shape(r_pGame, ref)
{
	pGame = r_pGame;
	sidelen = r_sidelen;

}
 
void EquiTri::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	point uppervertex, rightvertex, leftvertex;
	uppervertex.x = RefPoint.x- round(cos(angle)) * (sqrt(3) / 3) * sidelen;
	uppervertex.y = RefPoint.y - round(sin(angle)) *(sqrt(3)/3)*sidelen;
	rightvertex.x = RefPoint.x + round(sin(angle)) *sidelen / 2 + round(cos(angle)) * (sqrt(3) / 6) * sidelen;
	rightvertex.y = RefPoint.y + round(sin(angle)) * (sqrt(3) / 6) * sidelen + round(cos(angle)) * sidelen / 2;
	leftvertex.x = RefPoint.x - round(sin(angle)) * sidelen / 2 + round(cos(angle)) * (sqrt(3) / 6) * sidelen;
	leftvertex.y = RefPoint.y + round(sin(angle)) * (sqrt(3) / 6) * sidelen - round(cos(angle)) * sidelen / 2;

	pW->DrawTriangle(uppervertex.x, uppervertex.y, rightvertex.x, rightvertex.y, leftvertex.x, leftvertex.y);
}

void EquiTri::rotate() {

	angle += 3.14/2;
	
}

void EquiTri::resizeup()
{
	sidelen *= 2;
}
void EquiTri::resizedown()
{
	sidelen /= 2;
}
void EquiTri ::move(int x , int y)
{
	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
}
void EquiTri::save(ofstream& f) {

}

//void EquiTri::load(ifstream& f)
//{
//}
