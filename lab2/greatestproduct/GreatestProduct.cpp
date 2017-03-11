//
// Created by mat on 11.03.17.
//

#include "GreatestProduct.h"
#include <iostream>


using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k){
    int wynik=1;
//    cout<< "numbers: ";
//    PrintVector(numbers);
//    cout<<"k to:"<<k<<endl;
    if (numbers.size()>k ){
        vector<int> biggestElements; //k największych elementów, z których powstanie iloczyn; zaczynam od losowego elementu
        for (int v : numbers){
//            cout<<"v to; "<<v<<endl;
            InsertWithSort(biggestElements, v, k);
            PrintVector(biggestElements);

        }
        for (int tmp : biggestElements)
            if (tmp!=0) //do poprawy tak żeby dziłało z liczbami ujemnymi
                wynik *= tmp;
        return wynik;
    }
    else if (numbers.size()==k) {
        for (int v : numbers)
//            if (v!=0)
                wynik *= v;
        return wynik;
    }
    else return 0;
}

void InsertWithSort(std::vector<int> &biggestElements, const int v, const int k) {
    if (biggestElements.size() < k)
        biggestElements.push_back(v);
    else {
        //znajdz liczbę najmniejszą w biggestElements, ale v też musi być większy od tej najmniejszej
        vector<int>::iterator tmp = biggestElements.begin();
        bool flag=false;
        for( vector<int>::iterator i= biggestElements.begin(); i<biggestElements.end(); ++i){
//            cout << " w pętli i to: "<< *i<< ", tmp: "<< *tmp<<endl;
            if (*tmp >= *i && v > *i) {
                tmp = i;
                flag = true;
            }
        }
        if (flag)
            *tmp=v;
    }

}



void PrintVector(const vector<int> numbers){
    for(auto v : numbers)
        cout<< v<< " ";
    cout<<endl;
}