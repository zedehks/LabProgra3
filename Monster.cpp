#include "Monster.h"
#include <cmath>
#include <math.h>

/*Monster::Monster(SDL_Renderer * r) : Actor(r,'p', 0, 0)
{
    //ctor
}*/

Monster::~Monster()
{
    //dtor
}

void Monster::logic()
{
    int w = 128;
    int h = 121;
    rect_actor.w = w + (12*cos(++pos));
    rect_actor.h = h + (12*sin(pos));

    rect_actor.y  = this->y +  (90*cos( pos)) / 3;
    rect_actor.x  = this->x  +  (90*sin( pos)) / 3;
}
