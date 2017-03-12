//
// Created by mat on 12.03.17.
//

#include "XorCypherBreaker.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
void PrintVector(const vector<int> numbers);

using namespace std;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,int key_length,
                             const std::vector<string> &dictionary){
    string keyInstace;//="aaa";
    string newGuess;
    string keyWhenMaxFound;
    int maxFound=0;
    int foundWords=0;
    for (int i=0; i<key_length; ++i)
        keyInstace.push_back('a');      //zacznij od klucza 'aaa'
    //pętla główna (rozkodowująca)
    while(keyInstace!="zzz"){
        newGuess.clear();
        GenerateNewSetOfCode(cryptogram, key_length, keyInstace, newGuess);
        foundWords = CheckWithDictionary(dictionary, newGuess);
//        cout<<"trafień: "<< foundWords<<" "<<"klucz "<<keyInstace<<endl;


        if (foundWords> maxFound) {
            keyWhenMaxFound = keyInstace;
            maxFound = foundWords;
        }
        GenerateKey(keyInstace, 0);
    }
    return keyWhenMaxFound;
}

int CheckWithDictionary(const vector<string> &dictionary, string newGuess) {
    int i=0;
//    cout<<"dic "<<dictionary.size()<<endl;

    for( auto word : dictionary) {
        if (newGuess.find(word)!= string::npos) i++;
    }
//    cout<<endl<<newGuess<<endl;

    return i;
}

void GenerateNewSetOfCode(const vector<char> &cryptogram, const int key_length, string &keyIndexes,
                          string &newGuess) {
    long i=0;
    for (auto indexCrypted : cryptogram) { //wypróbuj jeden klucz
            newGuess.push_back( (char)(indexCrypted ^ (int)keyIndexes[i % key_length]) );
            i++;
        }
}

void GenerateKey(string &keyIndexes, int i = 0) {
    if (keyIndexes[i]=='z') {
        keyIndexes[i] = 'a';
        if ( i+1<=keyIndexes.size() )
            GenerateKey(keyIndexes, i+1);
    }
    else{
        keyIndexes[i]+=1;
    }

}


void PrintVector(const vector<char> numbers){
    for(auto v : numbers)
        cout<< v << " ";
    cout<<endl;
}