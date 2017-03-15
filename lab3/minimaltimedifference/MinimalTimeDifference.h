//
// Created by mat on 15.03.17.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>

namespace minimaltimedifference {

    unsigned int ToMinutes(std::string time_HH_MM);

    unsigned int MinimalTimeDifference(std::vector<std::string> times);

    unsigned int FindDiff(std::vector<int> timesInMinutes);

}

#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
