
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include <SDL_ttf.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

#include <cmath>
#include <time.h>



#include <sstream>
#include <string.h>

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
Mix_Music *musik = NULL;
Mix_Chunk *bump;

TTF_Font *typeface;
SDL_Color schwarz = {255,255,255};
SDL_Texture* tTexture;
SDL_Surface* tSurf;
SDL_Rect tRect;

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


using namespace std;

void hud_init(Playerpawn *player)
{
    SDL_DestroyTexture(tTexture);
    SDL_FreeSurface(tSurf);
   //Font by: Adam Moore  http://laemeur.sdf.org/fonts/
   typeface = TTF_OpenFont("MorePerfectDOSVGA.ttf", 32 );



    int health = player->getHP();

    stringstream strs;
      strs << health;
      string temp_str = strs.str();
      char* hp = (char*) temp_str.c_str();

    tSurf = TTF_RenderText_Solid(typeface,hp,schwarz);
    if( tSurf == NULL ) { printf( "Unable to render text surface!\n SDL_ttf Error: %s\n", TTF_GetError() ); }

   tTexture = SDL_CreateTextureFromSurface(renderer,tSurf);
    if( tTexture == NULL ) { printf( "Unable to create texture from rendered text! \nSDL Error: %s\n", SDL_GetError() ); }

   tRect.x = 0;tRect.y = 0;

    SDL_QueryTexture(tTexture,NULL,NULL,&tRect.w,&tRect.h);

}

void hud_redraw(Playerpawn *player)
{
    SDL_DestroyTexture(tTexture);
    SDL_FreeSurface(tSurf);

    int health = player->getHP();

    stringstream strs;
      strs << health;
      string temp_str = strs.str();
      char* hp = (char*) temp_str.c_str();

    tSurf = TTF_RenderText_Solid(typeface,hp,schwarz);
    if( tSurf == NULL ) { printf( "Unable to render text surface!\n SDL_ttf Error: %s\n", TTF_GetError() ); }

   tTexture = SDL_CreateTextureFromSurface(renderer,tSurf);
    if( tTexture == NULL ) { printf( "Unable to create texture from rendered text! \nSDL Error: %s\n", SDL_GetError() ); }

   tRect.x = 0;tRect.y = 0;
   SDL_QueryTexture(tTexture,NULL,NULL,&tRect.w,&tRect.h);

}
int main( int argc, char* args[] )
{
    //Init SDL
    TTF_Init();
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //srand(time(NULL));
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

    //init actors
    Blazkowicz *bj = new Blazkowicz(renderer,300,200);
    Monster* chaika = new Monster(renderer,'c',500,200);
    Dude* bro = new Dude(renderer,100,400);


    Playerpawn* player = new Playerpawn(renderer);

    list<Actor*>actors;

    actors.push_back(chaika);
    actors.push_back(bj);
    actors.push_back(bro);

    //init audio
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_Mixer could not initialize! SDL_Mixer Error: " << Mix_GetError();
    }
    //music
    musik = Mix_LoadMUS("untitled.wav");
    Mix_PlayMusic(musik,-1);
    bump = Mix_LoadWAV("boop.wav");

    //hud init
    hud_init(player);

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

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, &rect_background);


        if(player->getHP() > 0)
        {
            player->logic();
            player->draw();
        }
        for(list<Actor*>::iterator e = actors.begin();e!=actors.end();e++)
        {
            (*e)->logic();
            if( player->rect_actor.x >= (*e)->rect_actor.x && player->rect_actor.x+16 < (*e)->rect_actor.x+(*e)->rect_actor.w )
            {
                 if(player->rect_actor.y >= (*e)->rect_actor.y && player->rect_actor.y+16 < (*e)->rect_actor.y+(*e)->rect_actor.h )
                 {
                    Mix_PlayChannel(-1, bump, 0);
                    player->rect_actor.x += rand() % 33 - 16;
                    player->rect_actor.y += rand() % 33 -16;
                 }
            }


            (*e)->draw();
        }

        hud_redraw(player);
        SDL_RenderCopy(renderer, tTexture, NULL, &tRect);
        SDL_RenderPresent(renderer);

        fLength = SDL_GetTicks();
        if( (fLength - currentTime) < SCREEN_TICKS_PER_FRAME )
        {
            SDL_Delay(SCREEN_TICKS_PER_FRAME - (fLength - currentTime));
        }

        double fps = 1000.0 / (double)SCREEN_TICKS_PER_FRAME-(double)(fLength - currentTime);


    }
    fin:
    free(chaika);
    Mix_FreeMusic( musik );
    musik = NULL;

    for(list<Actor*>::iterator e = actors.begin();e!=actors.end();e++)
    {
        free(*e);
    }

	return 0;
}

