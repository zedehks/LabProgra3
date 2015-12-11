#ifndef DUDE_H
#define DUDE_H

#include "Actor.h"


class Dude : public Actor
{
    public:
        int swim;
        bool backwards;
        Dude(SDL_Renderer*r,int x, int y) : Actor(r,x,y)
        {

            int w= 64,h=75;
            this->swim = 0;
            this->backwards = false;
            this->skin = IMG_LoadTexture(r, "ruff.png");
            SDL_QueryTexture(skin, NULL, NULL, &w, &h);
            this->rect_actor.w = w; this->rect_actor.h = h;
        }
        void logic();
        virtual ~Dude();
    protected:
    private:
};

#endif // DUDE_H
