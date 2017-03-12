//
// Created by mat on 09.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H
//struct ForwardList;

struct ForwardList {
    int value=0;
    struct ForwardList *next=nullptr;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);
ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
