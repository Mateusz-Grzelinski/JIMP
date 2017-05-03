//
// Created by mat on 27.04.17.
//

#include "BallException.h"

#include <iostream>
using namespace std;

void drawBall() {
    throw BallException();
}

int main() {
    try {
        drawBall();
    } catch (const BallException &b) {
        cout << "Blad podczas rysowania kuli" << endl;
    } catch (const CircleException &a) {
        cout << "Blad podczas rysowania kola" << endl;
    }
}
