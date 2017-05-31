//
// Created by mat on 01.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <utility>


template <class TId, class TCounter>
class SequentialIdGenerator {
public:
    SequentialIdGenerator():counter_(0), first_(true) { }
    SequentialIdGenerator(const TCounter & in): counter_(in), first_(true) { }
    TId NextValue();
private:
    bool first_;
    TCounter counter_;
};
template <class TId, class TCounter>
TId SequentialIdGenerator<TId, TCounter>::NextValue() {
    // thre is no operator++(int), so use bool to determine first use of function
    if(!first_){
        ++counter_;
    }
    first_=false;

    return TId(counter_);
}

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
