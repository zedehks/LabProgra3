#include "Playerpawn.h"

/*Playerpawn::Playerpawn(SDL_Renderer* r) : Actor(r,'p', 0, 0)
{

}*/

Playerpawn::~Playerpawn()
{
    //dtor
}

void Playerpawn::logic()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
    {
        if(x_vel < 10)
            x_vel+=velocity;
    }
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
    {
        if(x_vel > -10)
            x_vel-=velocity;
    }
    if( currentKeyStates[ SDL_SCANCODE_UP ] )
    {
        if(y_vel > -10)
            y_vel-=velocity;
    }
    if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
    {
        if(y_vel < 10)
            y_vel+=velocity;
    }
    rect_actor.x+= x_vel;
    rect_actor.y+= y_vel;


    if(x_vel > 0)
        x_vel -= velocity/2;
    else if(x_vel < 0)
        x_vel += velocity/2;
    else
        x_vel = 0;

    if(y_vel > 0)
        y_vel -= velocity/2;
    else if(y_vel < 0)
        y_vel += velocity/2;
    else
        y_vel = 0;
}
