//
// Created by mat on 25.03.17.
//

#include <string>

#include <map>
#include <vector>
#include <experimental/optional>
#include "SimpleJson.h"


namespace nets {

    JsonValue::JsonValue(long input) : intvalue_(&input) {
        doublevalue_ = nullptr;
    }

    JsonValue::JsonValue(double input) : doublevalue_(&input) {
        intvalue_ = nullptr;
    }

    JsonValue::JsonValue(bool input) : boolvalue_(&input) {
        intvalue_ = nullptr;
        doublevalue_ = nullptr;
    }

    JsonValue::JsonValue(std::string input) : stringvalue_(input) {
        intvalue_ = nullptr;
        doublevalue_ = nullptr;
    }

    JsonValue::JsonValue(std::vector<nets::JsonValue> input) : table_(input) {
        intvalue_ = nullptr;
        doublevalue_ = nullptr;
    }

    JsonValue::JsonValue(std::map<std::string, nets::JsonValue> input) : mapjson_(input) {
        intvalue_ = nullptr;
        doublevalue_ = nullptr;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        if (mapjson_.count(name)) {
            JsonValue tmp = this->mapjson_.find(name)->second;
            return std::experimental::make_optional(tmp);
        }
        return {};
    }

    std::string JsonValue::ToString() const {
        if (doublevalue_)
            return std::to_string(*doublevalue_);
        if (intvalue_)
            return std::to_string(*intvalue_);
        if (!stringvalue_.empty())
            return stringvalue_;
        if (!table_.empty()) {
            std::string result;
            for (auto &i : table_) {
                result.append(i.ToString());
            }
            return result;
        }
        return "";
    }

}