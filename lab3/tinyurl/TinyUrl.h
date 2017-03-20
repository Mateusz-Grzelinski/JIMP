//
// Created by mat on 16.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>
#include <map>
#include<iostream>

namespace tinyurl {

    struct TinyUrlCodec {
        std::array<char, 6> keyArray;
        std::map<std::string, std::string> urlMap;
    };

    void NextHash(std::array<char, 6> *ref);

    void Gen(std::array<char, 6> &state, int index);

    std::unique_ptr<TinyUrlCodec> Init();

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

}

#endif //JIMP_EXERCISES_TINYURL_H
