//
// Created by mat on 04.04.17.
//
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include "Zipper.h"

using std::string;
using std::vector;
using std::pair;
using std::tuple;

namespace datastructures {

    static tuple<string, int> Zipper::zip
            (vector<string> &v1, vector<int> &v2) {

        tuple<string, int> out_tuple ={"",0};
        if(!v1.empty() && !v2.empty()) {
            out_tuple = {v1[0], v2[0]};
            return out_tuple;
        }else
            return out_tuple;
    }


//    auto Zipper::operator++(tuple<string, int> &it) {
//
//    }


}