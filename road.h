#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Road{
   private:
   Vector2f posnrd;
   RectangleShape rdsp;
   float rd_speed = .3f;
   float ht_window;
   float wd_window;

    public:
    Road();
    FloatRect getPosition();
    RectangleShape getShape();
    void update();

};