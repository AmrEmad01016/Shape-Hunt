#include "CompositeShapes.h"
#include "gameConfig.h"
#include <fstream>
#include "grid.h"
#include "game.h"


double Sign::getAngle()
{
	return angle;
}

double Sign::getUnitlen()
{
	return unitlen;
}

int Sign::getType()
{
	return type;
}

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	int top_h = 5 * unitlen, top_w = 10 * unitlen, base_h = 8 * unitlen, base_w = 2 * unitlen;
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + top_h / 2 + base_h / 2 };
	top = new Rect(pGame, topRef, top_h, top_w);
	base = new Rect(pGame, baseRef, base_h, base_w);

	maxy = 10.5 * unitlen;
}

void Sign::draw() const
{
	int top_h = 5 * unitlen, top_w = 10 * unitlen, base_h = 8 * unitlen, base_w = 2 * unitlen;
	base->setRefPoint({ RefPoint.x - int(round(sin(angle)) * (top_h / 2 + base_h / 2)),RefPoint.y + int(round(cos(angle)) * (top_h / 2 + base_h / 2)) });
	top->setRefPoint(RefPoint);
	base->draw();
	top->draw();
}

//<<<<<<< HEAD
void Sign::rotate() {
	angle += 3.14/2;
	int top_h = 5 * unitlen, base_h = 8 * unitlen;

	point bas = { RefPoint.x - int(round(sin(angle)) * (top_h / 2 + base_h / 2)),RefPoint.y + int(round(cos(angle)) * (top_h / 2 + base_h / 2)) };
	base->setRefPoint(bas);
	top->rotate(); base->rotate();


}
void Sign::resizeup()
{
	unitlen *= 2;
	if (!Sign::checkboundries())
	{
		unitlen /= 2;
		return;
	}

	int top_h = 5 * unitlen, base_h = 8 * unitlen;

	base->setRefPoint({ RefPoint.x - int(round(sin(angle)) * (top_h / 2 + base_h / 2)),RefPoint.y + int(round(cos(angle)) * (top_h / 2 + base_h / 2)) });
	base->resizeup(); top->resizeup();
}
void Sign::resizedown()
{
	unitlen /= 2;
	int top_h = 5 * unitlen, base_h = 8 * unitlen;

	base->setRefPoint({ RefPoint.x - int(round(sin(angle)) * (top_h / 2 + base_h / 2)),RefPoint.y + int(round(cos(angle)) * (top_h / 2 + base_h / 2)) });
	base->resizedown(); top->resizedown();

	maxy = 10.5 * unitlen;
}
bool Sign::checkboundries() 
{
	 maxy = 10.5 * unitlen;

	if (RefPoint.y < 60 + maxy || RefPoint.y > config.windHeight -80 - maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	else return true;


}

void Sign::setcolor(int r, int g, int b)
{
	rc = r; gc = g; bc = b;

	top->setcolor(r, g, b);

	base->setcolor(r, g, b);
}

//void Sign::move(int x, int y)
//{
//	
//	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
//
//}


//void Sign::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes(); 
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//	
//}

//void Sign::load(ifstream& f)
//{
//}


//=======
Sign::~Sign()
{
	delete base;
	delete top;
}

//>>>>>>> b63ce68a3d62c72a7a95f68ae46ae2ec2f5c869a

double dumbel::getAngle()
{
	return angle;
}

double dumbel::getUnitlen()
{
	return unitlen;
}

int dumbel::getType()
{
	return type;
}

dumbel::dumbel(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int handle_h = 2 * unitlen, handle_w = 8 * unitlen, circle_r = 3 * unitlen;
	point handleRef = ref;
	point RcircleRef = { ref.x + handle_w / 2 , ref.y };
	point LcircleRef = { ref.x - handle_w / 2 , ref.y };
	handle = new Rect(pGame, handleRef, handle_h, 6*unitlen);
	Rcircle = new circle(pGame, RcircleRef, circle_r);
	Lcircle = new circle(pGame, LcircleRef, circle_r);

	maxy = 7 * unitlen;

}

dumbel::~dumbel()
{
	delete handle;
	delete Rcircle;
	delete Lcircle;

}

void dumbel::draw() const
{
	int handle_h = 2 * unitlen, handle_w = 8 * unitlen, circle_r = 3 * unitlen;
	handle->setRefPoint(RefPoint);
	Rcircle->setRefPoint({ RefPoint.x + round(cos(angle)) * handle_w / 2 , RefPoint.y + round(sin(angle)) * handle_w / 2 });
	Lcircle->setRefPoint({ RefPoint.x - round(cos(angle)) * handle_w / 2 , RefPoint.y - round(sin(angle)) * handle_w / 2 });

	handle->draw();
	Rcircle->draw();
	Lcircle->draw();

}

void dumbel::rotate()
{
	angle += 3.14 / 2;
	int handle_w = 8 * unitlen;
	point RcircleRef = { RefPoint.x + round(cos(angle)) * handle_w / 2 , RefPoint.y + round(sin(angle)) * handle_w / 2 };
	point LcircleRef = { RefPoint.x - round(cos(angle)) * handle_w / 2 , RefPoint.y - round(sin(angle)) * handle_w / 2 };
	Rcircle->setRefPoint(RcircleRef); Lcircle->setRefPoint(LcircleRef);
	handle->rotate();
	
}

void dumbel::resizeup()
{
	unitlen *= 2;
	int handle_w = 8 * unitlen;

	if (!dumbel::checkboundries())
	{
		unitlen /= 2;
		return;
	}

	point RcircleRef = { RefPoint.x + round(cos(angle)) * handle_w / 2 , RefPoint.y + round(sin(angle)) * handle_w / 2 };
	point LcircleRef = { RefPoint.x - round(cos(angle)) * handle_w / 2 , RefPoint.y - round(sin(angle)) * handle_w / 2 };
	Rcircle->setRefPoint(RcircleRef); Lcircle->setRefPoint(LcircleRef);

	Rcircle->resizeup(); Lcircle->resizeup(); handle->resizeup();

}

void dumbel::resizedown()
{
	unitlen /= 2;
	int handle_w = 8 * unitlen;

	point RcircleRef = { RefPoint.x + round(cos(angle)) * handle_w / 2 , RefPoint.y + round(sin(angle)) * handle_w / 2 };
	point LcircleRef = { RefPoint.x - round(cos(angle)) * handle_w / 2 , RefPoint.y - round(sin(angle)) * handle_w / 2 };
	Rcircle->setRefPoint(RcircleRef); Lcircle->setRefPoint(LcircleRef);

	Rcircle->resizedown(); Lcircle->resizedown(); handle->resizedown();

	maxy = 7 * unitlen;
}

bool dumbel::checkboundries() 
{
	 maxy = 7*unitlen;

	if (RefPoint.y < 60 + maxy || RefPoint.y > config.windHeight -80- maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	else return true;

	
}

void dumbel::setcolor(int r, int g, int b)
{

	rc = r; gc = g; bc = b;

	Rcircle->setcolor(r, g, b);
	Lcircle->setcolor(r, g, b);
	handle->setcolor(r, g, b);
}

//void dumbel::move(int x, int y)
//{
//	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
//}



//void dumbel::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes();
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//}


//void dumbel::load(ifstream& f)
//{
//}




double car::getAngle()
{
	return angle;
}

double car::getUnitlen()
{
	return unitlen;
}

int car::getType()
{
	return 2;
}


car::car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	maxy = 5 * unitlen;

	unitlen *= 1.5;
	int uprbody_h = 2 * unitlen, lwrbody_w = 5 * uprbody_h, uprbody_w = lwrbody_w / 2, wheel_r = unitlen;
	point lwrBodyRef = ref,
		uprBodyRef = { ref.x , ref.y - uprbody_h },
		FwheelRef = { ref.x + unitlen * 3, ref.y + uprbody_h / 2 },
		BwheelRef = { ref.x - unitlen * 3, ref.y + uprbody_h / 2 },
		Tri1 = { ref.x + uprbody_w / 2,ref.y - ((3 + sqrt(3)) / 6) * uprbody_h },
		Tri2 = { ref.x - uprbody_w / 2,ref.y - ((3 + sqrt(3)) / 6) * uprbody_h };
	lwrBody = new Rect(pGame, lwrBodyRef, uprbody_h, lwrbody_w);
	uprBody = new Rect(pGame, uprBodyRef, uprbody_h, uprbody_w);
	frontWheel = new circle(pGame, FwheelRef, wheel_r);
	backWheel = new circle(pGame, BwheelRef, wheel_r);
	tri1 = new EquiTri(pGame,Tri1,uprbody_h* (2/sqrt(3)));
	tri2= new EquiTri(pGame, Tri2, uprbody_h * (2 / sqrt(3)));


}

car::~car()
{
	delete lwrBody;
	delete uprBody;
	delete frontWheel;
	delete backWheel;
	delete tri1;
	delete tri2;
}

void car::draw() const
{
	int uprbody_h = 2 * unitlen, lwrbody_w = 5 * uprbody_h, uprbody_w = lwrbody_w / 2, wheel_r = unitlen;
	uprBody->setRefPoint({ RefPoint.x + int(round(sin(angle))) * uprbody_h ,RefPoint.y - int(round(cos(angle))) * uprbody_h });
	frontWheel->setRefPoint({ RefPoint.x + int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle)) * uprbody_h / 2),RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) + int(round(sin(angle)) * unitlen * 3) });
	backWheel->setRefPoint({ RefPoint.x - int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle)) * uprbody_h / 2),RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) - int(round(sin(angle)) * unitlen * 3) });
	tri1->setRefPoint({ RefPoint.x + int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h), RefPoint.y + int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });
	tri2->setRefPoint({ RefPoint.x - int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h),RefPoint.y - int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });
	lwrBody->setRefPoint(RefPoint);

	lwrBody->draw();
	uprBody->draw();
	frontWheel->draw();
	backWheel->draw();
	tri1->draw();
	tri2->draw();

	

}

void car::rotate()
{
	angle += 3.14 / 2; 
	int uprbody_h = 2 * unitlen, lwrbody_w = 5 * uprbody_h, uprbody_w = lwrbody_w / 2, wheel_r = unitlen;

	lwrBody->setRefPoint(RefPoint);
	uprBody->setRefPoint({ RefPoint.x + int(round(sin(angle))) * uprbody_h ,RefPoint.y - int(round(cos(angle))) * uprbody_h });
	frontWheel->setRefPoint({ RefPoint.x + int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle))) * uprbody_h / 2,RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) + int(round(sin(angle)) * unitlen * 3) });
	backWheel->setRefPoint({ RefPoint.x - int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle))) * uprbody_h / 2,RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) - int(round(sin(angle)) * unitlen * 3) });
	tri1->setRefPoint({ RefPoint.x + int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle))*((3 + sqrt(3)) / 6) * uprbody_h), RefPoint.y + int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });
	tri2->setRefPoint({ RefPoint.x - int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h),RefPoint.y - int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });

	lwrBody->rotate(); uprBody->rotate(); tri1->rotate(); tri2->rotate();
}

void car::resizeup()
{
	unitlen *= 2;

	if (!car::checkboundries())
	{
		unitlen /= 2;
		return;
	}

	int uprbody_h = 2 * unitlen, lwrbody_w = 5 * uprbody_h, uprbody_w = lwrbody_w / 2, wheel_r = unitlen;


	uprBody->setRefPoint({ RefPoint.x + int(round(sin(angle))) * uprbody_h ,RefPoint.y - int(round(cos(angle))) * uprbody_h });
	frontWheel->setRefPoint({ RefPoint.x + int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle)) * uprbody_h / 2),RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) + int(round(sin(angle)) * unitlen * 3) });
	backWheel->setRefPoint({ RefPoint.x - int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle)) * uprbody_h / 2),RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) - int(round(sin(angle)) * unitlen * 3) });
	tri1->setRefPoint({ RefPoint.x + int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h), RefPoint.y + int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });
	tri2->setRefPoint({ RefPoint.x - int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h),RefPoint.y - int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });

	uprBody->resizeup(); lwrBody->resizeup(); backWheel->resizeup(); frontWheel->resizeup(); tri1->resizeup(); tri2->resizeup();

	maxy = 5 * unitlen;
}

void car::resizedown()
{
	unitlen /= 2;

	int uprbody_h = 2 * unitlen, lwrbody_w = 5 * uprbody_h, uprbody_w = lwrbody_w / 2, wheel_r = unitlen;


	uprBody->setRefPoint({ RefPoint.x + int(round(sin(angle))) * uprbody_h ,RefPoint.y - int(round(cos(angle))) * uprbody_h });
	frontWheel->setRefPoint({ RefPoint.x + int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle)) * uprbody_h / 2),RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) + int(round(sin(angle)) * unitlen * 3) });
	backWheel->setRefPoint({ RefPoint.x - int(round(cos(angle)) * unitlen * 3) - int(round(sin(angle)) * uprbody_h / 2),RefPoint.y + int(round(cos(angle)) * uprbody_h / 2) - int(round(sin(angle)) * unitlen * 3) });
	tri1->setRefPoint({ RefPoint.x + int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h), RefPoint.y + int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });
	tri2->setRefPoint({ RefPoint.x - int(round(cos(angle)) * uprbody_w / 2) + int(round(sin(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h),RefPoint.y - int(round(sin(angle)) * uprbody_w / 2) - int(round(cos(angle)) * ((3 + sqrt(3)) / 6) * uprbody_h) });


	uprBody->resizedown(); lwrBody->resizedown(); backWheel->resizedown(); frontWheel->resizedown(); tri1->resizedown(); tri2->resizedown();

	maxy = 5 * unitlen;
}

bool car::checkboundries() 
{
	 maxy = 5 * unitlen;

	if (RefPoint.y < 60 + maxy || RefPoint.y > config.windHeight -80- maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	else return true;

	return false;
}

void car::setcolor(int r, int g, int b)
{
	rc = r; gc = g; bc = b;

	uprBody->setcolor(r, g, b);
	frontWheel->setcolor(r, g, b);
	backWheel->setcolor(r, g, b);
	lwrBody->setcolor(r, g, b);
	tri1->setcolor(r, g, b);
	tri2->setcolor(r, g, b);


}

//void car::move(int x, int y)
//{
//	
//	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
//}


//void car::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes();
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//}



//void car::load(ifstream& f)
//{
//}

double house::getAngle()
{
	return angle;
}

double house::getUnitlen()
{
	return unitlen;
}

int house::getType()
{
	return type;
}

house::house(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int build_w = 2 * unitlen, RLbuild_h = 3 * build_w;
	point MbuildRef = ref,
		RbuildRef = { ref.x + build_w, ref.y + build_w },
		LbuildRef = { ref.x - build_w, ref.y + build_w },
		topRef = { ref.x, ref.y - unitlen - (sqrt(3)/6) * (6*unitlen) };

	Mbuild = new Rect(pGame, MbuildRef, build_w, build_w);
	Rbuild = new Rect(pGame, RbuildRef, RLbuild_h, build_w);
	Lbuild = new Rect(pGame, LbuildRef, RLbuild_h, build_w);
	top = new EquiTri(pGame, topRef, RLbuild_h);

	maxy = (1 + 3 * sqrt(3)) * unitlen;
}

house::~house()
{
	delete Mbuild;
	delete Rbuild;
	delete Lbuild;
	delete top;
}

void house::draw() const
{
	int build_w = 2 * unitlen, RLbuild_h = 3 * build_w;
	top->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))),RefPoint.y - int(round(cos(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))) });
	Rbuild->setRefPoint({ RefPoint.x + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) + int(round(sin(angle)) * build_w) });
	Lbuild->setRefPoint({ RefPoint.x - int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w) });
	Mbuild->setRefPoint(RefPoint);
	top->draw();
	Rbuild->draw();
	Lbuild->draw();
	Mbuild->draw();
}

void house::rotate()
{
	angle += 3.14 / 2;

	int build_w = 2 * unitlen;
	top->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))),RefPoint.y - int(round(cos(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))) });
	Rbuild->setRefPoint({ RefPoint.x + int(round(cos(angle)) * build_w)-int(round(sin(angle))*build_w), RefPoint.y + int(round(cos(angle)) * build_w) + int(round(sin(angle)) * build_w) });
	Lbuild->setRefPoint({ RefPoint.x - int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w) });
	top->rotate(); Rbuild->rotate(); Lbuild->rotate();
}

void house::resizeup()
{
	unitlen *= 2;

	if (!house::checkboundries())
	{
		unitlen /= 2;
		return;
	}

	int build_w = 2 * unitlen;
	top->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))),RefPoint.y - int(round(cos(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))) });
	Rbuild->setRefPoint({ RefPoint.x + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) + int(round(sin(angle)) * build_w) });
	Lbuild->setRefPoint({ RefPoint.x - int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w) });

	top->resizeup(); Rbuild->resizeup(); Lbuild->resizeup(); Mbuild->resizeup();


}

void house::resizedown()
{
	unitlen /= 2;

	int build_w = 2 * unitlen;
	top->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))),RefPoint.y - int(round(cos(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))) });
	Rbuild->setRefPoint({ RefPoint.x + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) + int(round(sin(angle)) * build_w) });
	Lbuild->setRefPoint({ RefPoint.x - int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w) });

	top->resizedown(); Rbuild->resizedown(); Lbuild->resizedown(); Mbuild->resizedown();

	maxy = (1 + 3 * sqrt(3)) * unitlen;
}

bool house::checkboundries() 
{

	 maxy = (1+3*sqrt(3))*unitlen;

	if (RefPoint.y < 60+maxy || RefPoint.y > config.windHeight -80- maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	else return true;

	return false;
}

void house::setcolor(int r, int g, int b)
{
	rc = r; gc = g; bc = b;

	top->setcolor(r, g, b);
	Rbuild->setcolor(r, g, b);
	Lbuild->setcolor(r, g, b);
	Mbuild->setcolor(r, g, b);
}

//void house::move(int x, int y)
//{
//	RefPoint.x = RefPoint.x + x;
//	RefPoint.y = RefPoint.y + y;
//}



//void house::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes();
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//}



//void house::load(ifstream& f)
//{
//}

double key::getAngle()
{
	return angle;
}

double key::getUnitlen()
{
	return unitlen;
}

int key::getType()
{
	return type;
}

key::key(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	unitlen /= 1.5;

	

	int circle_r = 6 * unitlen, main_h = circle_r/3, main_w = 20 * unitlen;
	point handRef = ref,
		mainRef = { ref.x +(circle_r+ main_w)/2 , ref.y},
		BtoothRef = { ref.x + 2*8.5 * unitlen + circle_r / 2, ref.y + 2 * unitlen },
		StoothRef = { ref.x + 2*6.5* unitlen+ circle_r/2,ref.y + 2 * unitlen };

	hand = new circle(pGame, handRef, circle_r);
	main = new Rect(pGame, mainRef, main_h, main_w);
	Btooth = new EquiTri(pGame, BtoothRef,  unitlen/(sqrt(3)/6));
	Stooth = new EquiTri(pGame, StoothRef,  unitlen / (sqrt(3) / 6));

	maxy = 26 * unitlen;
}

key::~key()
{
	delete hand;
	delete main;
	delete Btooth;
	delete Stooth;

}

void key::draw() const
{
	int circle_r = 6 * unitlen, main_h = circle_r / 3, main_w = 20 * unitlen;
	hand->setRefPoint(RefPoint);
	main->setRefPoint({ RefPoint.x + int(round(cos(angle))) * (circle_r + main_w) / 2,RefPoint.y + int(round(sin(angle))) * (circle_r + main_w) / 2 });
	Stooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2 * 6.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) * (2 * 6.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });
	Btooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2 * 8.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) * (2 * 8.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });

	hand->draw();
	main->draw();
	Btooth->draw();
	Stooth->draw();
	


}

void key::rotate()
{
	angle += 3.14 / 2;
	int circle_r = 6 * unitlen, main_w = 20 * unitlen;
	
	main->setRefPoint({ RefPoint.x + int(round(cos(angle))) * (circle_r + main_w) / 2,RefPoint.y+int(round(sin(angle)))* (circle_r + main_w) / 2 });
	Stooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2* 6.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) *( 2*6.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });
	Btooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2* 8.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) *( 2*8.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });

	main->rotate(); Btooth->rotate(); Stooth->rotate();
}

void key::resizeup()
{
	unitlen *= 2;

	if (!key::checkboundries()) {
		unitlen /= 2;
		return;
	}

	int circle_r = 6 * unitlen, main_w = 20 * unitlen;

	main->setRefPoint({ RefPoint.x + int(round(cos(angle))) * (circle_r + main_w) / 2,RefPoint.y + int(round(sin(angle))) * (circle_r + main_w) / 2 });
	Stooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2 * 6.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) * (2 * 6.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });
	Btooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2 * 8.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) * (2 * 8.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });

	main->resizeup(); Btooth->resizeup(); Stooth->resizeup(); hand->resizeup();
}

void key::resizedown()
{
	unitlen /= 2;

	int circle_r = 6 * unitlen, main_w = 20 * unitlen;

	main->setRefPoint({ RefPoint.x + int(round(cos(angle))) * (circle_r + main_w) / 2,RefPoint.y + int(round(sin(angle))) * (circle_r + main_w) / 2 });
	Stooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2 * 6.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) * (2 * 6.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });
	Btooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (2 * 8.5 * unitlen + circle_r / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) * (2 * 8.5 * unitlen + circle_r / 2)) + int(round(cos(angle)) * 2 * unitlen) });

	main->resizedown(); Btooth->resizedown(); Stooth->resizedown(); hand->resizedown();

	maxy = 26 * unitlen;
}

void key::setcolor(int r, int g, int b)
{
	rc = r; gc = g; bc = b;
	main->setcolor(r, g, b);
	Stooth->setcolor(r, g, b);
	Btooth->setcolor(r, g, b);
	hand->setcolor(r, g, b);
}

bool key::checkboundries()
{
	maxy = 26 * unitlen;

	if (RefPoint.y < 60 + maxy || RefPoint.y > config.windHeight-80 - maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	else return true;
}

//void key::move(int x, int y)
//{
//	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
//}



//void key::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes();
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//}



//void key::load(ifstream& f)
//{
//}

double tree::getAngle()
{
	return angle;
}

double tree::getUnitlen()
{
	return unitlen;
}

int tree::getType()
{
	return type;
}

tree::tree(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int root_h = 8 * unitlen, root_w = 2 * unitlen, tri_s = 6 * unitlen;
	point rootRef = ref,
		tri1Ref = { ref.x ,ref.y - root_h / 2 },
		tri2Ref = { ref.x ,ref.y - root_h / 2 + 2*unitlen },
	tri3Ref = { ref.x ,ref.y - root_h / 2 + 4*unitlen };
	root = new Rect(pGame, rootRef, root_h, root_w);
	tri1 = new EquiTri(pGame, tri1Ref, tri_s);
	tri2 = new EquiTri(pGame, tri2Ref, tri_s);
	tri3 = new EquiTri(pGame, tri3Ref, tri_s);


	maxy = (4 + 2 * sqrt(3)) * unitlen;

}

tree::~tree()
{
	delete root;
	delete tri1;
	delete tri2;
	delete tri3;

}

void tree::draw() const
{
	int root_h = 8 * unitlen, root_w = 2 * unitlen, tri_s = 6 * unitlen;
	root->setRefPoint(RefPoint);
	tri1->setRefPoint({ RefPoint.x + int(round(sin(angle))) * root_h / 2 ,RefPoint.y - int(round(cos(angle))) * root_h / 2 });
	tri2->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 2 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 2 * unitlen)) });
	tri3->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 4 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 4 * unitlen)) });

	root->draw();
	tri1->draw();
	tri2->draw();
	tri3->draw();

}

void tree::rotate()
{
	angle += 3.14 / 2;
	int root_h = 8 * unitlen;

	tri1->setRefPoint({ RefPoint.x + int(round(sin(angle))) * root_h / 2 ,RefPoint.y - int(round(cos(angle))) * root_h / 2 });
	tri2->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 2 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 2 * unitlen)) });
	tri3->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 4 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 4 * unitlen)) });
	root->rotate(); tri1->rotate(); tri2->rotate(); tri3->rotate();

}

void tree::resizeup()
{
	unitlen *= 2;

	if (!tree::checkboundries())
	{
		unitlen /= 2;
		return;
	}

	int root_h = 8 * unitlen;

	tri1->setRefPoint({ RefPoint.x + int(round(sin(angle))) * root_h / 2 ,RefPoint.y - int(round(cos(angle))) * root_h / 2 });
	tri2->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 2 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 2 * unitlen)) });
	tri3->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 4 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 4 * unitlen)) });

	root->resizeup(); tri1->resizeup(); tri2->resizeup(); tri3->resizeup();
	
}

void tree::resizedown()
{
	unitlen /= 2;

	int root_h = 8 * unitlen;

	tri1->setRefPoint({ RefPoint.x + int(round(sin(angle))) * root_h / 2 ,RefPoint.y - int(round(cos(angle))) * root_h / 2 });
	tri2->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 2 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 2 * unitlen)) });
	tri3->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (root_h / 2 - 4 * unitlen)) ,RefPoint.y - int(round(cos(angle)) * (root_h / 2 - 4 * unitlen)) });

	root->resizedown(); tri1->resizedown(); tri2->resizedown(); tri3->resizedown();

	maxy = (4 + 2 * sqrt(3)) * unitlen;
}

bool tree::checkboundries() 
{
	 maxy = (4 + 2 * sqrt(3)) * unitlen;

	 if (RefPoint.y < 60 + maxy || RefPoint.y > config.windHeight-80 - maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	 else return true;

	
}

void tree::setcolor(int r, int g, int b)
{
	rc = r; gc = g; bc = b;

	root->setcolor(r, g, b);
	tri1->setcolor(r, g, b);
	tri2->setcolor(r, g, b);
	tri3->setcolor(r, g, b);
}

//void tree::move(int x, int y)
//{
//	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
//}



//void tree::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes();
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//}



//void tree::load(ifstream& f)
//{
//}

double arrow::getAngle()
{
	return angle;
}

double arrow::getUnitlen()
{
	return unitlen;
}

int arrow::getType()
{
	return type;
}

arrow::arrow(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int tail_h = 10 * unitlen, tail_w = 2 * unitlen, head_s = 6 * unitlen;
	point tailRef = ref,
		headRef = { ref.x + tail_h/2 ,ref.y  };
	tail = new Rect(pGame, tailRef, tail_h, tail_w);
	head = new EquiTri(pGame, headRef, head_s);
	head->rotate();
	tail->rotate();
	
	maxy = (5 + sqrt(3) * 2) * unitlen;

}

arrow::~arrow()
{
	delete tail;
	delete head;
}

void arrow::draw() const
{
	int tail_h = 10 * unitlen, tail_w = 2 * unitlen, head_s = 6 * unitlen;
	tail->setRefPoint(RefPoint);
	head->setRefPoint({ RefPoint.x + int(round(sin(angle))) * tail_h / 2,RefPoint.y - int(round(cos(angle))) * tail_h / 2 });
	tail->draw();
	head->draw();
	//to adam: when you add a rotate function for arrow call it here
}

void arrow::rotate()
{
	angle += 3.14/2;
	int tail_h = 10 * unitlen;

	head->setRefPoint({ RefPoint.x + int(round(sin(angle))) * tail_h / 2,RefPoint.y - int(round(cos(angle))) * tail_h / 2 });
	head->rotate(); tail->rotate();
}

void arrow::resizeup()
{
	unitlen *= 2;

	if (!arrow::checkboundries())
	{
		unitlen /= 2;
		return;
	}

	int tail_h = 10 * unitlen;

	head->setRefPoint({ RefPoint.x + int(round(sin(angle))) * tail_h / 2,RefPoint.y - int(round(cos(angle))) * tail_h / 2 });

	head->resizeup(); tail->resizeup();
}

void arrow::resizedown()
{
	unitlen /= 2;

	int tail_h = 10 * unitlen;

	head->setRefPoint({ RefPoint.x + int(round(sin(angle))) * tail_h / 2,RefPoint.y - int(round(cos(angle))) * tail_h / 2 });

	head->resizedown(); tail->resizedown();

	maxy = (5 + sqrt(3) * 2) * unitlen;
}

bool arrow::checkboundries() 
{
	 maxy = (5 + sqrt(3) * 2) * unitlen;

	if (RefPoint.y < 60+maxy || RefPoint.y > config.windHeight-80 - maxy || RefPoint.x < maxy || RefPoint.x > config.windWidth - maxy) return false;

	else return true;

	return true;
}

void arrow::setcolor(int r, int g, int b)
{
	rc = r; gc = g; bc = b;

	head->setcolor(r, g, b);
	tail->setcolor(r, g, b);
}

//void arrow::move(int x, int y)
//{
//	setRefPoint({ RefPoint.x + x, RefPoint.y + y });
//}


//void arrow::Match()
//{
//	grid* pGrid = pGame->getGrid();
//	int shapeCount = pGrid->getshapecount();
//	shape** shapeList = pGrid->getRandShapes();
//	for (int i = 0; i < shapeCount; i++) {
//		int T = shapeList[i]->getType();
//		double size = shapeList[i]->getUnitlen(), A = shapeList[i]->getAngle();
//
//		if (type == T && unitlen == size && angle == A) {
//			pGame->changeScore(2);
//			delete shapeList[i];
//			pGrid->deleteActiveShape();
//		}
//		else pGame->changeScore(-1);
//	}
//}



//void arrow::load(ifstream& f)
//{
//}
