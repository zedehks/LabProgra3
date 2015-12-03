#ifndef PLAYERPAWN_H
#define PLAYERPAWN_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Actor.h"


class Playerpawn : public Actor
{
    public:
        int hp;
        Playerpawn(SDL_Renderer* r) : Actor(r, 0, 0)
        {
            int w= 0,h=0;
            hp = 100;
            this->skin = IMG_LoadTexture(r, "personaje.png");
            SDL_QueryTexture(skin, NULL, NULL, &w, &h);
            this->rect_actor.w = w; this->rect_actor.h = h;
        }
        void logic();
        double velocity = 2.5, x_vel = 0, y_vel = 0,friction = (velocity/2);
        int getHP()
        {
            return this->hp;
        }
        virtual ~Playerpawn();
    protected:
    private:
};

#endif // PLAYERPAWN_H
