//
// Created by mat on 04.04.17.
//
#include <string>
#include <iostream>
#include "StudyYear.h"
#include "Student.h"

using std::string;
namespace academia {
    //kostruktory:
    Student::Student() { }
    Student::Student(string id, string first, string last, string program, int y) : id_(id), first_name_(first), last_name_(last), program_(program), year_(y) {}

    //dostęp do poszczególnych pól:
    string Student::Id() const { return id_; }
    string Student::FirstName() const { return first_name_; }
    string Student::LastName() const {return last_name_; }
    string Student::Program() const {return program_; }
    StudyYear Student::Year() const { return year_; }
    void Student::ChangeLastName(string newsurname) { last_name_=newsurname; }

    //przładowanie operatorów:
    bool operator==(const Student std, const Student std2){
        return (std.Year()==std2.Year());
    }

    std::istream &operator>>(std::istream &is, Student &student) {
//        is>>student.id_>>student.first_name_>>student.last_name_>>student.program_>>student.year_;
//        IgnoreWaste(is);
//        ReadString(is, student);
    }

    std::ostream &operator<<(std::ostream &os, Student &student) {
        os << "Id: "<<student.Id();
        os << "First name: "<<student.FirstName();
        os << "Lastname: "<<student.LastName();
        os << "Program: "<<student.Program();
        os << "Year: "<<student.Year();
    }

}//end of namespace


