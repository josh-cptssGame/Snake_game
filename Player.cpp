#include "help.h"
#include "PlayerLogic.cpp"


class Player {

public:
    sf::Vector2f positionHead;
    int size;
    int keyHold;
    int echoMoveHead;
    sf::Sprite holdSpriteHead;
    sf::Texture textPic;
    std::vector<PlayerLogic> snake;

    // void constructor(void){}

    //constructor with bacic pramiters
    Player() {
        this->size = 1;
        this->keyHold = -1;
        this->echoMoveHead = 0;
        this->positionHead = { 200.0f,200.0f };
        //sf::Vector2f{ 200.0f, 200.0f };

    }
    //constructor with file name to make a 
    Player(std::string name) {
        this->size = 1;
        this->keyHold = -1;
        this->echoMoveHead = 0;
        this->positionHead = { 200.0f,200.0f };

        /* if (!this->textPic.loadFromFile(name, sf::IntRect(0, 0, 600, 800))) {

         }
         this->holdSprite.setScale(float(0.075), float(0.055));
         this->holdSprite.setTexture(textPic);
         this->holdSprite.setPosition(this->position);
         */
    }

    void incSpritePosition() {

        //if only head make spite from the head
        //otherwise look at back and mark position and move back from echo movement
    }

    void getSprite(void) {

        this->holdSpriteHead;
    }

    void setKey(int a) {

        this->keyHold = a;
    }
    int getKey(void) {

        return this->keyHold;
    }

    //initiates the first sprite and the head of snake from a preset file name
    int makeSprite(void) {

        std::string text = "coilsnake1.png";
        if (!this->textPic.loadFromFile("coilsnake1_1.png", sf::IntRect(0, 0, 600, 800))) {
            return (-1);
        }
        this->holdSpriteHead.setScale(float(0.075), float(0.055));
        this->holdSpriteHead.setTexture(textPic);
        this->holdSpriteHead.setPosition(this->positionHead);
        //this->snake.push_back(holdSpriteHead);

        PlayerLogic newHead(holdSpriteHead, 0);
        this->snake.push_back(newHead);

        return 0;
    }

    //makes a new sprite to be added to playerlogic/ snake
    //copies the same sprite as constructor and makes a position
    void makeSpriteInc(sf::Vector2f posIn) {

        sf::Sprite temp;

        temp.setScale(float(0.075), float(0.055));
        temp.setTexture(this->textPic);

        //need function to help make body spawn behind head of snake and from the direction it was moving
       // temp.setPosition(this->snake.back().hold.getPosition());

        PlayerLogic what = this->snake.back();
        int whatInt = what.getMold();

        if(whatInt == 1){
            posIn.x = posIn.x + 50.0f;
        }
        else if (whatInt == 2){
            posIn.y = posIn.y + 50.0f;
        }
        else if (whatInt == 3) {
            posIn.x = posIn.x - 50.0f;
        }
        else if (whatInt == 4) {
            posIn.y = posIn.y - 50.0f;
        }

        temp.setPosition(posIn);
        PlayerLogic fun(temp, whatInt);

        this->snake.push_back(fun);

    }

    //increases snake size and makes a new part of the snake
    void increaseSize(void) {

        this->size++;
        PlayerLogic temp = this->snake.back();
        sf::Vector2f tempPosition = temp.getHoldPostion();
        makeSpriteInc(tempPosition);
        // incSizeHelp();
    }

    //idea on helping make a new sprite to add to snake
    void incSizeHelp(void) {

        PlayerLogic tempAdd;
    }

    //update position of snake body (each peice)
    void helpMoveBody(void) {

        if (this->snake.size() > 0) {
            for (int i = 1; i <= this->snake.size(); i++) {
                PlayerLogic whatTemp = this->snake.at(i -1);
                int temp = whatTemp.getMold();
               // this->snake[i].setMold(temp);
                PlayerLogic help = this->snake.at(i);
                help.setMold(temp);
                sf::Vector2f testPos = help.moveEcho();
                help.setHoldPosition(testPos);
            }
        }
    }

    //funcation to move head of snake (player control part)
    void goMove(void) {

        this->snake.front().setMold(echoMoveHead);

        switch (this->keyHold) {
        case 1: {

            this->positionHead.x = this->positionHead.x - (50.0f);
            this->snake.front().hold.setPosition(positionHead);
            this->echoMoveHead = 1;
            break;
        }
        case 2: {

            this->positionHead.y = this->positionHead.y - (50.0f);
            this->snake.front().hold.setPosition(positionHead);
            this->echoMoveHead = 2;
            break;
        }
        case 3: {
            this->positionHead.x = this->positionHead.x + (50.0f);
            this->snake.front().hold.setPosition(positionHead);
            this->echoMoveHead = 3;
            break;
        }
        case 4: {
            this->positionHead.y = this->positionHead.y + (50.0f);
            this->snake.front().hold.setPosition(positionHead);
            this->echoMoveHead = 4;
            break;
        }
        }
        this->keyHold = -1;
        //this->holdSpriteHead.setPosition(positionHead);
        helpMoveBody();
    }

    //attemp to constitly move head and body
    void movementConst(void) {

        if (this->keyHold == -1) {
            //do nothing
        }

        else if (this->keyHold >= 0) {//do somthing
            sf::Vector2f tempCord = this->holdSpriteHead.getPosition();
            switch (this->keyHold)
            {
            case 0:
                tempCord.y = (tempCord.y + 50.f);
                break;
                /*case 1:
                    //
                    break;
                case 2:
                    //
                    break;
                    */
                    //default:
            }
            this->holdSpriteHead.setPosition(tempCord);
        }
    }
};