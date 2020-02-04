#include "car.h"
#include "obs.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
using namespace sf;

    double BackgroundY1 = 0;
    double BackgroundY2 = -600; 

void back_scrol(double spd)
{
      if(BackgroundY2 > 0)
     {
         BackgroundY1 = 0;
         BackgroundY2 = BackgroundY1 - 500;
     }
     BackgroundY1 += spd;
     BackgroundY2 += spd;
}

int main()
{
    const double SCREEN_WIDTH=800;
    const double SCREEN_HEIGH=600;
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGH), "Car Dodge");
    Sprite bgsprt, bgsprt1;

     double bkspd = 0.05;
    Texture bgtxt; bgtxt.loadFromFile("background.png");
    cAr p1_car;
    obS obs1, obs2, obs3, obs4;
    int score = 0; 
    int lives = 3, ct=0;
     Text hud;
    Font font;
    if(!font.loadFromFile("DS-DIGIT.TTF"))
    return EXIT_FAILURE;
    hud.setFont(font);
    hud.setCharacterSize(50);
    hud.setFillColor(sf :: Color :: White);
    Clock clock;   
    while(window.isOpen())
    {
          Event evt;
         while(window.pollEvent(evt))
          if(evt.type == Event :: Closed)
            window.close();
         
        if(Keyboard :: isKeyPressed(Keyboard :: Escape))
        window.close();
        if(Keyboard :: isKeyPressed(Keyboard :: A) || Keyboard :: isKeyPressed(Keyboard :: Left))
        p1_car.move_lft();
        if(Keyboard :: isKeyPressed(Keyboard :: D) || Keyboard :: isKeyPressed(Keyboard :: Right))
        p1_car.move_rt();
        if(Keyboard :: isKeyPressed(Keyboard :: W) || Keyboard :: isKeyPressed(Keyboard :: Up))
        p1_car.move_up();
        if(Keyboard :: isKeyPressed(Keyboard :: S) || Keyboard :: isKeyPressed(Keyboard :: Down))
        p1_car.move_down();
    
    bgsprt.setTexture(bgtxt);
    bgsprt1.setTexture(bgtxt);

    //scrolling background..
     bgsprt.setPosition(0, BackgroundY1);
     bgsprt1.setPosition(0, BackgroundY2);
     if(score <= 10)
      back_scrol(bkspd);
     else if(score > 10 && score <= 25)
     back_scrol(2.5*bkspd);
     else if(score > 25 && score <= 40)
     back_scrol(3*bkspd);
     else /*if( score > 40 && score <= 60)*/
     back_scrol(4.5*bkspd);
     //if(score > 100)
     //back_scrol(4.5*bkspd);
     

    std :: stringstream ss;
    ss << " Score: " << score << "    Lives: "<< lives;
    hud.setString(ss.str());
    
    if((score > 10 && score <= 25) && (ct == 0)) 
    {obs1.obspd(); ct++;} 
    else if(score > 25 && score <= 40 && ct == 1)
    {obs1.obspd(); ct++;}
    else if(score > 40 && score <= 65 && ct == 2)
    {obs1.obspd(); ct++;}
    else if(score > 65 && ct == 3)
    {obs1.obspd(); ct++;}
    if(score > 100 && ct == 4)
    {obs2.obspd(); ct++;}

        p1_car.update(); 
          obs1.update();
          obs2.update();
          obs3.update();
         score = obs4.update();
          if(p1_car.getSprite().getGlobalBounds().intersects(obs1.getSprite().getGlobalBounds()) || 
             p1_car.getSprite().getGlobalBounds().intersects(obs2.getSprite().getGlobalBounds()) || 
             p1_car.getSprite().getGlobalBounds().intersects(obs3.getSprite().getGlobalBounds()) || 
             p1_car.getSprite().getGlobalBounds().intersects(obs4.getSprite().getGlobalBounds()) )
          {p1_car.set_cntr();
          lives--;
          obs1.resetX(); obs2.resetX(); obs3.resetX(); obs4.resetX();
        if(lives < 1) window.close();}  
          //non overlapping obstracles...
          if(obs1.getSprite().getGlobalBounds().intersects(obs2.getSprite().getGlobalBounds()))
          obs1.resetX();
          if(obs1.getSprite().getGlobalBounds().intersects(obs3.getSprite().getGlobalBounds()))
          obs1.resetX();
          if(obs1.getSprite().getGlobalBounds().intersects(obs4.getSprite().getGlobalBounds()))
          obs1.resetX();
          if(obs2.getSprite().getGlobalBounds().intersects(obs3.getSprite().getGlobalBounds()))
          obs2.resetX();
          if(obs2.getSprite().getGlobalBounds().intersects(obs4.getSprite().getGlobalBounds()))
          obs2.resetX();
          if(obs3.getSprite().getGlobalBounds().intersects(obs4.getSprite().getGlobalBounds()))
          obs3.resetX();
     

    /*ime t3 = clock.getElapsedTime();
     float sec = t3.asSeconds()*1000;
     score = sec;
     clock.restart();*/
          window.clear(Color :: Black);

       window.draw(bgsprt);
       window.draw(bgsprt1);
       window.draw(obs2.getSprite());
       window.draw(obs1.getSprite()); 
       window.draw(obs3.getSprite());
       window.draw(obs4.getSprite());          
       window.draw(p1_car.getSprite());
       window.draw(hud);
       window.display();

    } 
}