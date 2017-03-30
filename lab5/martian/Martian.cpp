//
// Created by mat on 30.03.17.
//

#include "Martian.h"

int Martian::liczbaMarsjan = 0;


Martian::Martian() {
    liczbaMarsjan++;
}

Martian::~Martian() {
    liczbaMarsjan--;
}

static bool shouldAttack() { return Martian::liczbaMarsjan >= 5; }

void Martian::attack() {
    //jak atakować?
}