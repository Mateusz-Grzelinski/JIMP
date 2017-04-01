//
// Created by mat on 31.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <memory>
#include <iostream>

namespace pool {
    class TextPool {
    public:
//  Rule of Five (z usuniętą możliwością kopiowania):

        TextPool(TextPool &&in);  //kostr. przenoszący

        TextPool(const TextPool &in); //konstr. kopiujący- tego nie chcę

        TextPool &operator=(TextPool &&in);    //przenosi

        TextPool &operator=(const TextPool &in); //kopiujeje

        ~TextPool();  //nie potrzebny

//        Five end--------------------

        TextPool() ;

        TextPool(std::initializer_list<std::string> in);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;




    private:
        std::unique_ptr<std::set<std::string>>  wordset_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
