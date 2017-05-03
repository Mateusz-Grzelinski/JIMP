//
// Created by mat on 27.04.17.
//


#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include <string>
#include <stdexcept>
#include <exception>


namespace academia {
    class AcademiaDataValidationError : public std::runtime_error{
    protected:
        AcademiaDataValidationError(const std::string &s) : std::runtime_error(s){};
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &pesel, int sum) : AcademiaDataValidationError("Invalid PESEL("+pesel+") checksum: "+std::to_string(sum)){}
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const std::string &pesel) : AcademiaDataValidationError("Invalid PESEL("+pesel+") character set"){}
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(const std::string &pesel, unsigned long len) : AcademiaDataValidationError("Invalid PESEL("+pesel+") length: "+std::to_string(len)){}
    };

    class Pesel {
    public:
        Pesel(const std::string &p){
            Validate(p);
            pesel_=p;
        };
    private:
        std::string pesel_;
        void Validate(const std::string &pesel) const;
    };

}
#endif //JIMP_EXERCISES_PESEL_H
