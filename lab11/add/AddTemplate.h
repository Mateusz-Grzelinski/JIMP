//
// Created by mat on 18.05.17.
//

#ifndef JIMP_EXERCISES_ADDTEMPATE_H
#define JIMP_EXERCISES_ADDTEMPATE_H

#include <memory>
#include <vector>

template<class T1>
T1 Add( const T1 &left, const T1 &right) {
    return left + right;
}

template <class T>
auto Value(T in)-> decltype(*in){
    return *in;
}

template <class T>
T Mean(std::vector<T> in1){
    T suma=0;
    for (int i = 0; i < in1.size(); ++i) {
        suma+=in1[i];
    }
    return suma/in1.size();
}


class Loogger{
    Debug();
    Info();

};

#endif //JIMP_EXERCISES_ADDTEMPATE_H
