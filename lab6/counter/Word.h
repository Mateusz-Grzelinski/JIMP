//
// Created by mat on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>
#include <utility>

namespace datastructures {
    class Word {
    public:
        Word() = default;

        Word(std::string in);

        bool Empty();

        const std::string GetWord() const;

    private:
        std::string word_;

    };

    bool operator==(const Word &one, const Word &two);
//    bool operator<(const Word &one, const Word &two);
//    bool operator>(const Word &one, const Word &two);
}


#endif //JIMP_EXERCISES_WORD_H
