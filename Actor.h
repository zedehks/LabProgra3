#ifndef ACTOR_H
#define ACTOR_H
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

class Actor
{
    public:
        SDL_Texture *skin;
        SDL_Rect rect_actor;
        SDL_Renderer* renderer;
        double pos;
        int x,y;
        Actor(SDL_Renderer* r, int x, int y);
        void draw();
        virtual void logic(){}

        virtual ~Actor();

    protected:
    private:
};

#endif // ACTOR_H
