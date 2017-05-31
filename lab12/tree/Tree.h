//
// Created by mat on 25.05.17.
//

/* implementaja drzewa na Template */

#ifndef JIMP_EXERCISES_BINARYTREE_H
#define JIMP_EXERCISES_BINARYTREE_H
#include <memory>
#include <iostream>

namespace tree {
//  Node
//---------------------------------------------------------------------------------------
    template<class T>
    class Node{
    public:
        Node(T in);
        bool visited_;
        std::unique_ptr<Node<T>> left_;
        std::unique_ptr<Node<T>> right_;
        T value_;
    };

    template<class T>
    Node<T>::Node(T in) {
        visited_ = false;
        left_= nullptr;
        right_= nullptr;
        value_ = in;

    }
//  BinaryTree
//---------------------------------------------------------------------------------------

    template<class T>
    class BinaryTree {
    public:
        friend Node;
        BinaryTree();
        BinaryTree(T in);

        void Insert(T in);
        std::size_t Size() const ;
        bool Find(const T &search, const std::unique_ptr<Node<T>> &root = head_) ;
        T Remove(const T &search);
        void Print(std::unique_ptr<Node<T>> root=head_) const;

    private:
        std::unique_ptr<Node<T>> head_;
        std::size_t size_;
    };


    template<class T>
    BinaryTree<T>::BinaryTree() {
        size_=0;
        Node<T> one(1);
        head_= nullptr;
    }

    template<class T>
    BinaryTree<T>::BinaryTree(T in) {
        head_ = std::make_unique<Node<T>>(in);
        size_ = 1;
    }

    template<class T>
    void BinaryTree<T>::Insert(T in) {
//        Node *tmp = head_.get(); //sposob przechodzenia
        if (head_== nullptr){
            head_ = std::make_unique<Node<T>>(in);
            ++size_;
        }
        else {
            auto &pivot = head_;
            bool go = true;
            while (go) {
                if (pivot->value_ < in)
                    pivot = &pivot->left_;
                else
                    pivot = &pivot->right_;
                if (pivot == nullptr)
                    go = false;
            }
            pivot = std::make_unique<Node<T>>(in);
        }
    }

    template<class T>
    std::size_t BinaryTree<T>::Size() const {
        return size_;
    }

    template<class T>
    bool BinaryTree<T>::Find(const T &search, const std::unique_ptr<Node<T>> &root ) {

        if (&root== nullptr)
            return false;
        if (&root->value_==search)
            return true;
        if (&root->value_ < search)
            return this->Find(search, &root->left_);
        else
            return this->Find(search, &root->right_);
    }

    template<class T>
    T BinaryTree<T>::Remove(const T &search) {
        //not implemented

        --size_;
        return nullptr;
    }

    template<class T>
    void BinaryTree<T>::Print(std::unique_ptr<Node<T>> root) const {
        std::cout<<root->value_;
        if(root->left_!= nullptr)
            Print(root->left_);
        if(root->right_!= nullptr)
            Print(root->right_);
    }
}
#endif //JIMP_EXERCISES_BINARYTREE_H
