//
// Created by mat on 05.03.17.
//
#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10]){
    for(int x=0; x<10; x++)
        for (int y=0; y < 10; y++)
            tab[x][y]=(x+1)*(y+1);
}

void PrintMultiplicationTable(int tab[][10]){
    for(int x=0; x<10; x++) {
        for (int y=0; y < 10; y++)
            std::cout << tab[x][y]<<"\t";
        std::cout << std::endl;
    }
}
