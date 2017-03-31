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

    //Rule of five w niepełnym wymiarze:
    TextPool::TextPool(TextPool &&in) {
        std::swap(in.wordset_, wordset_);
    }

    TextPool& TextPool::operator=(TextPool &&in) {
        if (this!=&in) {
            std::swap(in.wordset_, wordset_);
            return *this;
        }
        else
            return *this;
    }

    TextPool::TextPool(std::initializer_list<std::string> in) {
        for (auto &&i : in) {
            wordset_.insert(i);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        auto found = wordset_.insert(str);
        std::experimental::string_view v(*found.first);
        return v;
    }

    size_t TextPool::StoredStringCount() const {
        size_t tmp = wordset_.size();
        return tmp;
    }
}