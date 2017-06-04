//
// Created by mat on 04.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>

namespace tree {

//    klasa bazowa dla wszyskich porządków przechodzenia (pre, in, post)
    template<class T>
    class GenericIterator {
    public:
        GenericIterator(Node<T> *head_) : head_(head_) {}

//        metoda przechodzenia
        virtual void GenerateVectorAccordingToOrder(Node<T> *pivot) = 0;

        T operator++() { if (i_ >= 0) ++i_; }

        //zwraca wartość która aktualnie kryje się pod iteratorem
        T operator*() { return generatedvalues_[i_]; }

        //sprawdza czy iteratory są takie same: ich zawartość oraz pozycja
        bool operator!=(const GenericIterator &second) const {
            return generatedvalues_ != second.generatedvalues_ || i_ != second.i_;
        }

//        ustaiwa iteracje: przudatne przy kostruktorze, begin, end
        void setIteration(const size_t &in) { i_ = in; }

//        zwraca rozmiar iteratora
        size_t size() const { return generatedvalues_.size(); }

//        dodaje wartość do iteratora
        void pushBackValue(const T &val) { generatedvalues_.push_back(val); }

    private:
        Node<T> *head_;
        std::vector<T> generatedvalues_;
        size_t i_;
    };

//    PreOrder - Iterator
    template<class T>
    class PreOrderTreeIterator : public GenericIterator<T> {
    public:
        PreOrderTreeIterator(Node<T> *head_) : GenericIterator<T>(head_) {
            GenerateVectorAccordingToOrder(head_);
            this->setIteration(0);
        }

        void GenerateVectorAccordingToOrder(Node<T> *pivot) override {

            this->pushBackValue(pivot->value_);

            if (pivot->left_ != nullptr)
                GenerateVectorAccordingToOrder(pivot->left_.get());

            if (pivot->right_ != nullptr)
                GenerateVectorAccordingToOrder(pivot->right_.get());
        }
    };

//   InOrder - Iterator
    template<class T>
    class InOrderTreeIterator : public GenericIterator<T> {
    public:
        InOrderTreeIterator(Node<T> *head_) : GenericIterator<T>(head_) {
            GenerateVectorAccordingToOrder(head_);
            this->setIteration(0);
        }

        void GenerateVectorAccordingToOrder(Node<T> *pivot) override {
            if (pivot->left_ != nullptr)
                GenerateVectorAccordingToOrder(pivot->left_.get());

            this->pushBackValue(pivot->value_);

            if (pivot->right_ != nullptr)
                GenerateVectorAccordingToOrder(pivot->right_.get());
        }
    };

//    PostOrder - Iterator
    template<class T>
    class PostOrderTreeIterator : public GenericIterator<T> {
    public:
        PostOrderTreeIterator(Node<T> *head_) : GenericIterator<T>(head_) {
            GenerateVectorAccordingToOrder(head_);
            this->setIteration(0);
        }

        void GenerateVectorAccordingToOrder(Node<T> *pivot) override {

            if (pivot->left_ != nullptr)
                GenerateVectorAccordingToOrder(pivot->left_.get());

            if (pivot->right_ != nullptr)
                GenerateVectorAccordingToOrder(pivot->right_.get());

            this->pushBackValue(pivot->value_);
        }
    };


//jak podejść do dziedziczenia w przupdku …TreeView?
//    PreOrder - View
    template<class T>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<T> *tree) : iter_(tree->Root()) {}

        InOrderTreeIterator<T> begin() {
            iter_.setIteration(0);
            return iter_;
        }

        InOrderTreeIterator<T> end() {
            iter_.setIteration(iter_.size() - 1);
            return iter_;
        }

    private:
        InOrderTreeIterator<T> iter_;
    };

//   InOrder - View
    template<class T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(Tree<T> *tree) : iter_(tree->Root()) {}

        PreOrderTreeIterator<T> begin() {
            iter_.setIteration(0);
            return iter_;
        }

        PreOrderTreeIterator<T> end() {
            iter_.setIteration(iter_.size() - 1);
            return iter_;
        }

    private:
        PreOrderTreeIterator<T> iter_;
    };

//    PostOrder - View
    template<class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(Tree<T> *tree) : iter_(tree->Root()) {}

        PostOrderTreeIterator<T> begin() {
            iter_.setIteration(0);
            return iter_;
        }

        PostOrderTreeIterator<T> end() {
            iter_.setIteration(iter_.size() - 1);
            return iter_;
        }

    private:
        PostOrderTreeIterator<T> iter_;
    };

//    funkcja jako zwykły wrapper. Treaz nie trzeba pisać <typ>, kiedy wołasz klasę
//    PreOrder - funkcja wrapper
    template<typename T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    };

//    InOrder - funkcja wrapper
    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    };

//    PostOrder - funkcja wrapper
    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    };

}
#endif //JIMP_EXERCISES_TREEITERATORS_H
