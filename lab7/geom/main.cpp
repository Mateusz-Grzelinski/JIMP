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
#include <memory>

using namespace std;

int main() {
    Kula kl(0, 0, 0, 10);
    Triangle tr;
    std::cout << "pole kuli: " << kl.Pole()<<std::endl;
    std::cout << "pole przekroju: " << kl.Kolo::Pole();

    list<unique_ptr<Shape>> shapelist;

    for (int i = 0; i < 10; ++i) {
        switch (rand()%4){
            case 0: {
                shapelist.push_back( make_unique<Triangle>() );
                break;
            }
            case 1: {
                shapelist.push_back( make_unique<Kolo>() );
                break;
            }
            case 2: {
                shapelist.push_back(make_unique<Kula>() );
                break;
            }
            case 3: {
                shapelist.push_back(make_unique<Square>() );
                break;
            }
            default: {
                cout<<"error";
            }
        }
    }

    for (auto &&item : shapelist) {
        item->Draw();
    }
    return 0;
}