//
// Created by mat on 04.03.17.
//
#include <reverse.h>

std::string reverse(std::string str){
    if (str.length()==0 || str.length()==1) return str;
    else {
        std::string reversed_characters; //odwrócony str
        std::string last_char(1, str[str.length()-1]); //string przechowujący ostatni znak str
        reversed_characters = last_char + reverse( str.substr(0,str.length()-1) );
        return std::string(reversed_characters);

    }
}