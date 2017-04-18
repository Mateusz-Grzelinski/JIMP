//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include <StudentRepository.h>

namespace academia {
    class Comparable {
        virtual bool IsLess(const Student &left, const Student &right)=0;
    };


    class ByFirstNameAscending : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override ;
        bool operator()(const Student &left, const Student &right);
    };

    class ByFirstNameDescending : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
        bool operator()(const Student &left, const Student &right);
    };

    class ByLastNameAscending : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
        bool operator()(const Student &left, const Student &right);
    };

    class ByProgramAscendingEmptyFirst : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
        bool operator()(const Student &left, const Student &right);
    };

    class ByProgramAscendingEmptyLast : public Comparable {
    public:
        bool IsLess(const Student &left, const Student &right) override;
        bool operator()(const Student &left, const Student &right);
    };

}

#endif //JIMP_EXERCISES_COMPARABLE_H
