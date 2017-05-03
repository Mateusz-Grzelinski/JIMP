//
// Created by mat on 27.04.17.
//

#include "Pesel.h"

namespace academia {
    Pesel::Pesel(std::string pesel) {
        validatePESEL(pesel.c_str());
        pesel_ = pesel;
    }


    bool ValidateLetter(const char *checkpesel, int currentsize) {
        return checkpesel[currentsize] == 'a';
    }

    bool validatePESEL(const char *checkpesel) {
        int currentsize;
        for (currentsize = 0; checkpesel[currentsize]!='\0'; ++currentsize) {
            if(ValidateLetter(checkpesel, currentsize))
                throw InvalidPeselCharacter();

        }
        if(currentsize==9)
            throw InvalidPeselLength();



    }


}