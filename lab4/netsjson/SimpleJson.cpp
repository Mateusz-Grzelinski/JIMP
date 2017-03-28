//
// Created by mat on 25.03.17.
//
#include <iostream>
#include <cstring>
#include <ostream>
#include <map>
#include <vector>
#include <experimental/optional>
#include "SimpleJson.h"


namespace nets {

    JsonValue::JsonValue(int input) : intvalue_(input) {
        enumvalue = INT;
    }

    JsonValue::JsonValue(double input) : doublevalue_(input) {
        enumvalue = DOUBLE;
    }

    JsonValue::JsonValue(bool input) : boolvalue_(input) {
        enumvalue = BOOL;
    }

    JsonValue::JsonValue(std::string input) {
//        std::string escape("\\\'\"\?"), result("\"");

//        for(auto &i: input){
//            if(escape.find(i)!=escape.npos)
//                result.append("\\");
//            result.push_back(i);
//        }
//        result.push_back('\"');
//        stringvalue_ = result;
        std::string tmp("\"");
        tmp.append(input);
        tmp.push_back('\"');
        stringvalue_ = tmp;
        enumvalue = STRING;
    }

    JsonValue::JsonValue(std::vector<nets::JsonValue> input) : table_(input) {
        enumvalue = VECTOR;
    }

    JsonValue::JsonValue(std::map<std::string, nets::JsonValue> input) : mapjson_(input) {
        enumvalue = MAP;
        std::string tmp;
        for (auto i : input) {
            tmp.append("\"");
            tmp.append(i.first);
            tmp.append("\": ");
            tmp.append(i.second.stringvalue_);

            i.second.stringvalue_.swap(tmp); //w mapie kazdy json ma postać "klucz" : "wartość"
        }
    }


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        if (mapjson_.count(name)) {
            JsonValue tmpjson = this->mapjson_.find(name)->second;
            return std::experimental::make_optional(tmpjson);
        }
        return {};
    }

    std::string JsonValue::ToString() const {
        switch (enumvalue) {
            case INT : {
                std::string tmp(stringvalue_);
                return tmp.append(std::to_string(intvalue_));
            }
            case DOUBLE : {
                std::string result(std::to_string(doublevalue_));
                while (result[result.size() - 1] == '0')
                    result.pop_back();
                std::string tmp(stringvalue_);
                return tmp.append(result);
            }

            case BOOL:
                if (boolvalue_)
                    return "true";
                else
                    return "false";

            case STRING :
                return stringvalue_;

            case VECTOR : {
                std::string result("[");
                int indx = 0;
                for (auto &i : table_) {
                    result.append(i.ToString());
                    indx++;
                    if (indx < table_.size())
                        result.append(", ");
                }
                result.append("]");
                return result;
            }
            default:
                return "";
        }
    }


}