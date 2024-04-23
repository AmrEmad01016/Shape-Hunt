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

//<<<<<<< HEAD
void Sign::rotate() {
	angle += 3.14/2;
	int top_h = 5 * unitlen, base_h = 8 * unitlen;

	point bas = { RefPoint.x - int(round(sin(angle)) * (top_h / 2 + base_h / 2)),RefPoint.y + int(round(cos(angle)) * (top_h / 2 + base_h / 2)) };
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

void dumbel::rotate()
{
	angle += 3.14 / 2;
	int handle_w = 8 * unitlen;
	point RcircleRef = { RefPoint.x + round(cos(angle)) * handle_w / 2 , RefPoint.y + round(sin(angle)) * handle_w / 2 };
	point LcircleRef = { RefPoint.x - round(cos(angle)) * handle_w / 2 , RefPoint.y - round(sin(angle)) * handle_w / 2 };
	Rcircle->setRefPoint(RcircleRef); Lcircle->setRefPoint(LcircleRef);
	handle->rotate();
	
}

car::car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	unitlen *= 1.5;
	int uprbody_h = 2 * unitlen, lwrbody_w = 5 * uprbody_h,uprbody_w = lwrbody_w/2,  wheel_r = unitlen;
	point lwrBodyRef = ref,
		uprBodyRef = { ref.x , ref.y - uprbody_h },
		FwheelRef = { ref.x + unitlen * 3, ref.y + uprbody_h/2 },
		BwheelRef = { ref.x - unitlen * 3, ref.y + uprbody_h/2 };
	lwrBody = new Rect(pGame, lwrBodyRef, uprbody_h, lwrbody_w);
	uprBody = new Rect(pGame, uprBodyRef, uprbody_h, uprbody_w);
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

void car::rotate()
{
	angle += 3.14 / 2; 
	int uprbody_h = 2 * unitlen;
	uprBody->setRefPoint({ RefPoint.x + int(round(sin(angle))) * uprbody_h ,RefPoint.y - int(round(cos(angle))) * uprbody_h });
	frontWheel->setRefPoint({ RefPoint.x + int(round(cos(angle))) * unitlen * 3 - int(round(sin(angle))) * uprbody_h / 2,RefPoint.y + int(round(cos(angle))) * uprbody_h / 2 + int(round(sin(angle))) * unitlen * 3 });
	backWheel->setRefPoint({ RefPoint.x - int(round(cos(angle))) * unitlen * 3 - int(round(sin(angle))) * uprbody_h / 2,RefPoint.y + int(round(cos(angle))) * uprbody_h / 2 - int(round(sin(angle))) * unitlen * 3 });
	
	lwrBody->rotate(); uprBody->rotate();
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

void house::rotate()
{
	angle += 3.14 / 2;

	int build_w = 2 * unitlen;
	top->setRefPoint({ RefPoint.x + int(round(sin(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))),RefPoint.y - int(round(cos(angle)) * (unitlen + (sqrt(3) / 6) * (6 * unitlen))) });
	Rbuild->setRefPoint({ RefPoint.x + int(round(cos(angle)) * build_w)-int(round(sin(angle))*build_w), RefPoint.y + int(round(cos(angle)) * build_w) + int(round(sin(angle)) * build_w) });
	Lbuild->setRefPoint({ RefPoint.x - int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w), RefPoint.y + int(round(cos(angle)) * build_w) - int(round(sin(angle)) * build_w) });
	top->rotate(); Rbuild->rotate(); Lbuild->rotate();
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

void key::rotate()
{
	angle += 3.14 / 2;
	int square_s = 6 * unitlen, main_w = 10 * unitlen;
	
	main->setRefPoint({ RefPoint.x + int(round(cos(angle))) * (square_s + main_w) / 2,RefPoint.y+int(round(sin(angle)))* (square_s + main_w) / 2 });
	Stooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) *( 6.5 * unitlen + square_s / 2)) - int(round(sin(angle)) * 1.5 * unitlen),RefPoint.y + int(round(sin(angle)) *( 6.5 * unitlen + square_s / 2)) + int(round(cos(angle)) * 1.5 * unitlen) });
	Btooth->setRefPoint({ RefPoint.x + int(round(cos(angle)) * (8.5 * unitlen + square_s / 2)) - int(round(sin(angle)) * 2 * unitlen),RefPoint.y + int(round(sin(angle)) *( 8.5 * unitlen + square_s / 2)) + int(round(cos(angle)) * 2 * unitlen) });

	main->rotate(); Btooth->rotate(); Stooth->rotate();
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

void tree::rotate()
{
	angle += 3.14 / 2;
	int root_h = 8 * unitlen;

	tri1->setRefPoint({ RefPoint.x + int(round(sin(angle))) * root_h / 2 ,RefPoint.y - int(round(cos(angle))) * root_h / 2 });
	tri2->setRefPoint({ RefPoint.x + int(round(sin(angle))) * (root_h / 2 - 2 * unitlen) ,RefPoint.y - int(round(cos(angle))) * (root_h / 2 - 2 * unitlen) });
	tri3->setRefPoint({ RefPoint.x + int(round(sin(angle))) * (root_h / 2 - 4 * unitlen) ,RefPoint.y - int(round(cos(angle))) * (root_h / 2 - 4 * unitlen) });
	root->rotate(); tri1->rotate(); tri2->rotate(); tri3->rotate();

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
	

}

void arrow::draw() const
{
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
