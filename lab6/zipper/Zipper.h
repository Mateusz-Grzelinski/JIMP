//
// Created by mat on 04.04.17.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <vector>
#include <string>
#include <tuple>
#include <utility>

namespace datastructures {
    using std::string;
    using std::vector;
    using std::pair;
    using std::tuple;

    class Zipper {
    public:
        static tuple<string, int> zip
                (vector<string> &v1, vector<int> &v2);
//        auto operator++(tuple<string, int> &it);



//        auto operator *(const tuple<string, int>);
//        auto operator++(int num, tuple<string, int> &it);
//        bool operator<(tuple<string, int> &it);

//    private:
//        pair<vector<string>, vector<int>> remember_;
//        int index_;
    };

}
#endif //JIMP_EXERCISES_ZIPPER_H
