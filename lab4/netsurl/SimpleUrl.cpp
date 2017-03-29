//
// Created by mat on 21.03.17.
//

#include <cstdint>
#include<string>
#include<regex>
#include "SimpleUrl.h"

namespace nets {
    std::string SimpleUrl::Login() const {
        return login;
    }

    std::string SimpleUrl::Host() const {
        return host;
    }

    std::string SimpleUrl::Path() const {
        return path;
    }

    uint16_t SimpleUrl::Port() const {
        return port;
    }

    std::string SimpleUrl::Scheme() const {
        return scheme;
    }

    std::string SimpleUrl::Query() const {
        return query;
    }

    std::string SimpleUrl::Fragment() const {
        return fragment;
    }

    SimpleUrl::SimpleUrl(std::string url) {
        std::regex pattern
                {R"((([\w\.\-\+]+:)\/{2}(([\w\d\.]+):([\w\d\.]+))?@?(([a-zA-Z0-9\.\-_]+)(?::(\d{1,5}))?))?(\/(?:[a-zA-Z0-9\.\-\/\+\%]+)?)(?:\?([a-zA-Z0-9=%\-_\.\*&;]+))?(?:#([a-zA-Z0-9\-=,&%;\/\\"'\?]+)?)?)"};
        std::smatch match;
        std::regex_search(url, match, pattern);

        login = match[4];
        host = match[7];
        path = match[9];
        port = stoi(match[8]);
        scheme = match[2];
        query = match[10];
        fragment = match[11];
    }
}