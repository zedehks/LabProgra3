#include "Playerpawn.h"

/*Playerpawn::Playerpawn(SDL_Renderer* r) : Actor(r,'p', 0, 0)
{

}*/

Playerpawn::~Playerpawn()
{
    //dtor
}
void Playerpawn::logic(){}

bool Playerpawn::logica(Mix_Chunk* pded)
{
    bool attack = false;
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
    if(currentKeyStates[SDL_SCANCODE_K])
    {
        this->hp--;
        if(hp==0)
            Mix_PlayChannel(-1, pded, 0);
    }
    if(currentKeyStates[SDL_SCANCODE_SPACE])
    {
        attack = true;
    }
    rect_actor.x+= x_vel;
    rect_actor.y+= y_vel;


    if(x_vel > 0.0)
        x_vel -= friction;
    if(x_vel < 0.0)
        x_vel += friction;


    if(y_vel > 0.0)
        y_vel -= friction;
     if(y_vel < 0.0)
        y_vel += friction;
    return attack;

}
