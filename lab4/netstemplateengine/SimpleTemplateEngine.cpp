//
// Created by mat on 25.03.17.
//

#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include "SimpleTemplateEngine.h"


namespace nets {
    View::View(std::string intext) : text_(intext) {}

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {

        std::regex formula(R"(\{\{([^\{\}]+?)\}\})");
        std::smatch matchexpr;
        std::string result = text_;
//        std::regex_search(result.begin(), result.end(), matchexpr, formula, std::regex_constants::format_first_only);
        while(true){
            std::regex_search(result, matchexpr, formula, std::regex_constants::format_first_only);
            if (matchexpr.size()<2)
                break;
            auto replacement = model.find(matchexpr[1].str());
            if (replacement==model.end())
                result = std::regex_replace(result, formula, "", std::regex_constants::format_first_only);
            else
                result = std::regex_replace(result, formula, replacement->second, std::regex_constants::format_first_only);
            std::cout<<result<<std::endl;
        }
        return result;
    }

}