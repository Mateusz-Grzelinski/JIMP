//
// Created by mat on 16.03.17.
//

#include "CCounter.h"
#include<iostream>


namespace ccounter {

    struct Counter {
        std::map<std::string, int> countStoI;
    };

    std::unique_ptr<Counter> Init(){
        std::unique_ptr<Counter> newStruct(new Counter);
        return newStruct;
    }


    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
//        counter->
    }
}