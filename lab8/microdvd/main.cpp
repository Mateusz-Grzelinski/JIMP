//
// Created by mat on 03.05.17.
//

#include "MovieSubtitles.h"
#include <iostream>
#include <memory>
#include <sstream>
using namespace moviesubs;
using namespace std;

int main(){
    auto subs = make_unique<MicroDvdSubtitles>();
    stringstream in {"{144}{299}{s:12}12 Font used\n{280}{350}{c:$0000FF}Hello!\n{1000}{1050}Multi|Line|Text\n"};
    stringstream out;
    subs->ShiftAllSubtitlesBy(2300, 20, &in, &out);
    std::cout<<out.str();
    return 0;
}