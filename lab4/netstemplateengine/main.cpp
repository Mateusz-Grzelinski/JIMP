//
// Created by mat on 26.03.17.
//

#include <iostream>
#include "SimpleTemplateEngine.h"

int main(){
    nets::View object("Test {{test}} {{injected}}");
    std::unordered_map<std::string, std::string> stringmap={
            {"test", "{{injected}}"}, {"injected", "{{test}}"}
    };
    std::cout<<object.Render(stringmap)<<std::endl;
}
