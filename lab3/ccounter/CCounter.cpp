//
// Created by mat on 16.03.17.
//
#include <string>
#include <memory>
#include <map>
#include<iostream>
#include "CCounter.h"



namespace ccounter {

    //jeśli deklaracja struct Couter będzie tutaj, wysypią się wskaźniki

    std::unique_ptr<Counter> Init(){ //tworzy nowy obiekt
        std::unique_ptr<Counter> newObject= std::make_unique<Counter>();
        return newObject;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) { //sprawdza czy obiekt istnieje, wtedy tworzy go lub inicjuje
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

