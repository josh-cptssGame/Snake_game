
#include "help.h"



class PlayerLogic {

public:
    sf::Sprite hold;
    int mold;
    int echoMoveBody;


    //constructor to set ints
    PlayerLogic() {

        this->echoMoveBody = 0;
        this->mold = 0;
    }

    //constructor takes a known sprite 
    PlayerLogic(sf::Sprite in, int a) {
        this->hold = in;
        this->mold = a;
        this->echoMoveBody = 0;
    }

    //as says set the mold int (my movement direction)
    void setMold(int a) {

        this->mold = a;
    }

    //independly updates move mold var
    void logicUpdateMove(int a) {
        this->echoMoveBody = a;
    }

    //check to see if i need to change position out side of class
    void setHoldPosition(sf::Vector2f a) {

        this->hold.setPosition(a);
    }

    //gets mold int
    int getMold(void) {
        
        return this->mold;
    }
    int getEchoMove(void) {

        return this->echoMoveBody;
    }
    sf::Vector2f getHoldPostion() {

        return this->hold.getPosition();
    }

    sf::Sprite getSpritePL(void) {

        return this->hold;
    }

    //function to move this indaviual snake segment
    //uses my movement mold and updates from last segemnt
    sf::Vector2f moveEcho(void) {

        sf::Vector2f tempPosPlayerLogic = this->hold.getPosition();
        switch (this->mold) {
        case 1: {
            //left
            tempPosPlayerLogic.x = tempPosPlayerLogic.x - (50.0f);
            this->echoMoveBody = 1;
            break;
        }
        case 2: {
            //up
            tempPosPlayerLogic.y = tempPosPlayerLogic.y - (50.0f);
            this->echoMoveBody = 2;
            break;
        }
        case 3: {
            //right
            tempPosPlayerLogic.x = tempPosPlayerLogic.x + (50.0f);
            this->echoMoveBody = 3;
            break;
        }
        case 4: {
            //down
            tempPosPlayerLogic.y = tempPosPlayerLogic.y + (50.0f);
            this->echoMoveBody = 4;
            break;
        }
        default:
            break;
        }
        //this->hold.setPosition(tempPosPlayerLogic);
        this->mold = 0;
        return tempPosPlayerLogic;
    }
};
