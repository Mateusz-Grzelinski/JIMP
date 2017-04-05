//
// Created by mat on 05.04.17.
//

#include "StudentRepository.h"

namespace academia {
    StudentRepository::StudentRepository(initializer_list<Student> in) {
        studentcontainer_.assign(in);
    }
    void StudentRepository::AddStudent(Student &in) {
        studentcontainer_.push_back(in);
    }
    void StudentRepository::RemoveStudent(std::string outbyid) {
        bool flag = true;
        int i=0;
        while  ( i < studentcontainer_.size() && flag) {
            if (studentcontainer_[i].Id()==outbyid)
                flag=false;
            i++;
        }
        if (!flag)
            studentcontainer_.erase(studentcontainer_.begin()+i);
    }
    void StudentRepository::RemoveStudent(Student out) {
        std::string outbyid=out.Id();
        this->RemoveStudent(outbyid);
    }

    Student *StudentRepository::operator[](std::string &searchfor) {
        bool flag = true;
        int i=0;
        while  ( i < studentcontainer_.size() && flag) {
            if (studentcontainer_[i].Id()==searchfor)
                flag=false;
            i++;
        }
        if (!flag)
            return &studentcontainer_[i];
        else {
            auto tmp = Student();
            return &tmp;
        }
    }
    
}