#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_
#include <iostream>
#include <cmath>
#include <ostream>

namespace geometry {
    class Point {
    public:
        Point();

        Point(double x, double y);

        ~Point();

        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;

        double GetX() const;

        double GetY() const;

        void SetX(double x);

        void SetY(double y);

        friend std::ostream& operator<<(std::ostream& out, const Point &other);
    private:
        double x_, y_;
    };

    std::ostream& operator<<(std::ostream& out, const Point &other);
}
#endif  // PROJECTNAME_PATH_POINT_H_