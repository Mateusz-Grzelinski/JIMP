//
// Created by mat on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>


namespace nets {

    class JsonValue {
    public:
        JsonValue(long);
        JsonValue(double);
        JsonValue(bool);
        JsonValue(std::string input);
        JsonValue(std::vector<nets::JsonValue> input);
        JsonValue(std::map<std::string, nets::JsonValue> input);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        long *intvalue_;
        double *doublevalue_;
        bool *boolvalue_;
        std::string stringvalue_ = nullptr;
        std::vector<nets::JsonValue> table_;
        std::map<std::string, nets::JsonValue> mapjson_ ;
    };

}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
