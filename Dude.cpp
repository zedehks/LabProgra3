#include "Dude.h"
#include <cmath>
#include <time.h>

Dude::~Dude()
{
    //dtor
}
void Dude::logic()
{
    srand(time(NULL));

    swim = (rand() % 3);

    if(swim == 0 && rect_actor.x < this->x+350)
    {
        rect_actor.x+=3;
        //swim--;
    }
    else if (swim == 2 && rect_actor.x > 50)
    {
        rect_actor.x-=3;
        //swim--;
    }
    else
    {
        if(rect_actor.y > (this->y -10) && rect_actor.y >= this->y)
            backwards = true;

        if (rect_actor.y < this->y && rect_actor.y <= (this->y - 10))
            backwards = false;



        if(backwards)
            rect_actor.y-=1;
        else
            rect_actor.y+=1;
    }
}
