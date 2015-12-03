#include "Blazkowicz.h"
#include <cmath>
#include <math.h>


Blazkowicz::~Blazkowicz()
{
    //dtor
}
void Blazkowicz :: logic()
{

    if(rect_actor.y > (this->y -150) && rect_actor.y >= this->y)
        backwards = true;

    if (rect_actor.y < this->y && rect_actor.y <= (this->y - 150))
        backwards = false;



    if(backwards)
    {
        rect_actor.y-=10;
        rect_actor.x+=10;
    }
    else
    {
        rect_actor.y+=10;
        rect_actor.x-=10;
    }

}
