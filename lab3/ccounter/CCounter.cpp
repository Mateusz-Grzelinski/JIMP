//
// Created by mat on 16.03.17.
//

#include "CCounter.h"
#include<iostream>


namespace ccounter {

    //jeśli deklaracja struct Couter będzie tutaj, wysypią się wskaźniki

    std::unique_ptr<Counter> Init(){
        std::unique_ptr<Counter> newObject= std::make_unique<Counter>();
        return newObject;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        std::unique_ptr<Counter> &ref=*counter;
        if (ref->countStoI.find(key)==ref->countStoI.end())
            ref->countStoI[key]=1;
        else
            ref->countStoI[key]+=1;

    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key){
        if (counter->countStoI.find(key)!=counter->countStoI.end())
            return counter->countStoI[key];
        else
            return 0;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter){
        (*counter)->countStoI[key]=value;
    }
}


//
// Created by mat on 16.03.17.
//

#include<iostream>
#include <string>
#include <memory>
#include <map>
#include "CCounter.h"

/*
namespace ccounter {

    struct Counter {
        std::map<std::string, int> countStoI;
    };

    std::unique_ptr<Counter> Init(){
        std::unique_ptr<Counter> newStruct= std::make_unique<Counter>();
        return newStruct;
    }


    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        auto &r=*counter;
        if (r->countStoI.find(key)==r->countStoI.end())
            r->countStoI[key]=0;
        else
            r->countStoI[key]++;
    }
    int Counts(const std::unique_ptr<Counter> &counter, std::string key){
//        auto &r=*counter;
        if (counter->countStoI.find(key)==counter->countStoI.end())
            return 0;
        else
            return counter->countStoI[key];
    }
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter){
        auto &r=*counter;
//        auto foundIterator=r->countStoI.find(key);
//        if (foundIterator!=r->countStoI.end())
        r->countStoI[key]=value;
    }

}*/