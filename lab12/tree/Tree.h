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

        std::unique_ptr<Node<T>> left_;
        std::unique_ptr<Node<T>> right_;

        T value_;
    };

    template<class T>
    Node<T>::Node(T in) {
        left_= nullptr;
        right_= nullptr;
        value_ = in;

    }
//  Tree
//---------------------------------------------------------------------------------------

    template<class T>
    class Tree {
    public:
//        friend class Node<T>;
        Tree();
        Tree(T in);

        void Insert(T in);
        std::size_t Size() const ;
        std::size_t Depth() const ;
        bool Find(const T &search, const std::unique_ptr<Node<T>> &root ) ;
        T Remove(const T &search);
        void Print(std::unique_ptr<Node<T>> &root ) const;
        auto Value();

    private:
        std::size_t DFSDepth(const std::unique_ptr<Node<T>> &root) const;
        std::unique_ptr<Node<T>> head_;
        std::size_t size_;
    };



    template<class T>
    Tree<T>::Tree() {
        size_=0;
        Node<T> one( T() );
        head_= nullptr;
    }

    template<class T>
    Tree<T>::Tree(T in) {
        head_ = std::make_unique<Node<T>>(in);
        size_ = 1;
    }

    template<class T>
    void Tree<T>::Insert(T in) {
//        Node *tmp = head_.get(); //sposob przechodzenia
//        Node<T> &tmp = head_;

        if (head_.get()== nullptr){
            head_ = std::make_unique<Node<T>>(in);
            ++size_;
        }
        else {
            auto *pivot = head_.get();
            bool stop=false;
            while (!stop) {
                if (pivot->value_ < in) {
                    if (pivot->left_ == nullptr) {
                        pivot->left_ = std::make_unique<Node<T>>(in);
                        stop = true;
                        ++size_;
                    }
                    pivot = pivot->left_.get();
                }
                else {
                    if (pivot->right_ == nullptr) {
                        pivot->right_ = std::make_unique<Node<T>>(in);
                        stop = true;
                        ++size_;
                    }
                        pivot = pivot->right_.get();
                }
            }
        }
    }

    template<class T>
    bool Tree<T>::Find(const T &search, const std::unique_ptr<Node<T>> &root ) {

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
    T Tree<T>::Remove(const T &search) {
        //not implemented

        --size_;
        return nullptr;
    }

    template<class T>
    void Tree<T>::Print(std::unique_ptr<Node<T>>& root) const {
        std::cout<<root->value_;
        if(root->left_!= nullptr)
            Print(root->left_);
        if(root->right_!= nullptr)
            Print(root->right_);
    }

    template<class T>
    auto Tree<T>::Value() {
        return head_->value_;
    }

    template<class T>
    std::size_t Tree<T>::Depth() const {
        return DFSDepth(head_);
    }

    template<class T>
    std::size_t Tree<T>::DFSDepth(const std::unique_ptr<Node<T>> &root) const {
        if (root!= nullptr)
            return 1 + std::max(this->DFSDepth(root->left_), this->DFSDepth(root->right_));
        return 0;
    }

    template<class T>
    std::size_t Tree<T>::Size() const {
        return size_;
    }
}
#endif //JIMP_EXERCISES_BINARYTREE_H
