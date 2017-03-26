//
// Created by mat on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>

namespace nets {

    class View {
    public:
        View(std:: string);
        std::string Render(const std::unordered_map<std::string,
                std::string> &model) const;
    private:
        std:: string text_;
    };

}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
