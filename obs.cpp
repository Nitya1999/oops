#include "obs.h"
#include <cstdlib>
int ct=0;

int get_random_num(int a, int b)
{
        static bool first = true; if (first){srand( time(NULL) );first = false;}
        int result=a + rand() % (( b + 1 ) - a);
        result=(result/10)*10;
        return result;
}

obS :: obS()
{   static int st=0;
    obs_speed = 0.07f;
    obs_posn.x = get_random_num(borderLeft, borderRight);
    if(st == 0) 
    obs_posn.y = 0;
    else if(st == 1)obs_posn.y = -200;
    else if(st == 2) obs_posn.y = -300;
    else obs_posn.y = -100;

    obtxt.loadFromFile("obs.png");
    obsprt.setTexture(obtxt);
    st++;
}

Sprite obS :: getSprite()
{
    return obsprt;
}

int obS :: update()
{    static int scr=0;
    if(obs_posn.y < low)
    obs_posn.y += obs_speed;
    else{
        scr++;
        obs_posn.y = 0; 
        obs_posn.x = get_random_num(borderLeft,borderRight);
    }
    obsprt.setPosition(obs_posn);
    return scr;
}

void obS :: resetX()
{   static int gt=0;
    obs_posn.x = get_random_num(borderLeft, borderRight);
      if(gt == 0) 
    obs_posn.y = 0;
    else if(gt == 1)obs_posn.y = -200;
    else if(gt == 2) obs_posn.y = -300;
    else obs_posn.y = -100;
    gt = (gt+1)%4;
}
/*void obS :: obspd(){
    if(ct == 0)
    obs_speed += 0.03f;
     ct = (ct+1)%4;}*/
//FloatRect obS :: get_Posn(){return obsprt.getGlobalBounds();}