//
// Created by mat on 12.03.17.
//

#include "XorCypherBreaker.h"
//#include <string>
//#include <vector>


using namespace std;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,int key_length,
                             const std::vector<string> &dictionary){
    string keyInstace;
    string stopInstance;
    string newGuess;
    string keyWhenMaxWordFound;
    int maxFoundWords=0;
    int foundWords=0;
    for (int i=0; i<key_length; ++i) {
        keyInstace.push_back('a');     //zacznij od klucza 'aaa'
        stopInstance.push_back('z');    //zakończ przy kluczu 'zzz'
    }
    //pętla główna (rozkodowująca)
    while(keyInstace!=stopInstance) {
        newGuess.clear();
        GenerateNewSetOfCode(cryptogram, key_length, keyInstace, newGuess);
        foundWords = CheckWithDictionary(dictionary, newGuess);

        if (foundWords> maxFoundWords) { //zapisz, przy którym kluczy jest najwięcej trafień
            keyWhenMaxWordFound = keyInstace;
            maxFoundWords = foundWords;
        }
        GenerateKey(keyInstace, 0); //wygeneruj kolejny klucz
    }

    return keyWhenMaxWordFound;
}

int CheckWithDictionary(const vector<string> &dictionary, string newGuess) { //zwraca ile słów pokrywa się ze słownikiem
    int i=0;
    for( auto word : dictionary) {
        if (newGuess.find(word)!= string::npos) i++;
    }
    return i;
}

void GenerateNewSetOfCode(const vector<char> &cryptogram, const int key_length, string &keyIndexes,
                          string &newGuess) { //generuje nowe tłumaczenie za pomocą podanego klucza
    long i=0;
    for (auto indexCrypted : cryptogram) { //wypróbuj jeden klucz
            newGuess.push_back( (char)(indexCrypted ^ (int)keyIndexes[i % key_length]) );
            i++;
        }
}

void GenerateKey(string &keyIndexes, int i = 0) { //generuje nowy klucz, litery a-z
    if (keyIndexes[i]=='z') {
        keyIndexes[i] = 'a';
        if ( i+1<=keyIndexes.size() )
            GenerateKey(keyIndexes, i+1);
    }
    else{
        keyIndexes[i]+=1;
    }

}


