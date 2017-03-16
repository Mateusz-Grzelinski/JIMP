//
// Created by mat on 15.03.17.
//
#include <iostream>
#include <utility>
#include <string>
#include <array>
#include <memory>

#include "MinimalTimeDifference.h"

#define MINUTESINDAY 1440 //mity w ciągu dnia

unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM) {
    std::stringstream ss;
    std::regex pattern {R"((\d{1,2}):(\d{1,2})\s*)"};
    std::smatch match;
    unsigned int hours, minutes;

    if (std::regex_match(time_HH_MM, match, pattern)){
//        std::cout<<std::endl<<match[0]<<" "<<match[1]<<" "<<match[2]<<" size: "<<match.size();
//        ss<<time_HH_MM.substr(0,2)<<' '<<time_HH_MM.substr(3,4); //bez regex
        ss<<match[1]<<" "<<match[2];
        ss>>hours>>minutes;

    }
    else{
        //zle dane, niedopasowane do regex
        return 0;
    }
    return hours*60+minutes;
}

unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times) {
    if(times.size()<2) return 0;
    std::vector<int> timesInMinutes;
    unsigned int minimalDiff=1441;
    for( auto singleTime : times) {
        timesInMinutes.push_back(ToMinutes(singleTime));
        if(minimalDiff > FindDiff(timesInMinutes))
            minimalDiff=FindDiff(timesInMinutes);
    }
    return minimalDiff;
}

unsigned int minimaltimedifference::FindDiff(std::vector<int> timesInMinutes) {
    int justAdded=timesInMinutes.back();
    int tmpMin=1441;
    for(auto i=timesInMinutes.begin(); i!=timesInMinutes.end()-1; ++i){
        unsigned int difference=abs(*i-justAdded);
        unsigned int reverseDifference=abs(MINUTESINDAY-difference);
        int lower;
        if (difference>reverseDifference)
            lower=reverseDifference;
        else
            lower=difference;
        if (tmpMin>lower)
            tmpMin=lower;
//        std::cout<<"difference: "<<difference<<" "<< reverseDifference<<"lower: "<<lower;

    }
    return tmpMin;
}
