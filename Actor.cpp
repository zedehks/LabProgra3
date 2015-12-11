#include "Actor.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>

Actor::Actor(SDL_Renderer* r, int x, int y)
{
    int w = 0,h=0,pos=0.0;
    isDead = false;
    this->renderer = r;
    this->x=x;
    this->y=y;
    //this->skin = skin = IMG_LoadTexture(r, "BJ_STAND.png");
    SDL_QueryTexture(skin, NULL, NULL, &w, &h);
    this->rect_actor.x = x; this->rect_actor.y = y; this->rect_actor.w = w; this->rect_actor.h = h;

}

void Actor::draw()
{
    SDL_RenderCopy(renderer, skin, NULL, &rect_actor);
}

/*void Actor::logic()
{

<<<<<<< HEAD
=======
    rect_actor.w = 128 + (64*cos(pos));
    rect_actor.h = 121 + (64*sin(pos));
>>>>>>> refs/remotes/origin/Tarea2Backup

    rect_actor.x -= 2;
<<<<<<< HEAD
    rect_actor.y -= 2;
}*/

Actor::~Actor()
{
    //dtor
}
