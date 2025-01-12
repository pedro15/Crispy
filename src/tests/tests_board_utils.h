#include <iostream>
#include "../Types.h"
#include "../BoardUtils.h"

namespace tests_board_utils 
{
    static bool IsDistancesValid()
    {
        uint8_t dist;
        Square a,b;

        a = Square::a1;
        b = Square::h8;
        dist = BoardUtils::DISTANCE[a][b];

        if(dist != 7)
        {
            std::cout << "[ERROR] distance between a1 and h8 is not valid: " <<  (int)dist << std::endl;
            return false;
        }

        a = Square::a1;
        b = Square::a3;
        dist = BoardUtils::DISTANCE[a][b];
        
        if (dist != 2)
        {
            std::cout << "[ERROR] distance between a1 and a3 is not valid: " << (int)dist << std::endl;
            return false;
        }

        a = Square::d4;
        b = Square::c3;
        dist = BoardUtils::DISTANCE[a][b];

        if (dist != 1)
        {
            std::cout << "[ERROR] distance between d4 and c3 is not valid: " << (int)dist << std::endl;
            return false;
        }

        a = Square::c3;
        b = Square::f6;
        dist = BoardUtils::DISTANCE[a][b];
        if (dist != 3)
        {
            std::cout << "[ERROR] distance between c3 and f6 is not valid: " << (int)dist << std::endl;
            return false;
        }
        return true;
    }
}