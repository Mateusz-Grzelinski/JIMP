//
// Created by mat on 16.03.17.
//

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>
#include <map>
#include "TinyUrl.h"

using namespace tinyurl;

std::unique_ptr<TinyUrlCodec> tinyurl::Init() {   //czy nie lepiej zrobić kostruktor?
    std::unique_ptr<TinyUrlCodec> newStructure = std::make_unique<TinyUrlCodec>();
    newStructure->keyArray.fill('0');
    return newStructure;
}

void tinyurl::Gen(std::array<char, 6> &state, int index) {
    if (state[index] == 'z') {
        state[index] = '0';
        if (index +1 >= state.size()-1)
            tinyurl::Gen(state, index + 1);
    } else if (state[index] == 'Z') {
        state[index] = 'a';
        if (index +1 >= state.size()-1)
            tinyurl::Gen(state, index + 1);
    } else if (state[index] == '9') {
        state[index] = 'A';
        if (index +1 >= state.size()-1)
            tinyurl::Gen(state, index + 1);
    } else
        state[index]++;
}

void tinyurl::NextHash(std::array<char, 6> *state) {     //nie wiem czy mogę zmienić tą funkcję więc piszę drugą
//    tinyurl::Gen(*ref, 0);       //funkcja rekurencyjna, dobry algorytm, ale nie tego chcą testy...
    auto &ref=*state;
    int i=ref.size()-1; //5
    while(i!=-1){
        if (ref[i] == '9') {
            ref[i] = 'A';
            break;
        } else if (ref[i] == 'Z') {
            ref[i] = 'a';
            break;
        } else if (ref[i] == 'z') {
            ref[i] = '0';
            //tylko to przechodzi
        } else {
            ++ref[i];
            break;
        }
        --i;
    }
}



std::string tinyurl::Encode(const std::string &url,
                            std::unique_ptr<TinyUrlCodec> *codec) {
    auto &ref=*codec;
    std::string encoded=ref->keyArray.data();
    ref->urlMap[encoded] = url ;
//    NextHash(&(*codec)->keyArray); //nowy kod
    return encoded;
}

std::string tinyurl::Decode(const std::unique_ptr<TinyUrlCodec> &codec,
                            const std::string &hash) {
    auto it=codec->urlMap.find(hash);
    if (it != codec->urlMap.end())
        return it->second;
    else
        return nullptr;
}

