//
// Created by mat on 29.03.17.
//

#include "Parent.h"

namespace family {
    Parent::Parent(std::string name, std::string surname, int age) :
            name_(name), surname_(surname), page_(age) {}


    void Parent::GiveChild(Child &newone) {
        parentchild_ = &newone;
    }
    Parent::~Parent() {std::cout<<"rodzic ginie"<<std::endl; }


    void Parent::SetChildParam(std::string name, std::string surname, int age, std::string school) {
        parentchild_->age_=age;
        parentchild_->name_=name;
        parentchild_->surname_=surname;
        parentchild_->school_=school;
    }

    std::ostream &operator<<(std::ostream &out, const Parent toprint) {
        return out <<"Rodzic: "<< toprint.name_ << ", " << toprint.surname_ << ", " << toprint.page_ << std::endl;
    }


}