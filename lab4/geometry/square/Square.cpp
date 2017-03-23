//
// Created by mat on 21.03.17.
//

#include <Point.h>
#include "Square.h"


namespace geometry {
    Square::Square(Point first, Point second, Point third, Point foutrh) {
//        tworzę tablicę, aby ją posortować. Jakieś lepsze rozwiązanie?
        Point *points[4];
        points[0] = &first;
        points[1] = &second;
        points[2] = &third;
        points[3] = &foutrh;

//        posortuj punkty według współrzędnej X
        InsertSort(points);

//        w posortowanym ciągu, wierzchołki kwadratu łączą się: 1-2, 1-3, 3-4, 2-4
        double dist01 = points[0]->Distance(*points[1]);
        double dist02 = points[0]->Distance(*points[2]);
        double dist23 = points[2]->Distance(*points[3]);
        double dist13 = points[1]->Distance(*points[3]);
        double diag01 = points[0]->Distance(*points[3]); //diagonal- przekątna
        double diag12 = points[1]->Distance(*points[2]); //diagonal
        if (dist01 == dist02 &&
            dist23 == dist13 &&
            dist01 == dist23)
            if (diag01==diag12){
            //jeśli kwadrat(i nie romb), to przepisz wartości:
            one_ = *points[0];
            two_ = *points[1];
            three_ = *points[2];
            four_ = *points[3];
        }
    }

    void Square::InsertSort(Point *tmpx[4]) {
        Point *swaptmp;
        for (int i = 1, j = i; i < 4; i++, j = i) {
            while (tmpx[j]->GetX() < tmpx[j - 1]->GetX() && j > 0) {
                swaptmp = tmpx[j];
                tmpx[j] = tmpx[j - 1];
                tmpx[j - 1] = swaptmp;
            }
        }
    }

    double Square::Circumference() {
        return 4 * one_.Distance(two_);
    }


    double Square::Area() {
        double side = one_.Distance(two_);
        return side * side;
    }
}