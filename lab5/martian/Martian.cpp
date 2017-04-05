//
// Created by mat on 30.03.17.
//
#include <iostream>
#include "Martian.h"

int Martian::liczbaMarsjan = 0;


Martian::Martian() {
    liczbaMarsjan++;
}

Martian::~Martian() {
    liczbaMarsjan--;
}

static bool Martian::shouldAttack() { return Martian::liczbaMarsjan >= 5; }

void Martian::attack() {
    std::cout<<"atakujemy!!\n";
}