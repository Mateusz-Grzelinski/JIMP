//
// Created by mat on 11.03.17.
//

#include "GreatestProduct.h"
#include <iostream>
#define abs(x) ((x)<0 ? -(x) : (x))

void GreatestPositive(int negative, int positive, int &k, int &wynik, int &p, int &n);

using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k){
    int wynik=1;
    vector<int> positiveList, negativeList;
    int minusNumbers=0, plusNumber=0;
    for(int v : numbers){ //przelicz ile jest liczb negatywnych i dodatnich
        if (v>0)
            plusNumber++;
        else
            minusNumbers++;
    }

    if (numbers.size()>=k) {
        //przypadek specjalny, gdy wynik MUSI być negatywny
        if ( (k%2) && plusNumber==0 ){  //wybierz k najmniejszych liczb
                for (int insertValue : numbers) {
                    if (insertValue > 0) {
//                        cout<<"positive: "; PrintVector(positiveList);
                        if (positiveList.size() == 0)
                            positiveList.push_back(insertValue);
                        else
                            insertElementKeepMin(positiveList, insertValue, k);
                    }
                    else if (negativeList.size() == 0)
                        negativeList.push_back(insertValue);
                    else
                        insertElementKeepMin(negativeList, insertValue, k);
                }
        }else {
            for (int insertValue : numbers) {
                if (insertValue > 0) {
//                    cout << "positive: "; PrintVector(positiveList);
                    if (positiveList.size() == 0)
                        positiveList.push_back(insertValue);
                    else
                        insertElementKeepMax(positiveList, insertValue, k);
                } else if (negativeList.size() == 0)
                    negativeList.push_back(insertValue);
                else
                    insertElementKeepMax(negativeList, insertValue, k);
            }
        }
    } else return 0; //kiedy k jest za duże

//    cout<<"negative(F): "; PrintVector(negativeList);
//    cout<<"positive(F): "; PrintVector(positiveList);
    int p = positiveList.size(), n = negativeList.size(), negative=0, positive=0;



    while(k>0){ //przypadek, kiedy wynik wyjdzie dodatni
        cout<<"k: "<<k<<" p: "<<p<<" n: "<<n<<endl;
        if (n>1 && k>1) negative = negativeList.at( n-1 ) * negativeList.at( n-2 ); //pary liczb
        else if ((k==1 || n==1) && n!=0) negative = negativeList.at( n-1 );   //pojedyńcze liczby

        if (p>1 && k>1) positive = positiveList.at( p-1 ) * positiveList.at( p-2 ); //pary licz
        else if ((k==1 || p==1) && p!=0) positive = positiveList.at( p-1 );   //pojedyńcze liczby
        cout<<"negative: "<< negative<<" positive: "<< positive<<endl;

        GreatestPositive(negative, positive, k, wynik, p, n);

    } //koniec pętli while
    return wynik;
}

void GreatestPositive(int negative, int positive, int &k, int &wynik, int &p, int &n) {
    if (k > 1) { //rozważam pray licz, parę i pojedyńczą liczbę
            if (p > 1 && n > 1)  //rozważam 2 pary
                if (negative > positive) {
                    wynik *= negative;
                    n -= 2;
                    k -= 2;
                } else {
                    wynik *= positive;
                    p -= 2;
                    k -= 2;
                }
            else if ( p==1 && n>1) { //positive została 1 liczba, negative para
                if (negative > positive) {
                    wynik *= negative;
                    n -= 2;
                    k -= 2;
                } else {
                    wynik *= positive;
                    p --;
                    k --;
                }
            }
            else if (p>0 && n==1) { //jedna liczba ujemna i wiele dodatnich
                if (p==1) {
                    wynik *= positive;
                    p--;
                    k--;
                }
                else{
                    wynik *= positive;
                    p -= 2;
                    k -= 2;
                }
            }
            else if (n==0) {    //brak ujemnych, wiele dodatnich
                wynik *= positive;
                p -= 2;
                k -= 2;
            } else {//if (p==0){   //brak dodatnich wiele ujemnych
                wynik*=negative;
                n -= 2;
                k -= 2;
            }
        }
        else{ //pojedyńcze liczby gdy k==1 (czyli ostatni ruch)
            if (p==0) {
                wynik*=negative;
                n--;
                k--;
            }
            else {
                wynik *= positive;
                p--;
                k--;
            }
        }
}

//funkcja która sortuje i zachowuje największe elementy w k elementowej tablicy
void insertElementKeepMax(std::vector<int> &elements, const int insertValue, const int k) {

    vector<int>::iterator indexMinToChange;
    indexMinToChange = elements.begin();
    if(elements.size()==k){
        if (abs(insertValue) >= abs(elements.back())) {     // jesli insertValue jest większe od wszystkiego
            elements.push_back(insertValue);
            elements.erase(elements.begin());
        } else {  //jesli element  trzeba wsadzić do środka:
            for (vector<int>::iterator i = elements.begin(); i != elements.end(); ++i) {
                if (abs(insertValue) >= abs(*i)) {
                    indexMinToChange = i;
                }
            }
            if (!(abs(insertValue) <= abs(elements.front() ))) {
                elements.emplace(++indexMinToChange, insertValue);
                elements.erase(elements.begin());
            }
        }
    } else{
        if ( abs(insertValue) <= abs(elements.front() )) elements.emplace( elements.begin(), insertValue );
        else if ( abs(insertValue) >= abs(elements.back())) elements.push_back(insertValue);
        else {
            for( vector<int>::iterator i= elements.begin(); i!=elements.end(); ++i){
                if ( abs(insertValue) >= abs(*i)) {
                    indexMinToChange = i;
                }
            }
            elements.emplace(++indexMinToChange, insertValue);
        }
    }
}

//funkcja sortuje i zachowuje najmniejsze elementy w k elementowej tablicy
void insertElementKeepMin(std::vector<int> &elements, const int insertValue, const int k) {
    vector<int>::iterator indexMinToChange;
    indexMinToChange = elements.begin();
    if(elements.size()==k){
        if (abs(insertValue) <= abs(elements.back())) {     // jesli insertValue jest większe od wszystkiego
            elements.push_back(insertValue);
            elements.erase(elements.begin());
        } else {  //jesli element  trzeba wsadzić do środka:
            for (vector<int>::iterator i = elements.begin(); i != elements.end(); ++i) {
                if (abs(insertValue) <= abs(*i)) {
                    indexMinToChange = i;
                }
            }
            if (!(abs(insertValue) >= abs(elements.front() ))) {
                elements.emplace(++indexMinToChange, insertValue);
                elements.erase(elements.begin());
            }
        }
    } else{
        if ( abs(insertValue) >= abs(elements.front() )) elements.emplace( elements.begin(), insertValue );
        else if ( abs(insertValue) <= abs(elements.back())) elements.push_back(insertValue);
        else {
            for( vector<int>::iterator i= elements.begin(); i!=elements.end(); ++i){
                if ( abs(insertValue) <= abs(*i)) {
                    indexMinToChange = i;
                }
            }
            elements.emplace(++indexMinToChange, insertValue);
        }
    }
}

void PrintVector(const vector<int> numbers){
    for(auto v : numbers)
        cout<< v<< " ";
    cout<<endl;
}