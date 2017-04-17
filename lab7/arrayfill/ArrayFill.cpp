//
// Created by mat on 17.04.17.
//

#include <random>
#include <vector>
#include <memory>
#include "ArrayFill.h"

namespace arrays {
    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return start_+step_*index;
    }

    int RandomFill::Value(int index) const {
        return (*distribution_)(*generator_);
    }

    int SquaredFill::Value(int index) const{
        return b_+a_*index*index;
    }

    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (std::size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
}