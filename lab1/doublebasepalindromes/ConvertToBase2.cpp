//
// Created by mat on 06.03.17.
//

#include "ConvertToBase2.h"
std::string reverse(std::string str){
    if (str.length()==0 || str.length()==1) return str;
    else {
        std::string reversed_characters; //odwrócony str
        std::string last_char(1, str[str.length()-1]); //string przechowujący ostatni znak str
        reversed_characters = last_char + reverse( str.substr(0,str.length()-1) );
        return std::string(reversed_characters);

    }
}
//z systemu dziesiątkowego na dwójkowy mmetodą iteracyjną
std::string ConvertToBase2(long int value){
    std::string BaseTwoString= "";
    while(value!=0){
        BaseTwoString.append( std::to_string(value%2) );
        value=value/2;
    }
    return reverse(BaseTwoString);
}

