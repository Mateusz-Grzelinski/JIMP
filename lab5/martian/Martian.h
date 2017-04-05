//
// Created by mat on 30.03.17.
//

#ifndef JIMP_EXERCISES_MARTIAN_H
#define JIMP_EXERCISES_MARTIAN_H

#include <iostream>

class Martian {
public:
    static int liczbaMarsjan;

    Martian();

    ~Martian();

    static bool shouldAttack();

    void attack();
};


#endif //JIMP_EXERCISES_MARTIAN_H
