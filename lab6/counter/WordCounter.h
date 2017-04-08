//
// Created by mat on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <set>
//#include <iostream>
#include <initializer_list>
#include "Word.h"
#include "Counts.h"

namespace datastructures {
    class WordCounter {
    public:
        WordCounter();

        WordCounter(const std::string &path);

        WordCounter(std::initializer_list<Word> in);

        ~WordCounter();

        int TotalWords();

        int DistinctWords();

        std::set<Word> Words();

        std::pair<Word, Counts> &FindElement(const Word &checkthisword);

        Counts & operator[](std::string lookforword);

        friend std::ostream& operator<<(std::ostream &os, const WordCounter &wcout) ;
    private:
        std::fstream file_;
        std::list<std::pair<Word, Counts>> wordcontainer_;
        //brutalne obejście w metodzie FindElement
        std::pair<Word, Counts> brutalwalkby_;
    };
    std::ostream& operator<<(std::ostream &os, const WordCounter &wcout) ;

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
