#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	int top_h = 5 * unitlen, top_w = 10 * unitlen, base_h = 8 * unitlen, base_w = 2 * unitlen;
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + top_h / 2 + base_h / 2 };
	top = new Rect(pGame, topRef, top_h, top_w);
	base = new Rect(pGame, baseRef, base_h, base_w);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

Sign::~Sign()
{
	delete base;
	delete top;
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
}

void dumbel::draw() const
{
	handle->draw();
	Rcircle->draw();
	Lcircle->draw();

}

car::car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int uprbody_s = 5 * unitlen, lwrbody_w = 2 * uprbody_s, wheel_r = unitlen;
	point lwrBodyRef = ref,
		uprBodyRef = { ref.x + unitlen * 3, ref.y - uprbody_s },
		FwheelRef = { ref.x + unitlen * 3, ref.y + uprbody_s/2 },
		BwheelRef = { ref.x - unitlen * 3, ref.y + uprbody_s/2 };
	lwrBody = new Rect(pGame, lwrBodyRef, uprbody_s, lwrbody_w);
	uprBody = new Rect(pGame, uprBodyRef, uprbody_s, uprbody_s);
	frontWheel = new circle(pGame, FwheelRef, wheel_r);
	backWheel = new circle(pGame, BwheelRef, wheel_r);


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
	int build_w = 2 * unitlen, RLbuild_h = 3 * build_w;
	point MbuildRef = ref,
		RbuildRef = { ref.x + build_w, ref.y + build_w },
		LbuildRef = { ref.x - build_w, ref.y + build_w },
		topRef = { ref.x, ref.y - unitlen - (sqrt(3)/6) * (6*unitlen) };

	Mbuild = new Rect(pGame, MbuildRef, build_w, build_w);
	Rbuild = new Rect(pGame, RbuildRef, RLbuild_h, build_w);
	Lbuild = new Rect(pGame, LbuildRef, RLbuild_h, build_w);
	top = new EquiTri(pGame, topRef, RLbuild_h);

}

void house::draw() const
{
	top->draw();
	Rbuild->draw();
	Lbuild->draw();
	Mbuild->draw();

}

key::key(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int square_s = 6 * unitlen, main_h = square_s / 3, main_w = 10 * unitlen;
	point squareRef = ref,
		mainRef = { ref.x +(square_s+ main_w)/2 , ref.y},
		BtoothRef = { ref.x + 8.5 * unitlen + square_s / 2, ref.y + 2 * unitlen },
		StoothRef = { ref.x + 6.5* unitlen+ square_s/2, ref.y + 1.5* unitlen };

	square = new Rect(pGame, squareRef, square_s, square_s);
	main = new Rect(pGame, mainRef, main_h, main_w);
	Btooth = new Rect(pGame, BtoothRef, main_h, unitlen);
	Stooth = new Rect(pGame, StoothRef, unitlen, unitlen);

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
	int root_h = 8 * unitlen, root_w = 2 * unitlen, tri_s = 6 * unitlen;
	point rootRef = ref,
		tri1Ref = { ref.x ,ref.y - root_h / 2 },
		tri2Ref = { ref.x ,ref.y - root_h / 2 + 2*unitlen },
	tri3Ref = { ref.x ,ref.y - root_h / 2 + 4*unitlen };
	root = new Rect(pGame, rootRef, root_h, root_w);
	tri1 = new EquiTri(pGame, tri1Ref, tri_s);
	tri2 = new EquiTri(pGame, tri2Ref, tri_s);
	tri3 = new EquiTri(pGame, tri3Ref, tri_s);




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
	int tail_h = 10 * unitlen, tail_w = 2 * unitlen, head_s = 6 * unitlen;
	point tailRef = ref,
		headRef = { ref.x ,ref.y - tail_h/2 };
	tail = new Rect(pGame, tailRef, tail_h, tail_w);
	head = new EquiTri(pGame, headRef, head_s);
	

}

void arrow::draw() const
{
	tail->draw();
	head->draw();
	//to adam: when you add a rotate function for arrow call it here
}
