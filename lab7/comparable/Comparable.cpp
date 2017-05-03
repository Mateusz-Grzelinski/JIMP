//
// Created by mat on 18.04.17.
//

#include "Comparable.h"

namespace academia {
    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) {
        return (left.FirstName() < right.FirstName());
    }


    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) {
        return (left.FirstName() > right.FirstName());
    }

 

    bool ByLastNameAscending::IsLess(const Student &left, const Student &right) {
        return (left.LastName() < right.LastName());
    }


    bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) {
        if (left.Program()=="")
            return true;
        else if (right.Program()=="")
            return false;
        else
            return (left.Program() < right.Program());
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) {
        if (left.Program()=="")
            return false;
        else if (right.Program()=="")
            return true;
        else
            return (left.Program() < right.Program());
    }

    bool Comparable::operator()(const Student &left, const Student &right) {
        return IsLess(left, right);
    }

}
