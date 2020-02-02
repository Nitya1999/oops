#include "road.h"

Road :: Road()
{
    posnrd.x = 500;
    posnrd.y = 300;
    wd_window = VideoMode :: getDesktopMode().width;
    ht_window = VideoMode :: getDesktopMode().height;
    rdsp.setSize(sf :: Vector2f(wd_window/2, ht_window));
    rdsp.setPosition(posnrd);
    rdsp.setFillColor(Color :: Yellow);
}

FloatRect Road :: getPosition(){
    return rdsp.getGlobalBounds();
} 

RectangleShape Road :: getShape()
{
    return rdsp;
}

void Road :: update()
{
    posnrd.y += rd_speed;
    rdsp.setPosition(posnrd);
}