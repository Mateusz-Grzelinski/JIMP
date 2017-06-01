//
// Created by mat on 01.06.17.
//

#ifndef JIMP_EXERCISES_ARABICROMECONSVERSION_H
#define JIMP_EXERCISES_ARABICROMECONSVERSION_H

#include <utility>
#include <string>


class ArabicRomeConsversion {
public:
    ArabicRomeConsversion(const size_t &in): arabic_(in) {}
    ArabicRomeConsversion(const std::string &in): rome_(in) {}

    to_rome();
    to_string();
private:
    size_t arabic_;
    std::string rome_;
};


#endif //JIMP_EXERCISES_ARABICROMECONSVERSION_H
