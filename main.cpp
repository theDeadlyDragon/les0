#include <iostream>
#include <vector>
#include <string>
#include "main.h"
#include <cstdlib>
#include<cmath>



void createChessBoard(std::vector<std::vector<float> >& chessBoard,std::vector<std::vector<std::vector<int> > >& cor,int rWitdh, int rHeight){

    int corX = 0;
    int corY = 0-(chessBoard.size()/2);
    std::cout << corY << std::endl;


    auto rectanglesWVar     = 5;
    bool rectanglesHVar  = true;


    for(int y = 0; y < chessBoard.size(); y++){
        corX = 0-(chessBoard[0].size()/2);
        //check if y by height of block
        if((y%rHeight) == 0)
            rectanglesHVar = !rectanglesHVar;
        //change start value
        if (rectanglesHVar)
            rectanglesWVar = 0;
        else if (!rectanglesHVar)
            rectanglesWVar = rWitdh;

        //create cor system
        corY++;

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

            //cor system
            cor[y][x] = {corY,corX};
            corX++;

        }
    }



}

void createDonut(std::vector<std::vector<float> >& chessBoard,std::vector<std::vector<std::vector<int> > >& cor){
    int var = 0;
    for(int y = 0; y < cor.size(); y++){
        for(int x = 0; x < cor[y].size(); x++){
            //std::cout << sqrt(pow(cor[y][x][0],2)+pow(cor[y][x][1],2)) << " " << cor[y][x][0]<< ":" << cor[y][x][1]<< std::endl;
            var = sqrt(pow(cor[y][x][0],2)+pow(cor[y][x][1],2));
            if( 40 == var ){
                chessBoard[y][x] = 3;
                std::cout << "help  ";
            }

        }
    }
}



void print2DVector(std::vector<std::vector<float> >& chessBoard){
    std::string ascii =  " .\'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@";

    for(int y = 0; y < chessBoard.size(); y++){
        for(int x = 0; x < chessBoard[y].size(); x++){
            std::cout << ascii.at(chessBoard[y][x]*10);
        }
        std::cout << std::endl;
    }
}


void print3DVector(std::vector<std::vector<std::vector<int> > >& cor){
    std::string ascii =  " .\'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@";

    for(int y = 0; y < cor.size(); y++){
        for(int x = 0; x <  cor[y].size(); x++){

            std::cout << cor[y][x][0] << "," << cor[y][x][1] << " . ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::cout << "Init program" << std::endl;

    //ratio = 2.5


    const auto heightChess   = 101;
    const auto widthChess    = 251;
    const auto ratio         = 2.5;

    //std::vector<std::vector<float>>* = new std::vector<std::vector<float>>;
    std::vector<std::vector<float> >  chessBoard(heightChess, std::vector<float>(widthChess,0));
    auto coordinaten = (std::vector(heightChess, std::vector(widthChess,std::vector<int>(2,0))));

    std::vector<std::vector<float> >  donut(heightChess, std::vector<float>(widthChess,0));

    createChessBoard(chessBoard,coordinaten, 9,5);


    //
    //print3DVector(coordinaten);
    createDonut(chessBoard,coordinaten);
    print2DVector(chessBoard);

    return 0;
}


