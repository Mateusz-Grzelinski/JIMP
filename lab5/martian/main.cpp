//
// Created by mat on 30.03.17.
//

#include <iostream>
#include <list>
#include "Martian.h"



int main(){
    std::list<Martian> alienlist;
    while(true){
        alienlist.push_back(Martian());
        if(Martian::shouldAttack())
            while( !alienlist.empty()) {
                alienlist.pop_back();
            }
    }
    return 0;
}

