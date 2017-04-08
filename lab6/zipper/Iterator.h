//
// Created by Student on 06/04/17.
//

#ifndef JIMP_EXERCISES_ITERATOR_H
#define JIMP_EXERCISES_ITERATOR_H

#include<string>
#include<utility>
#include <vector>
using std::string;
using std::vector;


class Iterator {
public:
    Iterator(vector<string> &v1, vector<int> &v2);
    bool operator!=(const Iterator &it);
    void operator++();
    std::pair<string,int> operator*();
private:
    vector<string> &v1_;
    vector<int> &v2_;
    int index_;
};


#endif //JIMP_EXERCISES_ITERATOR_H
