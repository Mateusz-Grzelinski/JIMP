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
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;
    };

}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
