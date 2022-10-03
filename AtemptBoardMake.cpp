#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <ostream>
#include <iostream>
#include <random>
#include <cstdlib>

#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>

#include "help.h"
#include "EatObject.cpp"
//#include "PlayerLogic.cpp"
#include "Board.cpp"
#include "Player.cpp"


int WinMain()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
    window.setFramerateLimit(60);
    
    sf::CircleShape shape(100.f);
   // sf::RectangleShape tile(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color::Green);
    //tile.setFillColor(sf::Color::White);

    int trackTime = 0;

    Board aTest;

    aTest.makeBoard();

    Player aPlayerTest;
    ObjectEat aEat;
    aEat.makeObjEat();
    int tempSprite = aPlayerTest.makeSprite();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
            {
                window.close();
            }
            case sf::Event::KeyPressed:
            {
                //sf::Keyboard::Key buttonTest;
                switch (event.key.code) {
                case sf::Keyboard::A: {
                    aPlayerTest.setKey(1);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::W: {
                    aPlayerTest.setKey(2);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::D: {
                    aPlayerTest.setKey(3);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::S: {
                    aPlayerTest.setKey(4);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::Left: {
                    aPlayerTest.setKey(1);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::Up: {
                    aPlayerTest.setKey(2);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::Right: {
                    aPlayerTest.setKey(3);
                    aPlayerTest.goMove();
                    break;
                }
                case sf::Keyboard::Down: {
                    aPlayerTest.setKey(4);
                    aPlayerTest.goMove();
                    break;
                }
                //pause button
                case sf::Keyboard::P: {
                    break;
                }
                }

            }
            }
        }

        if (trackTime >=0) {
            window.clear();
            window.draw(shape);

            for (int a = 0; a < aTest.theBoard.size(); a++) {
                window.draw(aTest.theBoard[a]);
            }
 
            window.draw(aEat.item);
            
            if (tempSprite == -1) {
                //return 0;
                //cout << "negitive 1";
            }
            else {
                //window.draw(aPlayerTest.holdSpriteHead);
                
                if (aPlayerTest.size >= 0) {

                    for (int i = 0; i < aPlayerTest.size; i++) {
                        PlayerLogic temp = aPlayerTest.snake[i];
                        window.draw(temp.getSpritePL());
                    }
                }
                
                // //used to draw other snakes not the first one
                //window.draw(aPlayerTest.snake.at(0).getSprite());

                //test makeing a second sprite of the same texture
                // using this when we eat and need to make size bigger for player
                //aPlayerTest.holdSprite.setPosition(float(250), float(200));
                //window.draw(aPlayerTest.holdSprite);
            }


            //player sprite is on top of eatable item: check and then handle 
            //making a second sprite and making a new eatable item
            if (aPlayerTest.holdSpriteHead.getPosition() == aEat.getEatPostion()) {
                aEat.moveItem();
                aPlayerTest.increaseSize();
            }

            window.display();
        }

       /* else if (trackTime > 0) {

            if (event.KeyPressed) {
                aPlayerTest.setMoveDirection();
                aPlayerTest.movementConst();
                window.draw(aPlayerTest.holdSpriteHead);
            }
            /*int temp = trackTime % 30;
            if ((temp == 0)){
                aEat.makeObjEat();
                window.draw(aEat.item);
            }*/
            //*/ }

        trackTime = trackTime + 5;
    }
    return 0;
}