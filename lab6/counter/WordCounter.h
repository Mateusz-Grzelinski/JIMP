//
// Created by mat on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H
#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <iostream>
#include <regex>
#include "Word.h"
#include "Counts.h"

namespace wordcounter {
    class WordCounter {
    public:
        WordCounter(const std::string &path);
        ~WordCounter();
        void ReadWholeFile();
//        void IgnoreWate();
    private:
        std::fstream file_;
        std::list<std::pair<Word, Counts>> wordcontainer_;
    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
