//
// Created by mat on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <Point.h>

namespace geometry {

    class Square {
    public:
        Square(Point, Point, Point, Point);

//        ~Square(); //nie potrzebny

        double Circumference();

        double Area();

    private:
        Point one_;
        Point two_;
        Point three_;
        Point four_;

        void InsertSort(Point *tmpx[4]);
    };
}
#endif //JIMP_EXERCISES_SQUARE_H
