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
        Playerpawn(SDL_Renderer* r) : Actor(r,'p', 0, 0)
        {

        }
        void logic();
        double velocity = 2.5, x_vel = 0, y_vel = 0,friction = (velocity/2);
        virtual ~Playerpawn();
    protected:
    private:
};

#endif // PLAYERPAWN_H
