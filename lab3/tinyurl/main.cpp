//
// Created by mat on 16.03.17.
//

#include <iostream>
#include "TinyUrl.h"

using namespace std;
int main(){

    std::array<char, 6> state;
    state.fill('0');
    tinyurl::NextHash(&state);
    for( auto i: state)
        cout<<i<<' ';
    return 0;
}
