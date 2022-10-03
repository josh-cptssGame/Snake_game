#include "help.h"



class Board {

public:
    int boardHeight = 10, boardLength = 10, tileSize = 50;
    //sf::RectangleShape tile;

    std::vector<sf::RectangleShape> theBoard;

    //makes the defalt tile size and shape that will be used for making a sub set of board
    //at the moment (atm) its locked in size need to make more dynamic
    sf::RectangleShape makeTile(int multiplierA, int multiplierB) {
        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(50, 50));
        tile.setFillColor(sf::Color::White);
        tile.setOutlineColor(sf::Color::Black);
        tile.setOutlineThickness(5);
        tile.setPosition(sf::Vector2f(float(50 * multiplierA), float(50 * multiplierB)));

        return tile;
    };


    //makes a vector of tiles at different positions that is referenced to make the whole board
    void makeBoard(void) {
        std::vector< sf::RectangleShape> squareBoard;

        for (int vert = 0; vert < 10; vert++) {

            for (int horz = 0; horz < 10; horz++) {
                sf::RectangleShape hold = makeTile(horz, vert);
                squareBoard.push_back(hold);
            }
        }
        this->theBoard = squareBoard;

    };

    //boolien function to chect if the snake head is past the edge of the board
    bool collitionDetection(sf::Sprite in) {

        sf::Vector2f hold = in.getPosition();

        if ((hold.y <= 0) || (hold.y >= (10 * 50))
            || (hold.x <= 0) || (hold.x >= (10 * 50))) {
            return true;
        }
        else {

            return false;
        }
        //return false;
    }

};