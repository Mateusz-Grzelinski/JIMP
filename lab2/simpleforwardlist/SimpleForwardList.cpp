//
// Created by mat on 09.03.17.
//

#include <stddef.h>
#include "SimpleForwardList.h"


ForwardList *CreateNode(int value){
    ForwardList *node= new ForwardList;
    (*node).value=value;
    (*node).next=nullptr;
    return node;
}

ForwardList *PushFront(ForwardList *list, int value){
    if (list) {
        ForwardList *newHead = CreateNode(value);
//    newHead->value=value;
        newHead->next = list;
        return newHead;
    }
    else return nullptr;
}

void Append(ForwardList *list, ForwardList *tail){
    if(list) {
        ForwardList *iterator = list;
        while (iterator->next != nullptr) //ustaw wskaźnik na ostatni  element
            iterator = iterator->next;
        iterator->next = tail;
    }


}

void DestroyList(ForwardList *list){
    ForwardList *tmp;
    while(list!=nullptr){
        tmp=list;
        list=list->next;
        delete tmp;
    }
}
