//
// Created by mat on 01.06.17.
//

#ifndef JIMP_EXERCISES_ARABICROMECONSVERSION_H
#define JIMP_EXERCISES_ARABICROMECONSVERSION_H

#include <utility>
#include <string>
#include <algorithm>
#include <unordered_map>
class ArabicRomeConsversion {
public:
    ArabicRomeConsversion(const size_t &in): arabic_(in) {
        keys_={ {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"M", 1000} };
    }
    ArabicRomeConsversion(const std::string &in): arabic_(0), rome_(in) {
        keys_={ {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"M", 1000} };
    }

    std::string to_rome();
    size_t to_arabic();

private:
    std::unordered_map<std::string, size_t> keys_;
    size_t arabic_;
    std::string rome_;
};

size_t ArabicRomeConsversion::to_arabic() {
    if( arabic_!=0 )
        return arabic_;
    for (size_t mod = arabic_%1000;  ; ) {

    }
}

std::string ArabicRomeConsversion::to_rome() {
    if( !rome_.empty())
        return rome_;

}
#endif //JIMP_EXERCISES_ARABICROMECONSVERSION_H
