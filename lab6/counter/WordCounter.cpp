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

namespace wordcounter {
    WordCounter::WordCounter(const std::string &path) {
        file_.open(path, std::fstream::in); //otwarty do odczytu
        if (file_.good())
            std::cout<<"błąd otwarcia pliku";
    }
    WordCounter::~WordCounter() {
        file_.close();
    }
    void WordCounter::ReadWholeFile() {
        if(file_.is_open()){
//            file_.seekg(0, file_.end );
//            long filelengthinchar = is.tellg();
//            file_.seekg(0, file_.beg);
//
//            std::stringstream readfile;
//            file_(readfile, filelengthinchar);

//            std::regex_match matchedwords;
//            std::regex wordformula("(\\w+?)");
//            std::regex_search(file_, matchedwords, wordformula); //czy na file_ będzie dziąłać?

//            for (auto &&singlematch :matchedwords) {
//            }
        }
    }
}