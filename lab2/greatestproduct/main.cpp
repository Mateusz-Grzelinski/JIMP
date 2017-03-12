//
// Created by mat on 11.03.17.
//

#include <iostream>
#include "GreatestProduct.h"

using namespace std;

int main(){
    vector<int>  exsample{-11, -90, -4, -5, -9, -1, -3, 1, };
    PrintVector(exsample);
    cout<<endl<<"iloczyn: "<<GreatestProduct(exsample, 3);
    return 0;
}