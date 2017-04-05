//
// Created by mat on 21.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include<string>
#include<regex>
#include <cstdint>

namespace nets {
    class SimpleUrl {
    public:
        SimpleUrl(std::string);

        std::string Login() const;

        std::string Host() const;

        std::string Path() const;

        uint16_t Port() const;

        std::string Scheme() const;

        std::string Query() const;

        std::string Fragment() const;

    private:
        std::string login;
        std::string host;
        std::string path;
        std::string scheme;
        std::string query;
        std::string fragment;
        uint16_t port = 443;
    };
}
#endif //JIMP_EXERCISES_SIMPLEURL_H
