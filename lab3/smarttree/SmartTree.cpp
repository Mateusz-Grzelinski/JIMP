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


std::unique_ptr <SmartTree> datastructures::RestoreTree(const std::string &tree){
    //    for(auto i=tree.begin(); i!=tree.end(); i++){
//        if (i=="[")    } tak nie chce porównywać...
    std::unique_ptr<SmartTree> reconstruct = std::make_unique<SmartTree>();
    int i=0;
    std::string
    if( tree[i]=='[' )



}

/*
std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
    const std::string str=tree;
    std::string temp="";
    std::unique_ptr <SmartTree> tree_out;
    int left_cnt=0,right_cnt=0,i=0,k=0;
    do{
        if(str[i]=='['){
            left_cnt++;
            i++;
            if(left_cnt==1){
                while(str[i]!=32 and str[i]!=']' ){
                    temp+=str[i];
                    i++;
                }
                if(temp=="none"){
                    return nullptr;
                }
                tree_out=std::move(CreateLeaf(std::stoi(temp)));
                temp="";

            }
            if(left_cnt==2 and k==0){
                tree_out->left=std::move(RestoreTree(&(str[i-1])));
                k=1;
            }
            if(left_cnt==2 and k==1){
                tree_out->right=std::move(RestoreTree(&(str[i-1])));
            }
        }
        if(str[i]==']'){
            right_cnt++;
            left_cnt--;
        }
        i++;

    }while(left_cnt!=0);
    return tree_out;
}
}
 */
