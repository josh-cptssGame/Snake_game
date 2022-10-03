#include "help.h"



class ObjectEat {

public:
    //sf::Sprite foodSprite;
    sf::Vector2f eatPostion;
    int posX = 0, posY = 0;
    sf::CircleShape item;


    //constructor makes object at top left corner
    ObjectEat() {

        this->eatPostion.x = 0;
        this->eatPostion.y = 0;
    }

    //constrictor takes in a position and assinges it
    ObjectEat(sf::Vector2f inPos) {

        this->eatPostion.x = inPos.x;
        this->eatPostion.y = inPos.y;
    }

    //returns eatable objects position
    sf::Vector2f getEatPostion(void) {

        return this->eatPostion;
    }

    //makes eatable object (shape and such) and assigns position
    void makeObjEat(void) {

        //calles function to make a random position
        makeRandom();
        //this->item.setPosition(float (posX), float (posY));
        this->item.setPosition(eatPostion);
        this->item.setRadius(20.f);
        this->item.setFillColor(sf::Color::Red);
    }

    //makes a random position and assigns it to eatable object
    void makeRandom(void) {
        int i = rand() % 10;
        int j = rand() % 10;

        this->posX = i * 50;
        this->posY = j * 50;

        this->eatPostion.x = i * 50;
        this->eatPostion.y = j * 50;
    }

    //calls random position function and assigns to eatable object as a new position
    void moveItem(void) {

        //calles random function for positions
        makeRandom();
        //this->item.setPosition(float (posX), float (posY));
        this->item.setPosition(eatPostion);

    }

    //boolien function to check that a new random position isnt on the snake
    bool checkIfInSnake(void) {


    }
};