#include "XXX.h"
#include <iostream>

XXX::XXX()  {
    name_ = new char[1024] ;
    std::memset(name_, 'a', 1024);
//    name_ = "bezparam";
}

XXX::XXX(int param) : param_(param) {}

XXX::XXX(const std::string name) : name_(new char[std::strlen(name.c_str()) + 1]) {
    std::strcpy(name_, name.data());
}

XXX::~XXX() { delete []name_; }

//konstruktor przenoszący:
XXX::XXX(XXX &&xxx) : name_{nullptr} {
    swap(name_, xxx.name_);
}

//operator przenoszący:
XXX &XXX::operator=(XXX &&xxx) {
    if (this == &xxx) {
        return xxx;
    }
    delete[] name_;
    name_ = nullptr;
    swap(name_, xxx.name_);
}

//konstruktor kopiujący:
XXX::XXX(const XXX &xxx) {
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
}

//operator przypisania:
XXX &XXX::operator=(const XXX &xxx) {
    if (this == &xxx) {
        return *this;
    }
    delete[] name_;
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
}

