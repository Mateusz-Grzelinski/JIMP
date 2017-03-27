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
        std::regex_search(result, matchexpr, formula, std::regex_constants::format_first_only);
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


//        for(std::sregex_iterator i = std::sregex_iterator(result.begin(), result.end(), formula);
//            i != std::sregex_iterator();
//            ++i )
//        {
//            std::smatch m = *i;
//            std::cout << m.str() << " at position " << m.position() << '\n';
//            unsigned long length = m.str().size();
//            std::cout<<length<<"substr: "<<m.str().substr(2, length - 4)<<std::endl;
//            auto replacement = model.find( m.str().substr(2, length - 4) );
//
//            result.replace(m.position(), length, replacement->second);
//            std::cout << result;
//        }
//        std::smatch m;
//        long offset=0;
//        while(offset<result.size()-1){
//            const std::string baserange = result.substr(offset);
//            auto i=std::regex_search(baserange, m, formula, std::regex_constants::format_first_only);
//            std::cout << m.str() << " at position " << m.position() << '\n';
//            unsigned long length = m.str().size();
//            std::cout<<"substr: "<<m.str().substr(2, length - 4)<<std::endl;
//            auto replacement = model.find( m.str().substr(2, length - 4) );
//
//            if (replacement==model.end())
//                result.replace(m.position(), length, "");
//            else
//                result.replace(m.position(), length, replacement->second);
//            offset+=m.position()+length;
//            std::cout << result<<std::endl<<std::endl;
//        }

    }

}