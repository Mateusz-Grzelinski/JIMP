//
// Created by mat on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <iostream>

using std::string;
namespace academia {

    class StudyYear {
    public:
        //metody clasy:
        StudyYear() : studyyear_(1) {};
        StudyYear(int yr) : studyyear_(yr) {};
        int GetYear() const;

        //przciążone operatory:
        StudyYear &operator++();
        StudyYear operator++(int);
        StudyYear &operator--();
        StudyYear operator--(int);

        operator int() const;
        friend std::istream &operator>>(std::istream &is, StudyYear howlongread);
    private:
        int studyyear_;
    }; //end of class

    bool operator>(const StudyYear oneman, const StudyYear otherman );
    bool operator>=(const StudyYear oneman, const StudyYear otherman );
    bool operator<(const StudyYear oneman, const StudyYear otherman );
    bool operator<=(const StudyYear oneman, const StudyYear otherman );
//    bool operator==(const StudyYear oneman, const StudyYear otherman );
//    bool operator==(const StudyYear oneman, const int otherman );

    std::istream &operator>>(std::istream &is, StudyYear howlongread);
    std::ostream &operator<<(std::ostream &os, StudyYear howlong);



} //end of namespace
#endif //JIMP_EXERCISES_STUDYYEAR_H
