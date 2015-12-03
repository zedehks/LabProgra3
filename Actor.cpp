#include "Actor.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>

Actor::Actor(SDL_Renderer* r,char tipo, int x, int y)
{
    int w = 0,h=0,
    pos = 0.0;
    this->renderer = r;
    switch(tipo)
    {
    case 'c':
        this->skin = IMG_LoadTexture(r, "chaika.png");
        break;
    case 'p':
        this->skin = IMG_LoadTexture(r, "personaje.png");
    }

    SDL_QueryTexture(skin, NULL, NULL, &w, &h);
    this->rect_actor.x = x; this->rect_actor.y = y; this->rect_actor.w = w; this->rect_actor.h = h;

}

void Actor::draw()
{
    SDL_RenderCopy(renderer, skin, NULL, &rect_actor);
}

void Actor::logic()
{

    rect_actor.w = 128 + (64*cos(pos));
    rect_actor.h = 121 + (64*sin(pos));

    rect_actor.y  = 32 +  (90*cos( pos)) / 3;
    rect_actor.x  = 200  +  (90*sin( pos)) / 3;
   /* rect_actor.h += 10;
    rect_actor.x -= 2;
    rect_actor.y -= 2;*/
    pos+=.1;
}
Actor::~Actor()
{
    //dtor
}
