//
// Created by mat on 18.04.17.
//

#include "StudentRepositoryQueries.h"

namespace academia{
    bool ByFirstName::Accept(const Student &student) const {
        return (student.FirstName()==firstname_);
    }

    bool ByLastName::Accept(const Student &student) const {
        return (student.LastName()==lastname_);
    }

    bool ByOneOfPrograms::Accept(const Student &student) const {
        bool flag=false;
        for (auto &&item : program_) {
            flag=(student.Program()==item);
            if (flag)
                return flag;
        }
        return flag;
    }

    bool ByYearLowerOrEqualTo::Accept(const Student &student) const {
        return (student.Year().GetYear()<=year_.GetYear());
    }


//    bool OrQuery::Accept(const Student &student) const {
//        bool flag = false;
//        for (auto &condit : conditions_) {
//            flag=condit.Accept(student);
//            if (flag)
//                return true;
//        }
//        return false;
//    }

    bool AndQuery::Accept(const Student &student) const {
        bool flag = true;
        for (auto &condit : conditions_) {
            flag=condit.Accept(student);
            if (!flag) //jesli choc jedno jest false
                return false;
        }
        return true;
    }
}