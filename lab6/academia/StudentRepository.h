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
    public:
        StudentRepository(initializer_list<Student> in);
        void AddStudent(Student &in);
        void RemoveStudent(Student out);
        void RemoveStudent(std::string outbyid);
        int StudentCount();

        Student &operator[]( const std::string &searchforid);

        friend bool operator==(StudentRepository &firstrep, StudentRepository &secondrep);
    private:
        std::vector<Student> studentcontainer_;

    };

    bool operator==(StudentRepository &firstrep, StudentRepository &secondrep);
std::ostream &operator<<(std::ostream &os, StudentRepository stdrep);
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
