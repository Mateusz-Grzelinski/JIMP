//
// Created by mat on 21.03.17.
//

#include <cstdint>
#include<string>
#include<regex>
#include "SimpleUrl.h"


std::string SimpleUrl::Login() const{
    std::regex formula(R" ");
    std::smatch matched;
    std::regex_match(url_, matched, formula);

}

std::string SimpleUrl::Host() const;

std::string SimpleUrl::Path() const;

uint16_t SimpleUrl::Port() const;

std::string SimpleUrl::Scheme() const;

std::string SimpleUrl::Query() const;

std::string SimpleUrl::Fragment() const;