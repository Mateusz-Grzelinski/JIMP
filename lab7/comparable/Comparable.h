//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include <StudentRepository.h>

namespace academia {
    class Comparable {
    public:
        virtual bool IsLess(const Student &left, const Student &right)=0;
        bool operator()(const Student &left, const Student &right);
    };


    class ByFirstNameAscending : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override ;

    };

    class ByFirstNameDescending : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByLastNameAscending : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyFirst : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyLast : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

}

#endif //JIMP_EXERCISES_COMPARABLE_H
