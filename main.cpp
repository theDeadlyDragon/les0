#include <iostream>
#include <vector>
#include <string>
#include "main.h"



void createChessBoard(std::vector<std::vector<float> >& chessBoard, int ratio,int rWitdh, int rHeight){


    auto rectanglesWVar     = 5;
    bool rectanglesHVar  = true;


    for(int y = 0; y < chessBoard.size(); y++){
        if((y%rHeight) == 0)

            rectanglesHVar = !rectanglesHVar;

        if (rectanglesHVar)
            rectanglesWVar = 0;
        else if (!rectanglesHVar)
            rectanglesWVar = rWitdh;

        for(int x = 0; x < chessBoard[y].size(); x++){
            if(rectanglesWVar < rWitdh){
                chessBoard[y][x] = 1;
                rectanglesWVar++;
            }
            else if(rectanglesWVar == (2*rWitdh)-1){
                rectanglesWVar = 0;
            }
            else
                rectanglesWVar++;
        }
    }



}

void print2DVector(std::vector<std::vector<float> >& chessBoard){
    auto ascii = std::vector<std::string>({" ",".",":",",",":","-","=","+","*","#","%","@"});

    for(int y = 0; y < chessBoard.size(); y++){
        for(int x = 0; x < chessBoard[y].size(); x++){
            std::cout << ascii[chessBoard[y][x]*10];
        }
        std::cout << std::endl;
    }
}


int main() {
    std::cout << "Init program" << std::endl;

    //ratio = 2.5


    const auto heightChess   = 100;
    const auto widthChess    = 250;
    const auto ratio         = 2.5;

    //std::vector<std::vector<float>>* = new std::vector<std::vector<float>>;
    std::vector<std::vector<float> >  chessBoard(heightChess, std::vector<float>(widthChess,0));

    createChessBoard(chessBoard,ratio, 9,5);


    print2DVector(chessBoard);


    return 0;
}


