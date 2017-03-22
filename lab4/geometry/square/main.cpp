//
// Created by mat on 22.03.17.
//

#include "Square.h"

int main(){
    Square object(Point (0, 1), Point (0, 0), Point (1, 1), Point (1, 0) );
    std::cout<<"dodbrze\n\n\n";
    std::cout<< "powierznia: "<<object.Area() <<" obwód: "<< object.Circumference();

    return 0;
}