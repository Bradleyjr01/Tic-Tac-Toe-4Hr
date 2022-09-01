//
// Created by brdly on 8/31/2022.
//
#include <iostream>
#include "T3Board.h"

void T3Board::PrintBoard(const T3Board& currentGame) {
    for(int row = 0; row < BOARD_DIMENSION; row++) {
        for(int col = 0; col < BOARD_DIMENSION; col++) {
            PrintLocation(row,col);
        }
        std::cout << std::endl;
    }
}

void T3Board::PlayerAddToBoard(char space) {
    bool added = false;

    for(int row = 0; row < BOARD_DIMENSION; row++) {
        for(int col = 0; col < BOARD_DIMENSION; col++) {
            if(this->myBoard[row][col] == space){
                this->myBoard[row][col] = 'X';
                added = true;
                for(int i = 0; i < this->emptySpaces.size(); i++) {
                    if(this->emptySpaces.at(i) == space){
                        this->emptySpaces.erase(this->emptySpaces.begin() + i);
                    }
                }
                break;
            }
            if(added){
                break;
            }
        }
    }
}


bool T3Board::SpotIsEmpty(int row, int col) {
    if ((myBoard[row][col] == 'X') || (myBoard[row][col] == 'O')) {
        return false;
    } else {
        return true;
    }
}

void T3Board::PrintLocation(int row, int col) {
    std::cout << " " << this->myBoard[row][col] << " ";
}

std::vector<char> T3Board::GetEmptySpaces() {
    return this->emptySpaces;
}

bool T3Board::GameEnded() {
    //check rows
    for (int col = 0; col < BOARD_DIMENSION; col++) {
        if ((this->myBoard[0][col] == this->myBoard[1][col]) && (this->myBoard[0][col] == this->myBoard[2][col])){
            switch(this->myBoard[0][col]){
                case 'X':
                    this->gameWinner = "Player";
                    break;
                case 'O':
                    this->gameWinner = "AI";
                    break;
            }
            return true;
        }
    }

    //check columns
    for (int row = 0; row < BOARD_DIMENSION; row++) {
        if ((this->myBoard[row][0] == this->myBoard[row][1]) && (this->myBoard[row][0] == this->myBoard[row][2])){
            switch(myBoard[row][0]){
                case 'X':
                    this->gameWinner = "Player";
                    break;
                case 'O':
                    this->gameWinner = "AI";
                    break;
            }
            return true;
        }
    }

    //check diagonals
        if ((this->myBoard[0][0] == this->myBoard[1][1]) && (this->myBoard[0][0] == this->myBoard[2][2])){
            switch(myBoard[0][0]){
                case 'X':
                    this->gameWinner = "Player";
                    break;
                case 'O':
                    this->gameWinner = "AI";
                    break;
            }
            return true;
        }
    if ((this->myBoard[0][2] == this->myBoard[1][1]) && (this->myBoard[0][2] == this->myBoard[2][0])){
        switch(this->myBoard[0][0]){
            case 'X':
                this->gameWinner = "Player";
                break;
            case 'O':
                this->gameWinner = "AI";
                break;
        }
        return true;
    }
    if(this->emptySpaces.empty()){
        this->gameWinner = "Tie";
        return true;
    }

    return false;
}

void T3Board::BotAddToBoard(int row, int col) {
    char removeMe = this->myBoard[row][col];
    this->myBoard[row][col] = 'O';
    for(int i = 0; i < this->emptySpaces.size(); i++) {
        if(this->emptySpaces.at(i) == removeMe){
            this->emptySpaces.erase(this->emptySpaces.begin() + i);
        }
    }
}

void T3Board::EndingPhrase(int gamesPlayed) {
    if(this->gameWinner == "Tie") {
        std::cout << "This game was a tie." << std::endl;
    } else if(this->gameWinner == "AI"){
        std::cout << "I won!" << std::endl;
    } else if(this->gameWinner == "Player"){
        std::cout << "You won! I'll get you next time." << std::endl;
    } else {
        std::cout << "Thanks for playing. We'll have our rematch later!" << std::endl;
    }
    std::cout << "You have played " << gamesPlayed << " games." << std::endl;
}