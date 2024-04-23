#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + (5*unitlen) / 2 + (8 * unitlen) / 2 };
	top = new Rect(pGame, topRef, (5 * unitlen), (10 * unitlen));
	base = new Rect(pGame, baseRef, (8 * unitlen), (2 * unitlen));
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

//<<<<<<< HEAD
void Sign::rotate() {
	angle += 90;
	point bas = { RefPoint.x + int(cos(angle) * (5 * unitlen) / 2 + (8 * unitlen) / 2),RefPoint.y + int(sin(angle) * (5 * unitlen) / 2 + (8 * unitlen) / 2) };
	base->setRefPoint(bas);
	top->rotate(); base->rotate();

}
//=======
Sign::~Sign()
{
	delete base;
	delete top;
}

//>>>>>>> b63ce68a3d62c72a7a95f68ae46ae2ec2f5c869a

dumbel::dumbel(game* r_pGame, point ref) :shape(r_pGame, ref)
{

	point handleRef = ref;
	point RcircleRef = { ref.x + cos(angle)*6*unitlen / 2 + 3*unitlen, ref.y+sin(angle)* 6 * unitlen / 2 + 3 * unitlen };
	point LcircleRef = { ref.x - cos(angle)*6*unitlen / 2 - 3*unitlen, ref.y - sin(angle) * 6 * unitlen / 2 - 3 * unitlen };
	handle = new Rect(pGame, handleRef, 2*unitlen, 6*unitlen);
	Rcircle = new circle(pGame, RcircleRef, 3*unitlen);
	Lcircle = new circle(pGame, LcircleRef, 3*unitlen);
}
/*I am not sure if this will work*/
void dumbel::draw() const
{
	handle->draw();
	Rcircle->draw();
	Lcircle->draw();

}

void dumbel::rotate()
{
	angle += 90;
	point RcircleRef = { RefPoint.x + cos(angle) * 6 * unitlen / 2 + 3 * unitlen, RefPoint.y + sin(angle) * 6 * unitlen / 2 + 3 * unitlen };
	point LcircleRef = { RefPoint.x - cos(angle) * 6 * unitlen / 2 - 3 * unitlen, RefPoint.y - sin(angle) * 6 * unitlen / 2 - 3 * unitlen };
	Rcircle->setRefPoint(RcircleRef); Lcircle->setRefPoint(LcircleRef);
	handle->rotate();
	
}

car::car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point lwrBodyRef = ref,
		uprBodyRef = { ref.x - unitlen * 3, ref.y - unitlen * 4 },
		FwheelRef = { ref.x + unitlen * 3, ref.y + unitlen * 2 },
		BwheelRef = { ref.x - unitlen * 3, ref.y + unitlen * 2 };
	lwrBody = new Rect(pGame, lwrBodyRef, unitlen * 4, unitlen * 12);
	uprBody = new Rect(pGame, lwrBodyRef, unitlen * 4, unitlen * 6);
	frontWheel = new circle(pGame, FwheelRef, unitlen);
	backWheel = new circle(pGame, BwheelRef, unitlen);


}

void car::draw() const
{
	lwrBody->draw();
	uprBody->draw();
	frontWheel->draw();
	backWheel->draw();

}

house::house(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point MbuildRef = ref,
		RbuildRef = { ref.x + 2 * unitlen, ref.y + 2 * unitlen },
		LbuildRef = { ref.x - 2 * unitlen, ref.y + 2 * unitlen },
		topRef = { ref.x, ref.y - unitlen - (sqrt(3)/6) * (6*unitlen) };

	Mbuild = new Rect(pGame, MbuildRef, 2 * unitlen, 2 * unitlen);
	Rbuild = new Rect(pGame, RbuildRef, 6 * unitlen, 2 * unitlen);
	Lbuild = new Rect(pGame, LbuildRef, 6 * unitlen, 2 * unitlen);
	top = new EquiTri(pGame, topRef, 6 * unitlen);

}

void house::draw() const
{
	top->draw();
	Rbuild->draw();
	Lbuild->draw();
	Mbuild->draw();
//<<<<<<< HEAD
	top->draw();
//=======
//
//>>>>>>> b63ce68a3d62c72a7a95f68ae46ae2ec2f5c869a
}

key::key(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point squareRef = ref,
		mainRef = { ref.x + 9 * unitlen, ref.y },
		BtoothRef = { ref.x + (27 / 2) * unitlen, ref.y + 2 * unitlen },
		StoothRef = { ref.x + (23 / 2) * unitlen, ref.y + (3 / 2) * unitlen };

	square = new Rect(pGame, squareRef, 8 * unitlen, 8 * unitlen);
	main = new Rect(pGame, squareRef, 22 * unitlen, 2 * unitlen);
	Btooth = new Rect(pGame, squareRef, 2 * unitlen, unitlen);
	Stooth = new Rect(pGame, squareRef, unitlen, unitlen);

}

void key::draw() const
{
	square->draw();
	main->draw();
	Btooth->draw();
	Stooth->draw();

}

tree::tree(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point rootRef = ref,
		tri1Ref = { ref.x ,ref.y -  unitlen - (sqrt(3) / 6) *  unitlen },
		tri2Ref = { ref.x ,ref.y - 2 *  unitlen - (sqrt(3) / 6) *  unitlen },
		tri3Ref = { ref.x ,ref.y - unitlen - (sqrt(3) / 6) * unitlen };
	root = new Rect(pGame, rootRef, 2 *  unitlen,  unitlen);
	tri1 = new EquiTri(pGame, tri1Ref, (3/2) *  unitlen);
	tri2 = new EquiTri(pGame, tri2Ref, (3 / 2) *  unitlen);
	tri3 = new EquiTri(pGame, tri3Ref, (3 / 2) *  unitlen);



}

void tree::draw() const
{
	root->draw();
	tri1->draw();
	tri2->draw();
	tri3->draw();

}

arrow::arrow(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point tailRef = ref,
		headRef = { ref.x ,ref.y - unitlen - (sqrt(3) / 6) * unitlen };
	tail = new Rect(pGame, tailRef, 2 * unitlen, unitlen);
	head = new EquiTri(pGame, headRef, (3 / 2) * unitlen);
	

}

void arrow::draw() const
{
	tail->draw();
	head->draw();
	//to adam: when you add a rotate function for arrow call it here
}
