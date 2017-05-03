//
// Created by mat on 27.04.17.
//


#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include <string>
#include <stdexcept>


namespace academia {

    class Pesel {
    public:
        Pesel(std::string pesel);

    private:
        std::string pesel_;
    };


    bool validatePESEL(const char *);
    bool ValidateLetter(const char *checkpesel, int currentsize);


    class AcademiaDataValidationError: public std::runtime_error{
        AcademiaDataValidationError(std: ::string info): runtime_error(info){}
    };

    class InvalidPeselChecksum: public AcademiaDataValidationError{
        InvalidPeselChecksum():AcademiaDataValidationError("sums") {};
    };
    class InvalidPeselLength: public std::runtime_error{

    };
    class InvalidPeselCharacter: public std::runtime_error{

    };
    class AcademiaDataValidationError: public std::runtime_error{

    };

}
#endif //JIMP_EXERCISES_PESEL_H
