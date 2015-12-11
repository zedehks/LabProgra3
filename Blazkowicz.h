#ifndef BLAZKOWICZ_H
#define BLAZKOWICZ_H

#include "Actor.h"


class Blazkowicz : public Actor
{
    public:
        bool backwards;
        Blazkowicz(SDL_Renderer*r,int x, int y) : Actor(r,x,y)
        {
            int w= 32,h=32;

            this->skin = IMG_LoadTexture(r, "BJ_STAND.png");
            SDL_QueryTexture(skin, NULL, NULL, &w, &h);
            this->rect_actor.w = w; this->rect_actor.h = h;

            backwards = false;
        }


        void logic();
        virtual ~Blazkowicz();
    protected:
    private:
};

#endif // BLAZKOWICZ_H
