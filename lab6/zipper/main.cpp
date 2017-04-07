//
// Created by mat on 05.04.17.
//

#include <Zipper.h>
#include <iostream>

using namespace std;
using datastructures::Zipper;
int main(){
    vector<string> strv={"ja", "ty", "on"};
    
    vector<int> intv={1, 2, 3};
    for (const pair<string,int> &p : Zipper::zip(strv, intv) ){
        cout<<p.first<<endl;
        cout<<p.second<<endl<<endl;
    }

}