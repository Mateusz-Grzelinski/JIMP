//
// Created by mat on 08.03.17.
//

#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <string>
#include <algorithm> // potrzebne do zamiany wszystkich liter na duże
std::string PolybiusCrypt(std::string message);
std::string PolybiusDecrypt(std::string crypted);

//funckcje pomocnicze:
std::string EncryptStringToIndex(char letter);
char DecryptIndexToString(char index_x, char index_y);



#endif //JIMP_EXERCISES_POLYBIUS_H
