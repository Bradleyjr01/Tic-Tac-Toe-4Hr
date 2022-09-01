//
// Created by brdly on 8/31/2022.
//

#ifndef TIC_TAC_TOE_T3BOARD_H
#define TIC_TAC_TOE_T3BOARD_H
#include <vector>

const int BOARD_DIMENSION = 3;
class T3Board {
    private:
        char myBoard[BOARD_DIMENSION][BOARD_DIMENSION];
        std::vector<char> emptySpaces;
        std::string gameWinner;

    public:
        T3Board(){
            gameWon = false;
            char counter = 49;
            for(int row = 0; row < BOARD_DIMENSION; row++){
                for(int col = 0; col < BOARD_DIMENSION; col++) {
                    myBoard[row][col] = counter;
                    emptySpaces.push_back(counter);
                    counter++;
                }
            }
        }
        bool gameWon;
        void PrintBoard(const T3Board& currentGame);
        void PlayerAddToBoard(char space);
        void BotAddToBoard(int row, int col);
        bool SpotIsEmpty(int row, int col);
        void PrintLocation(int row, int col);
        std::vector<char> GetEmptySpaces();
        bool GameEnded();
        void EndingPhrase(int gamesPlayed);
};


#endif //TIC_TAC_TOE_T3BOARD_H
