//
// Created by mat on 18.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H
#include <string>
namespace factoryMethod {
    template<class T>
    T Create() {
        return T();
    };

    class MyType{
    public:
        MyType()= default;

        std::string SayHello();
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
