//
// Created by mat on 21.03.17.
//

#include <Point.h>
#include "Square.h"


//using namespace geometry;
Square::Square(Point first, Point second, Point third, Point foutrh){
    first.Distance(second);
    Point *points[4];
    //tworzę tablicę, aby ją posortować. Jakieś lepsze rozwiązanie?
    points[0]=&first;
    points[1]=&second;
    points[2]=&third;
    points[3]=&foutrh;
//    posortuj punkty według współrzędnej X
    InsertSort(points);
    //w posortowanym ciągu, wierzchołki kwadratu łączą się: 1-2, 1-3, 3-4, 2-4
    if (points[0]->Distance(*points[1])==
            points[0]->Distance(*points[2])==
            points[2]->Distance(*points[3])==
            points[1]->Distance(*points[3]) ){
        //przepisz wartości:
        one.SetX( points[0]->GetX() );
        one.SetY( points[0]->GetY() );
        two.SetX( points[1]->GetX() );
        two.SetY( points[1]->GetY() );
        three.SetX( points[2]->GetX() );
        three.SetY( points[2]->GetY() );
        four.SetX( points[3]->GetX() );
        four.SetY( points[4]->GetY() );
    }
}

void Square::InsertSort(Point *tmpx[4]) {
    Point *swaptmp;
    std::cout<<"sortuję";
    for (int i=1, j=i; i<4; i++, j=i){
        while ( tmpx[j]->GetX()<tmpx[j-1]->GetX() && j>0){
            swaptmp= tmpx[j];
            tmpx[j] = tmpx[j-1];
            tmpx[j-1] = swaptmp;
         }
    }
}

double Square::Circumference(){
    return 4*one.Distance(two);
}


double Square::Area(){
    double side= one.Distance(two);
    return side*side;
}