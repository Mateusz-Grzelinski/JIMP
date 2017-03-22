//
// Created by mat on 22.03.17.
//

#ifndef JIMP_EXERCISES_NAME_H
#define JIMP_EXERCISES_NAME_H


#include <iostream>
#include <sstream>
#include <string>

using std::string;

class Name{
public:
    Name(string, string, string, string); //3 imiona i nazwisko
    Name(string, string, string);   // 2 imiona i nazwisko
    Name(string, string)    // 1 imię i nazwisko
    Name(string);    // wszystko podane razem
    std::string ToFullInitials();
    std::string ToFirstNamesInitials();
    std::string ToSurnameNames();
    std::string ToNamesSurname();
    bool IsBeforeBySurname();       //co to ma robić?
    bool IsBeforeByFirstName();
private:
    string FirstName_, SecondName_, ThirdName_;
    string Surname_;
};


#endif //JIMP_EXERCISES_NAME_H
