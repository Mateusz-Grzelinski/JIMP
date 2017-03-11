//
// Created by mat on 11.03.17.
//

#include <iostream>
#include "GreatestProduct.h"

using namespace std;

int main(){
    vector<int>  exsample{19, 8, 3, 5, 8, 1, 3, 5, 10};
    PrintVector(exsample);
    cout<<endl<<"iloczyn: "<<GreatestProduct(exsample, 2);
    return 0;
}