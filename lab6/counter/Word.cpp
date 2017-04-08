//
// Created by mat on 06.04.17.
//

#include "Word.h"

namespace datastructures {
    Word::Word(std::string in): word_(in) {}

    bool Word::Empty() {
        return word_.empty();
    }

    const std::string Word::GetWord() const {
        return word_;
    }

    bool operator==(const Word &one, const Word &two) {
        return (one.GetWord() == two.GetWord());
    }
    bool operator<(const Word &one, const Word &two){
        return (one.GetWord()<two.GetWord());
    }
    bool operator>(const Word &one, const Word &two) {
        return (one.GetWord() > two.GetWord());
    }
    std::ostream& operator<<(std::ostream &os, const Word &wout) {
        os<<wout.GetWord();
        return os;
    }

}


