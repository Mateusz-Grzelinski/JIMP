//
// Created by mat on 29.03.17.
//

#ifndef JIMP_EXERCISES_CHILD_H
#define JIMP_EXERCISES_CHILD_H

#include<iostream>
#include <string>

//extern class Parent;
namespace family {
    class Child {
        friend class Parent;
    public:
        Child(std::string name="Ala", std::string surname="Gog", int age=7, std::string school="Przedszkole");

        ~Child();

        void ChangeSchool(std::string school="Nowa szkoła");
        friend std::ostream &operator<<(std::ostream &out, const Child toprint);
        
    private:
        std::string name_, surname_,  school_;
        int age_;
    };

}
#endif //JIMP_EXERCISES_CHILD_H
