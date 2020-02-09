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
    float car_speed;

    public:
    cAr();
    Sprite getSprite();
    void move_lft();
    void move_rt();
    void move_up();
    void move_down();
    void set_cntr();
    void update();
};
