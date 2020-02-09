#include "car.h"

cAr :: cAr()
{
    car_speed = 0.2f;
    car_texture.loadFromFile("racer.png");
    car_sprite.setTexture(car_texture);

    car_posn.x = 396;
    car_posn.y = 525;  
}

Sprite cAr :: getSprite(){return car_sprite;}

void cAr :: move_lft(){
if(car_posn.x < borderLeft);
else car_posn.x -= car_speed; }

void cAr :: move_rt(){
if(car_posn.x > borderRight);
else car_posn.x += car_speed;}

void cAr :: move_up()
{  if(car_posn.y < high);
  else car_posn.y -= car_speed;}
  
void cAr :: move_down()
{ if(car_posn.y > low);
  else car_posn.y += car_speed;} 

void cAr :: update()
{
    car_sprite.setPosition(car_posn); }

void cAr :: set_cntr(){
    car_posn.x = 396;
    car_posn.y = 525; }