#include <iostream>
#include "Punkt3d.h"

/*
 * zadanie 5:
 *  najpierw wywoływany jest konstruktor klasy bazowej( Point 2d)
 *  a następnie klasa pochodna, czyli Punkt 3d
 *  Destruktory wywoływane są w odwrotnej kolejności
 *  najpierw Point 3d, potem Point 2d
 */
/*
 * zadanie 6
 *  To dziwne wywołanie zwróci odlagłośc smiędzy punktami w postaci 2d
 */
/*
 * zadanie 7
 *  z racji tego że Punkt 3d nie ma zdefiniowanego operatora <<
 *  wywołany zostanie najbliższy operator z klasy bazowej
 */

using namespace geometry;

int main() {
//    Punkt3d a(1,0), b(2,1,1);
//    std::cout<<"Dist "<< a.Distance(b)<<"\n";

//    Point punkt2d(1,1);
//    Punkt3d punkt3d(1,0,0);
//
//    std::cout<<"pkt 2d i pkt 3d: "<<punkt2d.Distance(punkt3d)<<"\n";

    Punkt3d p3d(1,2,3);
    std::cout << p3d << std::endl;

    return 0;
}