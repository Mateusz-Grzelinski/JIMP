//
// Created by mat on 04.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <Tree.h>
#include <vector>

/*
operator++, operator*, operator!= i pewnie PreOrderTreeView z metodami begin() end(),
*/
namespace tree {

    template <class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Node<T> *head_) : head_(head_) {
            GenerateVector(head_);
            i_=generatedvalues_.size()-1; }
        void GenerateVector(Node<T> *pivot) {
            if (pivot->left_ != nullptr)
                GenerateVector(pivot->left_.get());

            generatedvalues_.push_back(pivot->value_);

            if(pivot->right_ != nullptr)
                GenerateVector(pivot->right_.get());

        }
        //inkrementuje iterator, ale na odwrót, bo vector dadaje wszsyttko od tyłu!!
        T operator++(){ if(i_>=0) --i_; }
        //zwraca wartość która aktualnie kryje się pod iteratorem
        T operator*(){ return generatedvalues_[i_]; }
        //sprawdza czy iteratory są takie same: ich zawartość oraz pozycja
        bool operator!=(const InOrderTreeIterator &second) const{
            return generatedvalues_!=second.generatedvalues_ || i_ != second.i_; }

//    protected:
        Node<T> * head_;
        std::vector<T> generatedvalues_;
        size_t i_;
    };

    template <typename T>
    class InOrderTreeView : public InOrderTreeIterator<T>{
    public:
        InOrderTreeView(Tree<T> *tree) :  InOrderTreeIterator<T>(tree->Root()), tree_(tree) {}

        InOrderTreeIterator<T> begin() /*return generatedvalues_.end();*/{ /*return generatedvalues_.begin();*/ }
        InOrderTreeIterator<T> end()  {  /*return generatedvalues_.end();*/ }

    private:
        Tree<T> *tree_;
    };


    template <class T>
    class InOrder{

    };

}
#endif //JIMP_EXERCISES_TREEITERATORS_H
