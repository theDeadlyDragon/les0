#include <iostream>
#include <vector>
#include <string>
#include "main.h"
#include <cstdlib>
#include<cmath>
#include <tuple>



std::vector<int> createChessBoard(std::vector<std::vector<std::vector<float> > >& chessBoard,int ratio, int rHeight){

    int rWidth = rHeight*ratio;
    int corX = 0;
    int corY = (chessBoard.size()/2);
    int mX = 0;
    int mY = 0;
    auto zeroPoint = std::vector<int> ({0,0});
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
            rectanglesWVar = rWidth;

        //create cor system
        corY--;

        for(int x = 0; x < chessBoard[y].size(); x++){
            if(rectanglesWVar < rWidth){
                chessBoard[y][x][0] = 15;
                rectanglesWVar++;
            }
            else if(rectanglesWVar == (2*rWidth)-1){
                rectanglesWVar = 0;
            }
            else
                rectanglesWVar++;

            //cor system
            chessBoard[y][x][1] = corY;
            chessBoard[y][x][2] = (int)(corX/ratio);

            if(corX== 0 && corY == 0){
                zeroPoint[1] = y;
                zeroPoint[0] = x;
                std::cout<< y << ":" << x << std::endl;

            }

            corX++;

        }
    }


    return zeroPoint;
}

void createDonut(std::vector<std::vector<std::vector<float> > >& chessBoard, int maxRadius, int minRadius){
    int var = 0;

    int calcWidth   = (chessBoard[0].size()/2);
    int calcHeight  = (chessBoard.size()/2);


    for(int y = 0; y < chessBoard.size(); y++){
        for(int x = 0; x < chessBoard[y].size(); x++){



            var = sqrt(pow(chessBoard[y][x][1],2)+pow(chessBoard[y][x][2],2));

            if(minRadius<= var && maxRadius>= var){
                chessBoard[y][x][0] = chessBoard[y][x][0]+ 20;
                //std::cout << sqrt(pow(cor[y][x][0],2)+pow(cor[y][x][1],2)) << " " << cor[y][x][0]<< ":" << cor[y][x][1]<< std::endl;

                //std::cout << "help  ";
            }

        }
    }
}



void print2DVector(std::vector<std::vector<std::vector<float> > >& chessBoard){
    std::string ascii =  " .\'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@";

    for(int y = 0; y < chessBoard.size(); y++){
        for(int x = 0; x < chessBoard[y].size(); x++){
            std::cout << ascii.at(chessBoard[y][x][0]);
        }
        std::cout << std::endl;
    }
}


void print3DVector(std::vector<std::vector<std::vector<float> > >& cor){
    std::string ascii =  " .\'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@";

    for(int y = 0; y < cor.size(); y++){
        for(int x = 0; x <  cor[y].size(); x++){

            std::cout << cor[y][x][1] << "," << cor[y][x][2] << " . ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::cout << "Init program" << std::endl;

    //ratio = 2.5


    const auto heightChess   = 100;
    const auto widthChess    = 200;
    const auto ratio         = 2;
    auto zeroPoint = std::vector<int> ({0,0});
    //auto chessZeroX = 0;
    //auto chessZeroY = 0;

    std::vector<std::vector<std::vector<float> > >  chessBoard(heightChess, std::vector<std::vector<float> >(widthChess,std::vector<float>(3,0)));

    zeroPoint = createChessBoard(chessBoard, ratio,5);

    std::cout << zeroPoint[0] << ":" << zeroPoint[1] << std::endl;
    //

    //createDonut(chessBoard);
    //print3DVector(chessBoard);
    print2DVector(chessBoard);

    return 0;
}


