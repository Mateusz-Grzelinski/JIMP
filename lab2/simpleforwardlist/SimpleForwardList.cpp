//
// Created by mat on 09.03.17.
//

#include "SimpleForwardList.h"


ForwardList *CreateNode(int value){
    ForwardList *node= new ForwardList;
    (*node).value=value;
    (*node).next=nullptr;
    return node;
}


void DestroyList(ForwardList *list){
    ForwardList *tmp;
    while(list!=nullptr){
        tmp=list;
        list=list->next;
        delete tmp;
    }
}