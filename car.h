#pragma once
#include <SFML/Graphics.hpp>
#define borderLeft 140
#define borderRight 660
#define high 2
#define low 525

using namespace sf;

class cAr{
    private:
    Vector2f car_posn;
    Sprite car_sprite;
    Texture car_texture;
   // bool car_lft_prsd;
   // bool car_rt_prsd;
    float car_speed;

    public:
    cAr();
    Sprite getSprite();
    void move_lft();
    void move_rt();
    void move_up();
    void move_down();
  //  void rebound_sides();
   // void rebound_floor_ceil()   // void stop_lft();
    //void stop_rt();
    void set_cntr();
   // Sprite get_sprt();
    void update();
   // void crspd();
};
