#ifndef MONSTER_H
#define MONSTER_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Actor.h"


class Monster : public Actor
{
    public:
        Monster(SDL_Renderer* r, char tipo, int x, int y) : Actor(r, x, y)
        {
            int w= 0,h=0;

            this->skin = IMG_LoadTexture(r, "chaika.png");
            SDL_QueryTexture(skin, NULL, NULL, &w, &h);
            this->rect_actor.w = w; this->rect_actor.h = h;
        }
        virtual ~Monster();
        void logic();
    protected:
    private:
};

#endif // MONSTER_H
