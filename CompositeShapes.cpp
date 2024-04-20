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
