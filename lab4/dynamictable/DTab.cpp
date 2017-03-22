//
// Created by mat on 22.03.17.
//

#include <iostream>
#include "DTab.h"
#include<cstring>
//#include<string>
DTab::DTab() {
    length=0;
    resize(10);
    length=10;
    last=0;
}
DTab::DTab(int initLength) {
    resize(initLength);
    length=initLength;
    last=0;
}
DTab::~DTab(){
    delete tab;
}

void DTab::resize(int newSize){ //TODO przepisanie tablicy
    double *tmp=new double [newSize];
    if (tmp!= nullptr)
        if (newSize>length)
            std::memcpy( tmp, tab, length);
        else
            std::memcpy( tmp, tab, newSize);
    if (tab!= nullptr)
        delete tab;
    tab=tmp;
}

void DTab::add(double element){
    if (last==length-1)
        resize(length + 5);
    tab[last]=element;
    last++;

}

double DTab::get(int index){
    if (index>last)
        resize(index+1);
    return tab[index];
}

void DTab::set(double element, int index){
    if (index>last)
        resize(index+1);
    tab[index]=element;
    if (last<index)
        last=index;
}

void DTab::print(){
    for(int i=0; i<length; i++)
        std::cout<<tab[i]<<" ";
    std::cout<<std::endl;
}