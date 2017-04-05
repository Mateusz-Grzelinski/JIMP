//
// Created by mat on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "StudyYear.h"
#include <string>
#include <iostream>
#include<initializer_list>


using std::string;
using std::initializer_list;

namespace academia {
    class Student {
    public:
        Student();
        Student(string id, string first, string last, string program, int y);
//        Student(initializer_list<Student> in);
//        ~Student();
        string Id()const;
        string FirstName()const;
        string LastName()const;
        string Program()const;
        StudyYear Year() const ;
        int StudentCount();
        void ChangeFirstName(string newfirstname);
        void ChangeLastName(string newlastname);
        void ChangeId(string newid);
        void ChangeProgram(string newprogram);
        void ChangeYear(int newyear);
        friend std::istream &operator>>(std::istream &is, Student &student);

    private:
        std::string id_, first_name_, last_name_, program_;
        StudyYear year_;

    }; //end of class

    bool operator==(const Student std, const Student std2);
    bool operator==(const Student std, string idtext);
    bool operator<(const Student std, const Student std2); //potrzebne do set
//    bool operator>(const Student std, const Student std2);
    std::istream &operator>>(std::istream &is, Student &student);
    std::ostream &operator<<(std::ostream &os, Student &student);








}//end of namespace

#endif //JIMP_EXERCISES_STUDENT_H
