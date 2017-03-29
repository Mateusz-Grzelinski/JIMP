//
// Created by mat on 09.03.17.
//

#include <iostream>
#include "SimpleForwardList.h"

using namespace std;

int main(){
    ForwardList *head = CreateNode(27);
    cout<<head->value<<head->next;
    return 0;
}