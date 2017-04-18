//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_PUNKT3D_H
#define JIMP_EXERCISES_PUNKT3D_H

#include <Point.h>

namespace geometry {

    class Punkt3d : public Point{
    public:
        Punkt3d():Point(), z_(0) { std::cout<<"tworze pkt3d\n"; }
        Punkt3d(double x=0, double y=0, double z=0): Point(x,y), z_(z) { std::cout<<"tworze pkt3d\n"; }
        ~Punkt3d(){ std::cout<<"niszcze pkt3d\n"; }

        double GetZ() const;
        void SetZ(double z);
        double Distance(const Punkt3d &other) const;

    private:
        double z_;
    };
}

#endif //JIMP_EXERCISES_PUNKT3D_H
