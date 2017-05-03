//
// Created by mat on 27.04.17.
//

#ifndef JIMP_EXERCISES_BALLEXCEPTION_H
#define JIMP_EXERCISES_BALLEXCEPTION_H
class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};
class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};
void drawBall();

#endif //JIMP_EXERCISES_BALLEXCEPTION_H
