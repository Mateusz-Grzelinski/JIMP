//
// Created by mat on 29.03.17.
//

#ifndef JIMP_EXERCISES_PARENT_H
#define JIMP_EXERCISES_PARENT_H

#include <iostream>
#include <string>
#include <Child.h>

namespace family {
    class Parent {
        friend Child;
    public:
        Parent(std::string name = "tata", std::string surname = "Pat", int age=44);
        ~Parent();
        void GiveChild(Child newone);

        void SetChildParam(std::string name = "Ala", std::string surname = "Gog", int age = 7,
                           std::string school = "Przedszkole");

        friend std::ostream &operator<<(std::ostream &out, const Parent toprint);

    private:
        std::string name_, surname_;
        int page_;
        Child parentchild_;
    };

}
#endif //JIMP_EXERCISES_PARENT_H
