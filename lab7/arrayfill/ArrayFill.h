//
// Created by mat on 17.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <random>
#include <vector>
#include <memory>


using std::default_random_engine;
using std::uniform_int_distribution;
using std::unique_ptr;

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}

        int Value(int index) const override;

    private:
        int value_;
    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a = 1,int b=0) : a_{a}, b_{b} {}
        int Value(int index) const override ;
    private:
        int a_, b_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int start=0, int step=1) : start_{start},step_{step} {}
        int Value(int index) const override ;
    private:
        int start_,step_;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(unique_ptr<default_random_engine> eng,
                   unique_ptr<uniform_int_distribution<int>> dstr):
                generator_(move(eng)), distribution_(move(dstr)) {};

        virtual int Value(int index) const override;
    private:
        unique_ptr<default_random_engine> generator_;
        unique_ptr<uniform_int_distribution<int>> distribution_;
    };



    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v);

}
#endif //JIMP_EXERCISES_ARRAYFILL_H
