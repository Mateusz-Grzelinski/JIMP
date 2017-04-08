//
// Created by mat on 06.04.17.
//

#include "Counts.h"


namespace datastructures {
    Counts::Counts() { count_ = 0; }

    Counts::Counts(int x) { count_ = x; }

    void Counts::SetCount(int setto) {
        count_=setto;
    }

    const int Counts::GetCount() const {
        return count_;
    }
}//end of namespace
std::ostream &datastructures::operator<<(std::ostream &os, const Counts &cout){
    os<<cout.GetCount();
    return os;
}

int datastructures::operator++( Counts &counttoincrement, int zero){
    int tmp=counttoincrement.GetCount();
    ++counttoincrement;
    return tmp;
}
int datastructures::operator++(Counts &counttoincrement){
    counttoincrement.count_++;
}

//przeładowania typu: <Counts, Counts>
bool datastructures::operator==(const Counts &one, const Counts &two){
    return (one.GetCount()==two.GetCount());
}
bool datastructures::operator<(const Counts &one, const Counts &two){
    return (one.GetCount()<two.GetCount());
}
bool datastructures::operator>(const Counts &one, const Counts &two){
    return (one.GetCount()>two.GetCount());
}
//
////przeładowania typu: <int, Counts>
//bool operator==(const int one, const datastructures::Counts &two){
//    return (one==two.GetCount());
//}
//bool operator<(const int one, const datastructures::Counts &two){
//    return (one<two.GetCount());
//}
//bool operator>(const int one, const datastructures::Counts &two){
//    return (one>two.GetCount());
//}
//
////przeładowania typu: <Counts, int>
//bool operator==( const datastructures::Counts &two, const int one){
//    return (one==two.GetCount());
//}
//bool operator<( const datastructures::Counts &two,const int one){
//    return (one==two.GetCount());
//}
//bool operator>(const datastructures::Counts &two, const int one){
//    return (one==two.GetCount());
//}