
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

#include "Actor.h"
#include "Playerpawn.h"

#include "Monster.h"
#include "Blazkowicz.h"
#include "Dude.h"


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background;
SDL_Rect rect_background;

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

using namespace std;

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Mwee~", 100, 100, 800/*WIDTH*/, 500/*HEIGHT*/, SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"beach.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    Blazkowicz *bj = new Blazkowicz(renderer,300,200);
    Monster* chaika = new Monster(renderer,'c',500,200);
    Dude* bro = new Dude(renderer,100,400);


    Playerpawn* player = new Playerpawn(renderer);

    list<Actor*>actors;

    actors.push_back(chaika);
    actors.push_back(bj);
    actors.push_back(bro);


    //int frame = 0;
    int fLength = 0;
    int currentTime = 0;
    //Main Loop
    while(true)
    {
        currentTime = SDL_GetTicks();
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                switch(Event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    goto fin;
                }
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        player->logic();
        player->draw();
        for(list<Actor*>::iterator e = actors.begin();e!=actors.end();e++)
        {
            (*e)->logic();
            (*e)->draw();
        }


        SDL_RenderPresent(renderer);

        fLength = SDL_GetTicks();
        if( (fLength - currentTime) < SCREEN_TICKS_PER_FRAME )
        {
            SDL_Delay(SCREEN_TICKS_PER_FRAME - (fLength - currentTime));
        }

        double fps = 1000.0 / (double)SCREEN_TICKS_PER_FRAME-(double)(fLength - currentTime);
        system("cls");
        printf("\n%f",fps);
        printf("\nx speed: %f",player->x_vel);
        printf("\ny speed: %f",player->y_vel);
        printf("\ndude speed: %d",bro->swim);

    }

    fin:
    free(player);
    for(list<Actor*>::iterator e = actors.begin();e!=actors.end();e++)
    {
        free(*e);
    }

	return 0;
}

