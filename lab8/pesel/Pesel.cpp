//
// Created by mat on 27.04.17.
//

#include "Pesel.h"
#include <sstream>

namespace academia {

    int Sum(const std::string &str) {
        const char *c = str.c_str();
        int sum = 0, weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};

        for (int i = 0; i < str.size(); ++i) {
            sum += ((int) c[i] - 48) % 10 * weights[i];
        }

        return sum;
    }

    void CharactersValidation(const std::string &str) {
        const char *c = str.c_str();
        for (int i = 0; i < str.size(); ++i) {
            if ((int) c[i] > (int) '9' || (int) c[i] < (int) '0') throw InvalidPeselCharacter(str);
        }
    }

    void Pesel::Validate(const std::string &pesel) const {
        CharactersValidation(pesel);
        if (pesel.size() != 11) throw InvalidPeselLength(pesel, pesel.size());
        if (Sum(pesel) % 10 != 0) throw InvalidPeselChecksum(pesel, Sum(pesel));
    }

}