//
// Created by mat on 08.03.17.
//

#include "Polybius.h"
#include <iostream>
#define toDigit(c) (c-'0'-1)

using namespace std;

string EncryptStringToIndex(char letter){ // zamienia pojedyńczą literę na kod, np: 'N'->'33'
    char key[5][5]={
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'K'},
            {'L', 'M', 'N', 'O', 'P'},
            {'Q', 'R', 'S', 'T', 'U'},
            {'V', 'W', 'X', 'Y', 'Z'}    };
    if (letter=='J') return to_string(24); // litera j jest na tym samym miejscu co i
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if (key[i][j]==letter)
                return to_string( (j+1)+10*(i+1) );// np. 'N' to key[3][3], czyli zwracam 3+30=33

}

string PolybiusCrypt(std::string message){
    string resultEncrypted;
    //konwertuj wszystko na duże litery
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    for(int i=0; i<message.size(); i++) {
        if (message[i]!=' ')
            resultEncrypted.append(EncryptStringToIndex(message[i]) );
    }
    return resultEncrypted;
}

char DecryptIndexToString(char index_x, char index_y) {
    char key[5][5]={
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'K'},
            {'L', 'M', 'N', 'O', 'P'},
            {'Q', 'R', 'S', 'T', 'U'},
            {'V', 'W', 'X', 'Y', 'Z'}    }; //litery j nie mozna odkodowac, pozostaje ona i
//    cout<<key[toDigit(index_x)][toDigit(index_y)]<<endl;
    return key[toDigit(index_x)][toDigit(index_y)]; //potrzebne makro do kowersji, bo (int)'2'=33, 32-'0'=3
}

string PolybiusDecrypt(std::string crypted){
    string resultDecrypted;
    for (int i=0; i<crypted.size(); i+=2) //pobierz 2 cyfry i rokoduj, jaka to litera
        resultDecrypted+= DecryptIndexToString(crypted[i], crypted[i + 1]) ;
    //resultDecrypted.append( DecryptIndexToString(crypted[i], crypted[i + 1]) );// dlaczego append nie działa?
    return resultDecrypted;
}

