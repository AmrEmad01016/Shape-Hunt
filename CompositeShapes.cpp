#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

dumbel::dumbel(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point handleRef = ref;
	point RcircleRef = { ref.x + config.dumbelShape.handleWdth / 2 + config.dumbelShape.circleRad, ref.y };
	point LcircleRef = { ref.x - config.dumbelShape.handleWdth / 2 - config.dumbelShape.circleRad, ref.y };
	handle = new Rect(pGame, handleRef, config.dumbelShape.handleHeight, config.dumbelShape.handleWdth);
	Rcircle = new circle(pGame, RcircleRef, config.dumbelShape.circleRad);
	Lcircle = new circle(pGame, LcircleRef, config.dumbelShape.circleRad);
}

void dumbel::draw() const
{
	handle->draw();
	Rcircle->draw();
	Lcircle->draw();

}

car::car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int Ulen = config.compositeshape.unitlen;
	point lwrBodyRef = ref,
		uprBodyRef = { ref.x - Ulen * 3, ref.y - Ulen * 4 },
		FwheelRef = { ref.x + Ulen * 3, ref.y + Ulen * 2 },
		BwheelRef = { ref.x - Ulen * 3, ref.y + Ulen * 2 };
	lwrBody = new Rect(pGame, lwrBodyRef, Ulen * 4, Ulen * 12);
	lwrBody = new Rect(pGame, lwrBodyRef, Ulen * 4, Ulen * 6);
	frontWheel = new circle(pGame, FwheelRef, Ulen);
	backWheel = new circle(pGame, BwheelRef, Ulen);


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
	int u = config.compositeshape.unitlen; //half Mbuild side length
	point MbuildRef = ref,
		RbuildRef = { ref.x + 2 * u, ref.y + 2 * u },
		LbuildRef = { ref.x - 2 * u, ref.y + 2 * u },
		topRef = { ref.x, ref.y - u - (sqrt(3) / 6) * u };

	Mbuild = new Rect(pGame, MbuildRef, 2 * u, 2 * u);
	Rbuild = new Rect(pGame, RbuildRef, 4 * u, 2 * u);
	Lbuild = new Rect(pGame, LbuildRef, 4 * u, 2 * u);
	top = new EquiTri(pGame, topRef, 6 * u);

}

void house::draw() const
{
	Rbuild->draw();
	Lbuild->draw();
	Mbuild->draw();
	top->draw();

}

key::key(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int u = config.compositeshape.unitlen; //small tooth length
	point squareRef = ref,
		mainRef = { ref.x + 9 * u, ref.y },
		BtoothRef = { ref.x + (27 / 2) * u, ref.y + 2 * u },
		StoothRef = { ref.x + (23 / 2) * u, ref.y + (3 / 2) * u };

	square = new Rect(pGame, squareRef, 8 * u, 8 * u);
	main = new Rect(pGame, squareRef, 22 * u, 2 * u);
	Btooth = new Rect(pGame, squareRef, 2 * u, u);
	Stooth = new Rect(pGame, squareRef, u, u);

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
	int u = config.compositeshape.unitlen; //root width
	point rootRef = ref,
		tri1Ref = { ref.x ,ref.y - u - (sqrt(3) / 6) * u },
		tri2Ref = { ref.x ,ref.y - 2 * u - (sqrt(3) / 6) * u },
		tri3Ref = { ref.x ,ref.y - 3 * u - (sqrt(3) / 6) * u };
	root = new Rect(pGame, rootRef, 2 * u, u);
	tri1 = new EquiTri(pGame, tri1Ref, (3/2) * u);
	tri2 = new EquiTri(pGame, tri2Ref, (3 / 2) * u);
	tri3 = new EquiTri(pGame, tri3Ref, (3 / 2) * u);



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
	int u = config.compositeshape.unitlen; //root width
	point tailRef = ref,
		headRef = { ref.x ,ref.y - u - (sqrt(3) / 6) * u };
	tail = new Rect(pGame, tailRef, 2 * u, u);
	head = new EquiTri(pGame, headRef, (3 / 2) * u);
	

}

void arrow::draw() const
{
	tail->draw();
	head->draw();
	//to adam: when you add a rotate function for arrow call it here
}
