//
// Created by mat on 05.03.17.
//


#include "MultiplicationTable.h"

int main(){
    std::cout<<"Tablica mnożenia (dwuwymiarowa): "<<std::endl;
    int tablica_probna[10][10]={ {1,2,3} };
    MultiplicationTable(tablica_probna);
    PrintMultiplicationTable(tablica_probna);
    return 0;
}