//
// Created by mat on 16.03.17.
//

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>
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

/* Algorytm: zamień string na ciąf int'ów zapsanych w dalej w liście stringów(albo intów)
 * np: "aa"->{"97", "97"}
 * weź pary liczb,
 * wykonaj Xor z kluczem
 * zamień na system o dużej podstawie
 * po drodze zapisz gdzieś ten klucz aby potem odkodować*/

std::string tinyurl::Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
    //zakodój Xor-em
    std::string encoded;
    long i=0;
    for (auto index : url) { //podaje litery po kolei
        encoded+=std::to_string( (int)index ^ (int)(*codec)->keyArray[i % (*codec)->keyArray.size()] ); //zakodowane inty do stringa
        i++;
    }

    TenToN(encoded);

    NextHash(&(*codec)->keyArray); //nowy kod
    return encoded;
}


/* Dekodowanie:
 * zamień na system dziesiętny
 * weź po 2 liczby nie wiem co dalej  */

std::string tinyurl::Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
    //zamiana z n-tego na 10
    std::vector<int> digitsFromHash = NToTen(hash);
    long i=0;
    std::string decoded;
    //Xor dekodowanie
    for (auto index : digitsFromHash) { //podaje po kolei liczby
        decoded.push_back( (char)(index ^ (int)codec->keyArray[i % codec->keyArray.size()]) );  //odkoduje je
        i++;
    }
}

std::vector<int> NToTen(const std::string &basic_string) { //zamienia system n zmiennych na dziesiątkowy
    std::vector<int> newTranslationToDigits;

    return newTranslationToDigits;
}
