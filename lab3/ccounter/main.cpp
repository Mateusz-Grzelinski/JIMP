//
// Created by mat on 16.03.17.
//

#include <iostream>
#include "CCounter.h"

using namespace std;

int main(){
    std::unique_ptr<ccounter::Counter> nowyObiekt = ccounter::Init();
//    cout<<nowyObiekt;
    return 0;
}