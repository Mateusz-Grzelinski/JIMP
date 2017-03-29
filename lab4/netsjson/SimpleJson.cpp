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

    JsonValue::JsonValue(std::vector<nets::JsonValue> input) : table_(input) {
        enumvalue = VECTOR;
    }

    JsonValue::JsonValue(std::string input) {
        enumvalue = STRING;
        std::string tmp("\"");
//        tmp.append(input);
        for(int j=0; j<input.size(); j++){
            if (input[j]=='\\' || input[j]=='\"') {
                tmp.append("\\");
            }
            tmp.push_back(input[j]);
        }
        tmp.append("\"");
        stringvalue_ = tmp;
    }

    JsonValue::JsonValue(std::map<std::string, nets::JsonValue> input) : mapjson_(input) {
        enumvalue = MAP;
        std::string tmp;
        for (auto &i : input) {
            tmp.append("\"");
//            tmp.append(i.first);
            for(int j=0; j<i.first.size(); j++){
                if (i.first[j]=='\\' ) {
                    tmp.append("\\");
                }
                tmp.push_back(i.first[j]);
            }

            tmp.append("\": ");
            tmp.append(i.second.stringvalue_);

            i.second.stringvalue_.swap(tmp); //w mapie kazdy json ma postać "klucz" : "wartość"
        }
    }


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
//        std::string tmpwithescaped;
//        for(int j=0; j<name.size(); j++){
//            if (name[j]=='\\' ) {
//                tmpwithescaped.append("\\");
//            }
//            tmpwithescaped.push_back(name[j]);
//        }

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
            case MAP : {
                std::string result("{");
                int counter=0;
                for( auto &i : mapjson_){
                    std::string tmp;
                    result.append("\"");
                    for(int j=0; j<i.first.size(); j++){
                        if (i.first[j]=='\\' || i.first[j]=='\"') {
                            tmp.append("\\");
                        }
                        tmp.push_back(i.first[j]);
                    }
                    result.append(tmp);
                    result.append("\": ");
                    result.append(i.second.ToString());
//                    if(j!=i.first.size()-1)
                    counter++;
                    if(counter<mapjson_.size()) {
                        result.append(", ");
                    }
                }
                result.push_back('}');

                return result;
            }
        } //end of switch
    } //end of function ToString


} //end of namespace