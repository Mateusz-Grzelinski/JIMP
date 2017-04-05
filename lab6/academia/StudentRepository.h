//
// Created by mat on 05.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include <set>
#include <vector>
#include <string>
#include "Student.h"

namespace academia {
    class StudentRepository {
//        friend class Student;
    public:
        StudentRepository(initializer_list<Student> in);
        void AddStudent(Student &in);
        void RemoveStudent(Student out);
        void RemoveStudent(std::string outbyid);


        Student *operator[](std::string &searchfor);

    private:
        std::vector<Student> studentcontainer_;

    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
