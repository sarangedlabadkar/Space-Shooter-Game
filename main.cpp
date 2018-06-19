#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "collision.hpp"
#include"audio.hpp"
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
int main()
{
    int t =1,b=0,c=0,d=0,h1=0,k=0,h2=0,g=0;
    Mouse mouse;

    stringstream score;
    Texture spaceship;
    Sprite spaceshipsprite;
    spaceship.loadFromFile("player.png");
    spaceshipsprite.setTexture(spaceship);
    spaceshipsprite.setOrigin(Vector2f(70,22));
    spaceshipsprite.setPosition(70,300);

    Texture health;
    Sprite healthsprite;
    health.loadFromFile("health.png");
    healthsprite.setTexture(health);
    healthsprite.setPosition(5,5);
    healthsprite.setScale(0.09,0.09);

    Sprite healthsprite1;
    health.loadFromFile("health.png");
    healthsprite1.setTexture(health);
    healthsprite1.setPosition(35,5);
    healthsprite1.setScale(0.09,0.09);


    Sprite healthsprite2;
    health.loadFromFile("health.png");
    healthsprite2.setTexture(health);
    healthsprite2.setPosition(65,5);
    healthsprite2.setScale(0.09,0.09);

    Font font;
    if(!font.loadFromFile("COOPBL.ttf"))
     return EXIT_FAILURE;
    Text tittle ("Score: ",font,30);
    tittle.setPosition(800,0);
    tittle.setColor(Color::Cyan);

    Text scorename("",font,30);
    scorename.setPosition(915,0);

    Texture gameover;
    Sprite gameoversprite;
    gameover.loadFromFile("gameover.png");
    gameoversprite.setTexture(gameover);
    //gameoversprite.setPosition(65,5);
    gameoversprite.setScale(0.7,0.9);

    Texture play;
    Sprite playsprite;
    play.loadFromFile("start.png");
    playsprite.setTexture(play);
    playsprite.setPosition(300,250);


    Texture ins;
    Sprite inssprite;
    ins.loadFromFile("ins.png");
    inssprite.setTexture(ins);
    inssprite.setPosition(70,450);
    inssprite.setOrigin(0,0);

    Texture exitb;
    Sprite exitsprite;
    exitb.loadFromFile("quit.png");
    exitsprite.setTexture(exitb);
    exitsprite.setPosition(350,600);
    exitsprite.setOrigin(0,0);

    Texture menuwall;
    Sprite menusprite;
    menuwall.loadFromFile("etc.jpg");
    menusprite.setTexture(menuwall);
    menusprite.setOrigin(0,0);
   // menusprite.setPosition(350,600);

    Music bgsong;
    bgsong.openFromFile("sound.ogg");
    bgsong.play();

    Music bulletfire;
    bulletfire.openFromFile("bulletfire.ogg");

    Music boom;
    boom.openFromFile("boom.ogg");

    Music spaceshipdestroy;
    spaceshipdestroy.openFromFile("spaceshipdestroy.ogg");

    Texture explosion;
    Sprite explosionsp;
    explosion.loadFromFile("explosion.png");
    explosionsp.setTexture(explosion);




    Texture enemy;
    Sprite enemysprite;
    enemy.loadFromFile("enemy.png");
    enemysprite.setTexture(enemy);
    enemysprite.setPosition(1170,300);

    Sprite enemysprite1;
    enemy.loadFromFile("enemy.png");
    enemysprite1.setTexture(enemy);
    enemysprite1.setPosition(1100,400);

    Sprite enemysprite2;
    enemy.loadFromFile("enemy.png");
    enemysprite2.setTexture(enemy);
    enemysprite2.setPosition(1020,300);

    Sprite enemysprite3;
    enemy.loadFromFile("enemy.png");
    enemysprite3.setTexture(enemy);
    enemysprite3.setPosition(1200,200);

    Sprite enemysprite4;
    enemy.loadFromFile("enemy.png");
    enemysprite4.setTexture(enemy);
    enemysprite4.setPosition(1040,100);

    Sprite enemysprite5;
    enemy.loadFromFile("enemy.png");
    enemysprite5.setTexture(enemy);
    enemysprite5.setPosition(1200,20);

    Texture enemy1;
    Sprite enemysprite6;
    enemy1.loadFromFile("asteroid.png");
    enemysprite6.setTexture(enemy1);
    enemysprite6.setPosition(1300,500);

    Texture enemy2;
    Sprite enemysprite7;
    enemy2.loadFromFile("asteroid.png");
    enemysprite7.setTexture(enemy2);
    enemysprite7.setPosition(1400,600);

    Sprite enemysprite8;
    enemy1.loadFromFile("asteroid.png");
    enemysprite8.setTexture(enemy1);
    enemysprite8.setPosition(1500,100);

    Sprite enemysprite9;
    enemy2.loadFromFile("saucer.png");
    enemysprite9.setTexture(enemy2);
    enemysprite9.setPosition(1600,200);

    Sprite enemysprite10;
    enemy2.loadFromFile("saucer.png");
    enemysprite10.setTexture(enemy2);
    enemysprite10.setPosition(1700,300);

    Texture enemy3;
    Sprite enemysprite11;
    enemy3.loadFromFile("capsule.png");
    enemysprite11.setTexture(enemy3);
    enemysprite11.setPosition(1800,400);

    Sprite enemysprite12;
    enemy3.loadFromFile("capsule.png");
    enemysprite12.setTexture(enemy3);
    enemysprite12.setPosition(2000,500);

    Sprite enemysprite13;
    enemy3.loadFromFile("capsule.png");
    enemysprite13.setTexture(enemy3);
    enemysprite13.setPosition(1900,600);

    Sprite enemysprite14;
    enemy3.loadFromFile("capsule.png");
    enemysprite14.setTexture(enemy3);
    enemysprite14.setPosition(1970,300);

    Texture win;
    Sprite winsprite;
    win.loadFromFile("win.png");
    winsprite.setTexture(win);
    winsprite.setPosition(-800,-150);

    Texture instruct;
    Sprite instructsprite;
    instruct.loadFromFile("instruction.png");
    instructsprite.setTexture(instruct);
    instructsprite.setPosition(-70,-150);
    instructsprite.setScale(Vector2f(0.7,1));

    Texture backbut;
    Sprite backbuttonsprite;
    backbut.loadFromFile("backbutton.png");
    backbuttonsprite.setTexture(backbut);
    backbuttonsprite.setPosition(350,550);







    Texture bullet;
    Sprite bulletsprite;
    bullet.loadFromFile("bullet.png");
    bulletsprite.setTexture(bullet);
    bulletsprite.setPosition(5000,5000);

    Sprite bulletsprite1;
    bullet.loadFromFile("bullet.png");
    bulletsprite1.setTexture(bullet);
    bulletsprite1.setPosition(5000,5000);

    Sprite bulletsprite2;
    bullet.loadFromFile("bullet.png");
    bulletsprite2.setTexture(bullet);
    bulletsprite2.setPosition(5000,5000);

    Sprite bulletsprite3;
    bullet.loadFromFile("bullet.png");
    bulletsprite3.setTexture(bullet);
    bulletsprite3.setPosition(5000,5000);

    Sprite bulletsprite4;
    bullet.loadFromFile("bullet.png");
    bulletsprite4.setTexture(bullet);
    bulletsprite4.setPosition(5000,5000);

    Sprite enemybulletsprite;
    bullet.loadFromFile("bullet.png");
    enemybulletsprite.setTexture(bullet);
    enemybulletsprite.setPosition(5000,5000);

    Sprite enemybulletsprite1;
    bullet.loadFromFile("bullet.png");
    enemybulletsprite1.setTexture(bullet);
    enemybulletsprite1.setPosition(5000,5000);

    Sprite enemybulletsprite2;
    bullet.loadFromFile("bullet.png");
    enemybulletsprite2.setTexture(bullet);
    enemybulletsprite2.setPosition(5000,5000);

    Sprite enemybulletsprite3;
    bullet.loadFromFile("bullet.png");
    enemybulletsprite3.setTexture(bullet);
    enemybulletsprite3.setPosition(5000,5000);





    Texture bgtex;
    Sprite bgsprite;
    bgtex.loadFromFile("background.png");
    bgsprite.setTexture(bgtex);
    bgsprite.setScale(Vector2f(0.25,0.45));


    Texture wall;
    Sprite wallsprite1;
    wall.loadFromFile("wall.png");
    wallsprite1.setTexture(wall);
    wallsprite1.setScale(Vector2f(1,0.01));

    Sprite wallsprite2;
    wallsprite2.setTexture(wall);
    wallsprite2.setScale(Vector2f(0.004,2));

    Sprite wallsprite3;
    wallsprite3.setTexture(wall);
    wallsprite3.setScale(Vector2f(1,2));
    wallsprite3.setPosition(1020,0);

    Sprite wallsprite4;
    wallsprite4.setTexture(wall);
    wallsprite4.setScale(Vector2f(1,0.01));
    wallsprite4.setPosition(0,715);



    sf::RenderWindow window(sf::VideoMode(1024,720), "Space Invaders");
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
        }
    if(Mouse::isButtonPressed(Mouse::Left))
    {
      Vector2i mymouse(Mouse::getPosition(window));
      Vector2f posti(playsprite.getPosition());
      Vector2u siz(play.getSize());
      if(mymouse.y>=posti.y && mymouse.x>=posti.x && mymouse.y<=posti.y+ siz.y && mymouse.x<=posti.x+siz.x)
        {
        playsprite.setPosition(5000,5000);
        inssprite.setPosition(5000,5000);
        exitsprite.setPosition(5000,5000);
        menusprite.setPosition(5000,5000);
        backbuttonsprite.setPosition(5000,5000);
        instructsprite.setPosition(5000,5000);
         }
    }

     if(Mouse::isButtonPressed(Mouse::Left))
    {
      Vector2i mymouse(Mouse::getPosition(window));
      Vector2f posti(inssprite.getPosition());
      Vector2u siz(ins.getSize());
      if(mymouse.y>=posti.y && mymouse.x>=posti.x && mymouse.y<=posti.y+ siz.y && mymouse.x<=posti.x+siz.x)
        { playsprite.setPosition(5000,5000);
        inssprite.setPosition(5000,5000);
        exitsprite.setPosition(5000,5000);
        menusprite.setPosition(5000,5000);
        instructsprite.setPosition(-70,-150);
        backbuttonsprite.setPosition(350,550);

        }

    }

    if(Mouse::isButtonPressed(Mouse::Left))
    {
      Vector2i mymouse(Mouse::getPosition(window));
      Vector2f posti(backbuttonsprite.getPosition());
      Vector2u siz(backbut.getSize());
      if(mymouse.y>=posti.y && mymouse.x>=posti.x && mymouse.y<=posti.y+ siz.y && mymouse.x<=posti.x+siz.x)
        {
        playsprite.setPosition(300,250);
        inssprite.setPosition(70,450);
        exitsprite.setPosition(350,600);
        menusprite.setPosition(0,0);
        instructsprite.setPosition(5000,5000);

        }

    }

    if(Mouse::isButtonPressed(Mouse::Left))
    {
      Vector2i mymouse(Mouse::getPosition(window));
      Vector2f posti(exitsprite.getPosition());
      Vector2u siz(exitb.getSize());
      if(mymouse.y>=posti.y && mymouse.x>=posti.x && mymouse.y<=posti.y+ siz.y && mymouse.x<=posti.x+siz.x)
        {
        cout<<"You are out of the game";
        exitsprite.setPosition(5000,5000);
        window.close();

        }

    }


    if(Keyboard::isKeyPressed(Keyboard::Up)&& !Collision::PixelPerfectTest(spaceshipsprite,wallsprite1))
        spaceshipsprite.move(0,-0.5);
    if(Keyboard::isKeyPressed(Keyboard::Down)&& !Collision::PixelPerfectTest(spaceshipsprite,wallsprite4))
        spaceshipsprite.move(0,0.5);
    if(Keyboard::isKeyPressed(Keyboard::Right)&& !Collision::PixelPerfectTest(spaceshipsprite,wallsprite3))
        spaceshipsprite.move(0.5,0);
    if(Keyboard::isKeyPressed(Keyboard::Left) && !Collision::PixelPerfectTest(spaceshipsprite,wallsprite2))
        spaceshipsprite.move(-0.5,0);

        if(Keyboard::isKeyPressed(Keyboard::Space)&& t==1 && c>=250)
        {

             bulletsprite.setPosition(spaceshipsprite.getPosition().x,spaceshipsprite.getPosition().y);
             bulletfire.play();
             cout<<"one\n";
             t++;
             c=0;


        }

         if(Keyboard::isKeyPressed(Keyboard::Space)&& t==2 && c>=250)
        {

            bulletsprite1.setPosition(spaceshipsprite.getPosition().x,spaceshipsprite.getPosition().y);
             bulletfire.play();
             t++;
             cout<<"two\n";
             c=0;
        }

         if(Keyboard::isKeyPressed(Keyboard::Space)&& t==3 && c>=250)
        {

            bulletsprite2.setPosition(spaceshipsprite.getPosition().x,spaceshipsprite.getPosition().y);
             bulletfire.play();
             t++;
                cout<<"three\n";
                c=0;
        }

         if(Keyboard::isKeyPressed(Keyboard::Space)&& t==4 && c>=250)
        {

            bulletsprite3.setPosition(spaceshipsprite.getPosition().x,spaceshipsprite.getPosition().y);
             bulletfire.play();
             t++;
                cout<<"4\n";
                c=0;


        }

         if(Keyboard::isKeyPressed(Keyboard::Space)&& t==5 && c>=250)
        {

            bulletsprite4.setPosition(spaceshipsprite.getPosition().x,spaceshipsprite.getPosition().y);
             bulletfire.play();
             t=1;
                cout<<"5\n";
                c=0;

        }



                bulletsprite.move(1,0);
                bulletsprite1.move(1,0);
                bulletsprite2.move(1,0);
                bulletsprite3.move(1,0);
                bulletsprite4.move(1,0);
                c++;

                enemybulletsprite.move(-1,0);
                enemybulletsprite1.move(-1,0);
                enemybulletsprite2.move(-1,0);
                enemybulletsprite3.move(-1,0);




                enemysprite.move(-0.5,0);
                enemysprite1.move(-0.5,0);
                enemysprite2.move(-0.5,0);
                enemysprite3.move(-0.5,0);
                enemysprite4.move(-0.5,0);
                enemysprite5.move(-0.5,0);
                if(k>=500)
                {

                enemysprite6.move(-0.5,0);
                enemysprite7.move(-0.5,0);
                enemysprite8.move(-0.5,0);
                enemysprite9.move(-0.5,0);
                enemysprite10.move(-0.5,0);
                }
                if(k>=1000)
               {

                enemysprite11.move(-0.5,0);
                enemysprite12.move(-0.5,0);
                enemysprite13.move(-0.5,0);
                enemysprite14.move(-0.5,0);
               }








        if(Collision::PixelPerfectTest(bulletsprite,enemysprite)||Collision::PixelPerfectTest(bulletsprite1,enemysprite) || Collision::PixelPerfectTest(bulletsprite2,enemysprite) || Collision::PixelPerfectTest(bulletsprite3,enemysprite) || Collision::PixelPerfectTest(bulletsprite4,enemysprite))
        {
          window.draw(explosionsp);
           enemysprite.setPosition(1050,300);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());




        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite1)||Collision::PixelPerfectTest(bulletsprite1,enemysprite1) || Collision::PixelPerfectTest(bulletsprite2,enemysprite1)|| Collision::PixelPerfectTest(bulletsprite3,enemysprite1)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite1))
        {
           enemysprite1.setPosition(1100,400);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite2)||Collision::PixelPerfectTest(bulletsprite1,enemysprite2) || Collision::PixelPerfectTest(bulletsprite2,enemysprite2)||Collision::PixelPerfectTest(bulletsprite3,enemysprite2)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite2))
        {
           enemysprite2.setPosition(1020,300);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite3)||Collision::PixelPerfectTest(bulletsprite1,enemysprite3) || Collision::PixelPerfectTest(bulletsprite2,enemysprite3)||Collision::PixelPerfectTest(bulletsprite3,enemysprite3)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite3))
        {
           enemysprite3.setPosition(1200,200);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }

      if(Collision::PixelPerfectTest(bulletsprite,enemysprite4)||Collision::PixelPerfectTest(bulletsprite1,enemysprite4) || Collision::PixelPerfectTest(bulletsprite2,enemysprite4)||Collision::PixelPerfectTest(bulletsprite3,enemysprite4)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite4))
        {
           enemysprite4.setPosition(1040,100);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite5)||Collision::PixelPerfectTest(bulletsprite1,enemysprite5) || Collision::PixelPerfectTest(bulletsprite2,enemysprite5)||Collision::PixelPerfectTest(bulletsprite3,enemysprite4)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite4))
        {
           enemysprite5.setPosition(1200,20);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }





        if(Collision::PixelPerfectTest(bulletsprite,enemysprite6)||Collision::PixelPerfectTest(bulletsprite1,enemysprite6) || Collision::PixelPerfectTest(bulletsprite2,enemysprite6)||Collision::PixelPerfectTest(bulletsprite3,enemysprite6)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite6))
        {
           enemysprite6.setPosition(1300,500);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite7)||Collision::PixelPerfectTest(bulletsprite1,enemysprite7) || Collision::PixelPerfectTest(bulletsprite2,enemysprite7)||Collision::PixelPerfectTest(bulletsprite3,enemysprite7)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite7))
        {
           enemysprite7.setPosition(1400,600);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite8)||Collision::PixelPerfectTest(bulletsprite1,enemysprite8) || Collision::PixelPerfectTest(bulletsprite2,enemysprite8)||Collision::PixelPerfectTest(bulletsprite3,enemysprite8)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite8))
        {
           enemysprite8.setPosition(1500,100);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite9)||Collision::PixelPerfectTest(bulletsprite1,enemysprite9) || Collision::PixelPerfectTest(bulletsprite2,enemysprite9)||Collision::PixelPerfectTest(bulletsprite3,enemysprite9)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite9))
        {
           enemysprite9.setPosition(1600,200);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite10)||Collision::PixelPerfectTest(bulletsprite1,enemysprite10) || Collision::PixelPerfectTest(bulletsprite2,enemysprite10)||Collision::PixelPerfectTest(bulletsprite3,enemysprite10)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite10))
        {
           enemysprite10.setPosition(1700,300);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }







        if(Collision::PixelPerfectTest(bulletsprite,enemysprite11)||Collision::PixelPerfectTest(bulletsprite1,enemysprite11) || Collision::PixelPerfectTest(bulletsprite2,enemysprite11)||Collision::PixelPerfectTest(bulletsprite3,enemysprite11)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite11))
        {
           enemysprite11.setPosition(1800,400);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite12)||Collision::PixelPerfectTest(bulletsprite1,enemysprite12) || Collision::PixelPerfectTest(bulletsprite2,enemysprite12)||Collision::PixelPerfectTest(bulletsprite3,enemysprite12)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite12))
        {
           enemysprite12.setPosition(2000,500);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite13)||Collision::PixelPerfectTest(bulletsprite1,enemysprite13) || Collision::PixelPerfectTest(bulletsprite2,enemysprite13)||Collision::PixelPerfectTest(bulletsprite3,enemysprite12)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite12))
        {
           enemysprite13.setPosition(1900,600);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }
        if(Collision::PixelPerfectTest(bulletsprite,enemysprite14)||Collision::PixelPerfectTest(bulletsprite1,enemysprite14) || Collision::PixelPerfectTest(bulletsprite2,enemysprite14)||Collision::PixelPerfectTest(bulletsprite3,enemysprite14)|| Collision::PixelPerfectTest(bulletsprite4,enemysprite14))
        {
           enemysprite14.setPosition(1970,300);
           boom.play();
           k=k+10;
           score.str("");
           score<<k;
           scorename.setString(score.str());
        }



            if(enemysprite.getPosition().x <=0)
            enemysprite.setPosition(1050,300);

            if(enemysprite1.getPosition().x <=0)
            enemysprite1.setPosition(1100,400);

            if(enemysprite2.getPosition().x <=0)
            enemysprite2.setPosition(1020,300);

            if(enemysprite3.getPosition().x <=0)
            enemysprite3.setPosition(1200,200);

            if(enemysprite4.getPosition().x <=0)
            enemysprite4.setPosition(1040,100);

            if(enemysprite5.getPosition().x <=0)
            enemysprite5.setPosition(1200,20);

            if(enemysprite6.getPosition().x <=0)
            enemysprite6.setPosition(1300,500);

            if(enemysprite7.getPosition().x <=0)
            enemysprite7.setPosition(1400,600);

            if(enemysprite8.getPosition().x <=0)
            enemysprite8.setPosition(1500,100);

            if(enemysprite9.getPosition().x <=0)
            enemysprite9.setPosition(1600,200);

            if(enemysprite10.getPosition().x <=0)
            enemysprite10.setPosition(1700,300);

            if(enemysprite11.getPosition().x <=0)
            enemysprite11.setPosition(1800,400);


            if(enemysprite12.getPosition().x <=0)
            enemysprite12.setPosition(2000,500);

            if(enemysprite13.getPosition().x <=0)
            enemysprite13.setPosition(1900,600);

            if(enemysprite14.getPosition().x <=0)
            enemysprite14.setPosition(1970,300);

            h2=0;
            if(bulletsprite.getPosition().x>=1025 && h2==0)
            {
                bulletsprite.setPosition(5000,5000);
                h2++;
            }
            h2=0;
            if(bulletsprite1.getPosition().x>=1025 && h2==0)
            {
                bulletsprite1.setPosition(5000,5000);
                h2++;
            }
            h2=0;
            if(bulletsprite2.getPosition().x>=1025 && h2==0)
            {
                bulletsprite2.setPosition(5000,5000);
                h2++;
            }
            h2=0;
            if(bulletsprite3.getPosition().x>=1025 && h2==0)
            {
                bulletsprite3.setPosition(5000,5000);
                h2++;
            }
            h2=0;
            if(bulletsprite4.getPosition().x>=1025 && h2==0)
            {
                bulletsprite4.setPosition(5000,5000);
                h2++;
            }
            h2=0;






       // spaceship khatam agar enemy se touch hua to
     if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;

        }

        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite2))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }

        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite1))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }

        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite3))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
         if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite4))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite5))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite6))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite7))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
         if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite8))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite9))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite10))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite11))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite12))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite13))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }
        if(Collision::PixelPerfectTest(spaceshipsprite,enemysprite14))
        {
           spaceshipsprite.setPosition(5000,5000);
            spaceshipdestroy.play();
            d++;
        }

        if(d==1 && h1==0)
        {
            healthsprite2.setPosition(5000,5000);
            spaceshipsprite.setPosition(70,700);
            h1++;

        }

        if(d==2 && h1==1)
        {
            healthsprite1.setPosition(5000,5000);
            spaceshipsprite.setPosition(70,700);
            h1++;
        }

        if(d==3)
        {
            g=1;
            healthsprite.setPosition(5000,5000);


        }



        window.clear();
        window.draw(wallsprite1);
        window.draw(wallsprite2);
        window.draw(wallsprite3);
        window.draw(wallsprite4);
        window.draw(bgsprite);
        window.draw(spaceshipsprite);
        window.draw(bulletsprite);
        window.draw(bulletsprite1);
        window.draw(bulletsprite2);
        window.draw(bulletsprite3);
        window.draw(bulletsprite4);
        window.draw(enemybulletsprite);
        window.draw(enemybulletsprite1);
        window.draw(enemybulletsprite2);
        window.draw(enemybulletsprite3);
        window.draw(enemysprite);
        window.draw(enemysprite1);
        window.draw(enemysprite2);
        window.draw(enemysprite3);
        window.draw(enemysprite4);
        window.draw(enemysprite5);
        window.draw(enemysprite6);
        window.draw(enemysprite7);
        window.draw(enemysprite8);
        window.draw(enemysprite9);
        window.draw(enemysprite10);
        window.draw(enemysprite11);
        window.draw(enemysprite12);
        window.draw(enemysprite13);
        window.draw(enemysprite14);
        window.draw(healthsprite);
        window.draw(healthsprite1);
        window.draw(healthsprite2);
        window.draw(tittle);
        window.draw(scorename);
        window.draw(instructsprite);
        window.draw(backbuttonsprite);
        window.draw(menusprite);
        window.draw(playsprite);
        window.draw(inssprite);
        window.draw(exitsprite);
        if(g==1)
        window.draw(gameoversprite);
         if(k>=10000)
               {
                   window.draw(winsprite);

               }


        window.display();
    }

}
