//
// Created by mat on 20.03.17.
//

#include <ostream>
#include <string>
#include <memory>
#include "SmartTree.h"

using namespace datastructures;

std::unique_ptr <SmartTree> datastructures::CreateLeaf(int value){
    std::unique_ptr<SmartTree> leafNew= std::make_unique<SmartTree>();
    leafNew->value=value;
    return leafNew;
}

std::unique_ptr <SmartTree> datastructures::
InsertLeftChild(std::unique_ptr <SmartTree> tree, std::unique_ptr <SmartTree> left_subtree){
//    std::tree <SmartTree> miniHead = std::make_unique<SmartTree>();
    tree->left=move(left_subtree);
    return tree;
}

std::unique_ptr <SmartTree> datastructures::
InsertRightChild(std::unique_ptr <SmartTree> tree, std::unique_ptr <SmartTree> right_subtree){
    tree->right=move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr <SmartTree> &unique_ptr, std::ostream *out){
    if (unique_ptr!= nullptr) {
        if (unique_ptr->left != nullptr)
            PrintTreeInOrder(unique_ptr->left, out);
        *out << (unique_ptr->value) << ", ";
        if (unique_ptr->right != nullptr)
            PrintTreeInOrder(unique_ptr->right, out);
    }
}

std::string datastructures::DumpTree(const std::unique_ptr <SmartTree> &tree){
    std::string result;
    if (tree!= nullptr) {
        result.append("[");
        result.append( std::to_string(tree->value) );
        result.append(" ");
        if (tree->left!= nullptr){

            result.append(DumpTree(tree->left));
        }
        else
            result.append("[none]");

        result.append(" ");

        if (tree->right!= nullptr) {
            result.append(DumpTree(tree->right));
        }
        else
            result.append("[none]");
    }
    result.append("]");
    return result;
}

