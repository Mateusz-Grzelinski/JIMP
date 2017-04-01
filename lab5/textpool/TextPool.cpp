//
// Created by mat on 31.03.17.
//
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <algorithm>
#include <iostream>
#include "TextPool.h"

namespace pool {

    TextPool::TextPool() {
        wordset_ = std::make_unique<std::set<std::string>>();
    }

    //Rule of five :
    TextPool::TextPool(TextPool &&in) {
        std::swap(in.wordset_, wordset_);
    }

    TextPool::TextPool(const TextPool &in) { //czy to jest dobrze?
        wordset_ = std::move(in.wordset_);
    }

    TextPool &TextPool::operator=(TextPool &&in) = default; //przenosi

    TextPool &TextPool::operator=(const TextPool &in) {//kopiujeje, ale kompilator nie pozwala
        //jak to (nie) implementować?
        return nullptr; //hmm, tu nie może być nula...
    }

    TextPool::~TextPool() = default;  //nie potrzebny

//    rozważnia dla impementacji: private:
//                                      std::set<std::string>  wordset_;
//
//    TextPool &TextPool::operator=(TextPool &&in) {
//        if (this != &in) {
//            wordset_=std::move(in.wordset_);
//            return *this;
//        } else
//            return *this;
//    }


    //Five end------------------------

    TextPool::TextPool(std::initializer_list<std::string> in) {
        if (wordset_ == nullptr)
            wordset_ = std::make_unique<std::set<std::string>>();
        for (auto &&i : in) {
            wordset_->insert(i);
        }
    }


    std::experimental::string_view TextPool::Intern(const std::string &str) {
        auto found = wordset_->insert(str);
        std::experimental::string_view v(*found.first);
        return v;
    }

    size_t TextPool::StoredStringCount() const {
        size_t tmp = wordset_->size();
        return tmp;
    }
}