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
        return Iterator(v1,v2);
    }

    Iterator Zipper::begin() {
        
    }


}