//
// Created by mat on 12.03.17.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;


std::string XorCypherBreaker(const std::vector<char> &cryptogram,int key_length,
                             const std::vector<std::string> &dictionary);
void GenerateKey(string &keyIndexes, int i);

void GenerateNewSetOfCode(const vector<char> &cryptogram, const int key_length, string &keyIndexes,
                          string &newGuess);

int CheckWithDictionary(const vector<string> &dictionary, string newGuess);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
