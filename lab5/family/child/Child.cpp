//
// Created by mat on 29.03.17.
//

#include "Child.h"

namespace family {
    Child::Child(std::string name, std::string surname, int age, std::string school) :
            name_(name), surname_(surname), age_(age), school_(school) {
        std::cout << "tworze dziecko\n";
    }

    Child::~Child() {std::cout<<"Niszcze dziecko. Buhaha!!"<<std::endl; }

    void Child::ChangeSchool(std::string school) {
        school_ = school;
    }

    std::ostream &operator<<(std::ostream &out, const Child toprint) {
        return out <<"Dziecko: "<< toprint.name_ << ", " << toprint.surname_ << " " << toprint.age_ <<", "<<toprint.school_<< std::endl;
    }
}