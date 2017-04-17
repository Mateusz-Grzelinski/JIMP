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
#include <istream>
#include <initializer_list>
#include "Word.h"
#include "Counts.h"

namespace datastructures {
    class WordCounter {
    public:
        WordCounter();

        WordCounter(std::initializer_list<Word> in);

        int TotalWords();

        int DistinctWords();

        void Insert(Word newword);

        std::set<Word> Words();

        std::pair<Word, Counts> &FindElement(const Word &checkthisword);

        static WordCounter FromInputStream(std::istream &is);

        Counts & operator[](std::string lookforword);

        friend std::ostream& operator<<(std::ostream &os, const WordCounter &wcout) ;
    private:
        std::list<std::pair<Word, Counts>> wordcontainer_;
        //brutalne obejście w metodzie FindElement
        std::pair<Word, Counts> brutalwalkby_;
    };

    std::ostream& operator<<(std::ostream &os, const WordCounter &wcout) ;

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
