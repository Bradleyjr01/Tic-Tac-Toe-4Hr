#include <iostream>
#include "T3Board.h"

char InputChecker(char inputChar, T3Board currentBoard);
void BotChoice(T3Board currentBoard, bool start, int turn);

int main() {
    int gamesPlayed = 0;
    char playerInput = 'X';

    do {
        std::cout << "Hello! Welcome to Tic-Tac-Toe!" << std::endl;
        std::cout << "You play the X and I play the O." << std::endl;
        std::cout << "If you want to quit \'q\' will let me know" << std::endl;
        std::cout << std::endl;

        //player first or second
            bool botFirst;
            int botTurn = 1;
            bool playerSelect = false;
            T3Board myGame;
            do {
                std::cout << "Would you like to go first('1') or second('2')?" << std::endl;
                std::cin >> playerInput;
                if (playerInput == '1') {
                    botFirst = false;
                    playerSelect = true;
                } else if (playerInput == '2') {
                    botFirst = true;
                    playerSelect = true;
                }
                if (!playerSelect) {
                    std::cout << "Please select a valid option" << std::endl;
                }
            } while (!playerSelect && playerInput != 'q');

            //play the game
            do {
                if (botFirst && botTurn == 1) {
                    std::cout << "AI is selecting a square..." << std::endl;
                    BotChoice(myGame, botFirst, botTurn);
                    botTurn++;
                }
                //player turn
                    myGame.PrintBoard(myGame);
                    std::cout << "Enter the space you would like to take." << std::endl;
                    std::cin >> playerInput;
                    InputChecker(playerInput, myGame);
                    myGame.gameWon = myGame.GameEnded();

                //bot turn
                if(playerInput != 'q') {
                    std::cout << "AI is selecting a square..." << std::endl;
                    BotChoice(myGame, botFirst, botTurn);
                    botTurn++;
                    myGame.gameWon = myGame.GameEnded();
                }

            } while (!myGame.gameWon && playerInput != 'q');
            myGame.PrintBoard(myGame);
            myGame.EndingPhrase(gamesPlayed);
            gamesPlayed++;
            if(playerInput != 'q') {
                std::cout << "Press 'q' to quit or any other key to play again." << std::endl;
                std::cin >> playerInput;
            }
    } while (playerInput != 'q');

    return 0;
}

char InputChecker(char inputChar, T3Board currentBoard) {
    bool validMove = false;
    while (!validMove) {
        if (inputChar == 'q') {
            return inputChar;
        }
        for (int i = 0; i < currentBoard.GetEmptySpaces().size(); i++) {
            if (currentBoard.GetEmptySpaces().at(i) == inputChar) {
                currentBoard.PlayerAddToBoard(inputChar);
                validMove = true;
                break;
            }
        }
        if (!validMove) {
            std::cout << "Please enter a valid choice" << std::endl;
            std::cin >> inputChar;
        }
    }
    return inputChar;
}

void BotChoice(T3Board currentBoard, bool start, int turn){
    if(start) {
        switch(turn){
            case 1:
                if(currentBoard.SpotIsEmpty(0,0)) {
                    currentBoard.BotAddToBoard(0, 0);
                }
                break;
            case 2:
                //if player doesn't choose middle
                if(currentBoard.SpotIsEmpty(1,1)) {
                    if(currentBoard.SpotIsEmpty(0,2)) {
                        currentBoard.BotAddToBoard(0, 2);
                    }
                    else {
                        currentBoard.BotAddToBoard(2, 0);
                    }
                }
                //if player chooses middle
                else {
                    currentBoard.BotAddToBoard(2,2);
                }
                break;
            case 3:
                if(!currentBoard.SpotIsEmpty(1,1)) {
                    if(currentBoard.SpotIsEmpty(0,2)) {
                        currentBoard.BotAddToBoard(0,2);
                    } else if(currentBoard.SpotIsEmpty(2,0)) {
                        currentBoard.BotAddToBoard(2,0);
                    } else if(currentBoard.SpotIsEmpty(2,2)) {
                        currentBoard.BotAddToBoard(2,2);
                    }
                } else {

                }
                break;
            case 4:

                break;
            case 5:

                break;
        }
    }
    else {
        switch(turn){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;

        }
    }
}
