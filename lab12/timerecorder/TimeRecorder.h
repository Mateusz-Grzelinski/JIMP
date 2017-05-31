//
// Created by mat on 25.05.17.
//

/* przyjmuje jako parametr funkcje i mierzy jej czas */

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <utility>
#include <chrono>
#include <iostream>

namespace profiling {
    template<typename T>
    auto TimeRecorder(T t) {
        typedef std::chrono::high_resolution_clock cl;
        static cl::time_point begin = cl::now();
        auto wynik = (t)();
        std::chrono::duration<double, std::milli> elapsed = cl::now() - begin;
        return std::pair<decltype(wynik), double>(wynik, elapsed.count());
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
