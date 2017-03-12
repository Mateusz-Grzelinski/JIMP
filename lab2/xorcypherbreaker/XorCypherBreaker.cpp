//
// Created by mat on 12.03.17.
//

#include "XorCypherBreaker.h"
//#include <string>
//#include <vector>
//#include <algorithm>

using namespace std;


std::string XorCypherBreaker(const std::vector<char> &cryptogram,int key_length,
                             const std::vector<string> &dictionary){



//    vector<string> dictionary {"the","of"};

    if (find(dictionary.begin(),dictionary.end(),"of") != dictionary.end()) {
        //FOUND!
    }

}