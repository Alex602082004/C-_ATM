
#ifndef LAB2_SD_TRANZACTIE_H
#define LAB2_SD_TRANZACTIE_H

#include <ostream>
#include <vector>
#include "colection.h"

class Tranzactie{
private:
    int id;
    int suma;
    Collection banc;
public:
    Tranzactie(int id, int suma, const Collection &banc) : id(id), suma(suma), banc(banc) {}

    Tranzactie() {
        id=-1;
        suma=-1;
    }

    int getId() const {
        return id;
    }

    int getSuma() const {
        return suma;
    }

    Collection getBanc() {
        return banc;
    }

    friend ostream &operator<<(ostream &os, const Tranzactie &tranzactie) {
        os << "id: " << tranzactie.id << " suma: " << tranzactie.suma << " banc: " <<endl<< tranzactie.banc;
        return os;
    }


};

#endif
