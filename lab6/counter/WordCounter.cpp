//
// Created by mat on 06.04.17.
//
#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <iostream>
#include <regex>
#include "WordCounter.h"

namespace datastructures {
    WordCounter::WordCounter() {}

    WordCounter::WordCounter(const std::string &path) {
        file_.open(path, std::fstream::in); //otwarty do odczytu
        if (file_.good())
            std::cout << "błąd otwarcia pliku";
    }

    WordCounter::~WordCounter() {
        if (file_.is_open())
            file_.close();
    }

    int WordCounter::TotalWords() {
        int allwords = 0;
        for (auto &&uniqueword : wordcontainer_) {
            allwords += uniqueword.second.GetCount();
        }
        return allwords;
    }

    int WordCounter::DistinctWords() {
        return wordcontainer_.size();
    }

    std::set<Word> WordCounter::Words() {
        std::list<Word> resultsortedlist;
        for (auto &pairitem : wordcontainer_) {
            resultsortedlist.push_back(pairitem.first);
        }
        resultsortedlist.sort();
        //TODO
//        return resultsortedlist;
    }

    WordCounter::WordCounter(std::initializer_list<Word> in) {
        for (auto &&worditem : in) {
            //find REFERENCE to list element, or empty
            std::pair<Word, Counts> &repetitionindex = this->FindElement(worditem);
            if (repetitionindex.first.Empty()) {
                wordcontainer_.push_back(std::make_pair(worditem, Counts(1)));
            } else {
                //if element exists, increment Counts
                ++repetitionindex.second;
            }
        }
    }

    std::pair<Word, Counts> &WordCounter::FindElement(const Word &checkthisword) {
        for (auto &wordcountpair : wordcontainer_) {
            if (wordcountpair.first == checkthisword)
                return wordcountpair;
        }
        brutalwalkby_ = std::make_pair(Word(), Counts());
        return brutalwalkby_;
    }

    Counts & WordCounter::operator[](std::string lookforword) {
        return FindElement(Word(lookforword)).second;
    }

    std::ostream& operator<<(std::ostream &os, const WordCounter &wcout)  {
        for (auto &&pairitem : wcout.wordcontainer_) {
            os<<"Word: \""<<pairitem.first;
            os<<"\", Count: "<<pairitem.second<<std::endl;
        }
        return os;
    }
}


