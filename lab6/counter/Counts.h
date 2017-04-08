//
// Created by mat on 06.04.17.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {

    class Counts {
    public:
        Counts();

        Counts(int howmany);

        void SetCount(int setto);
        const int GetCount() const ;

        friend int operator++(Counts &counttoincrement);
    private:
        int count_;
    }; //end of class
    int operator++(Counts &counttoincrement);
    bool operator==(const datastructures::Counts &one, const datastructures::Counts &two);
} //end of namespace


//przeładowania typu: <Counts, Counts>
bool operator<(const datastructures::Counts &one, const datastructures::Counts &two);
bool operator>(const datastructures::Counts &one, const datastructures::Counts &two);


//przeładowania typu: <int, Counts>
bool operator==(const int one, const datastructures::Counts &two);
bool operator<(const int one, const datastructures::Counts &two);
bool operator>(const int one, const datastructures::Counts &two);

//przeładowania typu: <Counts, int>
bool operator==( const datastructures::Counts &two,const int one);
bool operator<( const datastructures::Counts &two, const int one);
bool operator>(const datastructures::Counts &two, const int one);
#endif //JIMP_EXERCISES_COUNTS_H
