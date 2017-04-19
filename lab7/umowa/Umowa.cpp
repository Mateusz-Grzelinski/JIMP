//
// Created by mat on 18.04.17.
//

#include "Umowa.h"
using namespace std;

double Umowa::pobierzBrutto() { return wynagrodzenieBrutto; }
double Umowa::pobierzNetto() { return wynagrodzenieBrutto*0.9; }

double UmowaDzielo::pobierzNetto() { return wynagrodzenieBrutto*0.8; }
double UmowaPraca::pobierzNetto() { return wynagrodzenieBrutto*0.7;  }

double Pracownik::pobierzPensje() { return umowa->pobierzNetto(); }

ostream& operator<<(ostream & os, Pracownik &worker) {
    os<<"imie: " <<worker.imie<<endl;
    os<<"nazwisko: " <<worker.nazwisko<<endl;
    os<<"pesel: " <<worker.pesel<<endl;
    os<<"pensja: " <<worker.pobierzPensje()<<endl;
    return os;
}

Pracownik::Pracownik(const Pracownik &) {

}