//
// Created by mat on 18.04.17.
//
#include <list>
#include <random>
#include <iostream>
#include "Kolo.h"
#include "Kula.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

int main() {
    Kula kl(0, 0, 0, 10);
    Triangle tr;
    tr.Draw();
    std::cout << "pole kuli: " << kl.Pole()<<std::endl;
    std::cout << "pole przekroju: " << kl.Kolo::Pole();

    list<Shape> shapelist; //gdzie tu jest haczyk?

    for (int i = 0; i < 10; ++i) {
        switch (rand()%4){
            case 0: {
                shapelist.push_back(Triangle() );
                break;
            }
            case 1: {
                shapelist.push_back(Kolo() );
                break;
            }
            case 2: {
                shapelist.push_back(Kula() );
                break;
            }
            case 3: {
                shapelist.push_back(Square() );
                break;
            }
            default:{
                cout<<"error";
            }
        }

    }

    return 0;
}