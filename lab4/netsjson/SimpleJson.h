//
// Created by mat on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <ostream>

namespace nets {
    enum whichenum {
        INT = 0, DOUBLE, BOOL, STRING, VECTOR, MAP
    };

    class JsonValue {
    public:
        JsonValue(int);

        JsonValue(double);

        JsonValue(bool);

        JsonValue(std::string input);

        JsonValue(std::vector<nets::JsonValue> input);
//"\"account_balance\": -107
// "{"\w+": ["\w\.-]+, "\w+": ["\w\.-]+, "\w+": ["\w\.-]+\})"}
        JsonValue(std::map<std::string, nets::JsonValue> input);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        whichenum enumvalue;
        long intvalue_;
        double doublevalue_;
        bool boolvalue_;
        std::string stringvalue_;
        std::vector<nets::JsonValue> table_;
        std::map<std::string, nets::JsonValue> mapjson_;
    };


}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
