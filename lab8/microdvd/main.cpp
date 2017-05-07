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
    stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
    stringstream out;
    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
    std::cout<<out.str();
//    std::cout<<"{7}{257}TEXT\\n{267}{307}NEWLINE\n";
    return 0;
}
//regex dla SubRiba:
//\s*(.+):(.+):(.+),(.+)\s*-->\s*(.+):(.+):(.+),(.+)([.\s]+)