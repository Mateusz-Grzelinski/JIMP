//
// Created by mat on 22.03.17.
//


#include <iostream>
#include <sstream>
#include <string>
#include "Name.h"

using std::string;

Name::Name(std::string FN, string SN, string TN, string S):
        FirstName_(FN), SecondName_(SN), ThirdName_(TN), Surname_(S) {}
Name::Name(string FN, string SN, string S):
        FirstName_(FN), SecondName_(SN),Surname_(S) {
    ThirdName_="";
}
Name::Name(string FN, string S): FirstName_(FN), Surname_(S){
    ThirdName_=SecondName_="";
}
Name::Name(string fullname){
    std::stringstream ss(fullname);
    ss>>FirstName_;
    ss>>Surname_;
    if (!ss.str().empty()){
        SecondName_=Surname_;
        ss>>Surname_;
    }
    if (!ss.str().empty()){
        ThirdName_=Surname_;
        ss>>Surname_;
    }

}
std::string Name::ToFullInitials(){
    std::stringstream ss;
    ss<< FirstName_.front()<<". ";
    ss<< SecondName_.front()<<". ";
    ss<< ThirdName_.front()<< ". ";
    ss<< Surname_.front()<< ". ";
    return ss.str();
}
std::string Name::ToFirstNamesInitials(){
    std::stringstream ss;
    ss<< FirstName_.front()<<". ";
    ss<< Surname_.front()<< ". ";
    return ss.str();
}
std::string Name::ToSurnameNames(){
    std::stringstream ss;
    ss<< Surname_<< " "<<FirstName_ <<" "<< SecondName_<< " "<< ThirdName_;
    return ss.str();
}
std::string Name::ToNamesSurname(){
    std::stringstream ss;
    ss<< FirstName_ <<" "<< SecondName_<< " "<< ThirdName_<<Surname_<< " ";
    return ss.str();

}
bool Name::IsBeforeBySurname(std::string inputname){
    std::stringstream objectname(Surname_);
    objectname<<FirstName_<<SecondName_<<ThirdName_;
    if (inputname.compare(objectname.str()) > 0)
        return true;
    else
        return false;

}
bool Name::IsBeforeByFirstName(std::string inputname){
    std::stringstream objectname("");
    objectname<<FirstName_<<SecondName_<<ThirdName_<<Surname_;
    if (inputname.compare(objectname.str()) > 0)
        return true;
    else
        return false;
}