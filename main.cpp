#include <iostream>
#include <vector>
#include <string>
#include "main.h"



void createChessBoard(std::vector<std::vector<float>>& chessBoard, int squareSize){


    auto rectangles = 0;


    for(int y = 0; y < chessBoard.size(); y++){
        for(int x = 0; x < chessBoard[y].size(); x++){
            if(rectangles == 10){
                rectangles = 0;
            }

            else if(rectangles>4){
                chessBoard[y][x] = 1;
                rectangles++;
            }
            else
                rectangles++;
        }
    }



}

void print2DVector(std::vector<std::vector<float>>& chessBoard){
    for(int y = 0; y < chessBoard.size(); y++){
        for(int x = 0; x < chessBoard[y].size(); x++){
            std::cout << chessBoard[y][x];
        }
        std::cout << std::endl;
    }
}


int main() {
    std::cout << "Init program" << std::endl;

    //ratio = 2.5

    const auto heightChess   = 100;
    const auto widthChess    = 250;
    const auto radiusCircle  = 0;

    //std::vector<std::vector<float>>* = new std::vector<std::vector<float>>;
    std::vector<std::vector<float>>  chessBoard(heightChess, std::vector<float>(widthChess,0));

    createChessBoard(chessBoard,0);


    print2DVector(chessBoard)


    return 0;
}


