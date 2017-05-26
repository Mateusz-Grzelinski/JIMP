//
// Created by mat on 25.05.17.
//

#include "BinaryTree.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace tree;

int main(){
//    działą:
    BinaryTree<int> first;
//    co to jest:
//    BinaryTree<int> first(); // dlaczego nie mogę na first operować?

//    to działą:
    Node<int> nodzik(5);
    Node<int>(8);

//    dziwny bład:
    std::make_unique(Node<int>(5));


    return 0;
}