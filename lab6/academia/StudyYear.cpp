//
// Created by mat on 04.04.17.
//

#include "StudyYear.h"

namespace academia {

    int StudyYear::GetYear() const { return studyyear_; }

    StudyYear &StudyYear::operator++(){
        ++studyyear_;
    }
    StudyYear StudyYear::operator++(int){
        studyyear_++;
    }
    StudyYear &StudyYear::operator--(){
        if (studyyear_>0)
            --studyyear_;
    }
    StudyYear StudyYear::operator--(int){
        if (studyyear_>0)
            studyyear_--;
    }

    bool operator>(const StudyYear oneman, const StudyYear otherman ){
        return (oneman.GetYear()>otherman.GetYear());
    }
    bool operator>=(const StudyYear oneman, const StudyYear otherman ){
        return (oneman.GetYear()>=otherman.GetYear());
    }
    bool operator<(const StudyYear oneman, const StudyYear otherman ){
        return (oneman.GetYear()<otherman.GetYear());
    }
    bool operator<=(const StudyYear oneman, const StudyYear otherman ){
        return (oneman.GetYear()<=otherman.GetYear());
    }
    bool operator==(const StudyYear oneman, const StudyYear otherman){
        return (oneman.GetYear()==otherman.GetYear());
    }

    std::istream &operator>>(std::istream &is, StudyYear howlongread){
        is>>howlongread.studyyear_;
        return is;
    }

    std::ostream &operator<<(std::ostream &os, StudyYear howlong) {
        os << howlong.GetYear();
    }

}//end of namespace