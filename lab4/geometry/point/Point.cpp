//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <ostream>
#include <ostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using std::cout;
/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::" 
*/


namespace geometry {
    Point::Point() : x_(0), y_(0) {
  cout << "Konstruktor bezparametrowy 2d" << endl;
    }

    Point::Point(double x, double y) {
        std::cout<<"tworze Point2d\n";
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
  cout << "Destruktor 2d! ";
  cout << endl;
    }

    double Point::GetX() const {
        return this->x_;
    }

    double Point::GetY() const {
        return this->y_;
    }

    void Point::SetX(double x) {
        this->x_ = x;
    }

    void Point::SetY(double y) {
        this->y_ = y;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(std::ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    std::ostream& operator<<(std::ostream& out, const Point &other){
        out<<"("<<other.GetX()<<", "<<other.GetY()<<")";
    }

}