
#ifndef LAB2_SD_ATM_H
#define LAB2_SD_ATM_H

#include <ostream>
#include <vector>
#include "tranzactie.h"
#include <stack>
#include <algorithm>

vector<stack < int>>
sol = {};

class ATM {
private:
    vector<Tranzactie> tranz;
    Collection bani;
public:


    ATM() {
        bani = Collection();
    }

    ATM(Collection collection) {
        bani = collection;
    }

    void add_tranzactie(int &k, int banc) {
        Collection c;
        c.add(banc);
        Tranzactie t(k, banc, c);
        k++;
        tranz.push_back(t);
    }

    void extragere_tranzactie(int &k, int banc) {
        Collection c;
        c.add(banc);
        Tranzactie t(k, -banc, c);
        k++;
        tranz.push_back(t);
    }

    void extragere_tran(int &k, int suma, Collection c) {
        Tranzactie t(k, -suma, c);
        k++;
        tranz.push_back(t);
    }

    void add_bani(int elem) {
        bani.add(elem);
    }

    void extragere_bani(int elem) {
        bani.extragere(elem);
    }

    int size_tranz() {
        return tranz.size();
    }

    Tranzactie gettranz(int pos) {
        return tranz[pos];
    }

    static bool safe(int aux, int sum) {
        return (aux <= sum);
    }

    Collection getbani() {
        return bani;
    }

    VectorDinamic getval() {
        return bani.valori();
    }

    VectorDinamic getapar() {
        return bani.apar();
    }

    void
    afiseaza_modalitati_plata(VectorDinamic &bancnote, VectorDinamic &aparitii, int suma, vector<vector<int>> &solutii,
                              vector<int> &solutie_partiala, int index_bancnota, int &counter) {
        if (index_bancnota == bancnote.size()) {

            if (suma == 0 && !solutie_partiala.empty()) {

                solutii.push_back(solutie_partiala);
                counter++;
            }
            return;
        }

        int bancnota = bancnote[index_bancnota];
        int cantitate_maxima = aparitii[index_bancnota];

        for (int cantitate = 0; cantitate <= cantitate_maxima; ++cantitate) {

            if (cantitate * bancnota <= suma) {

                solutie_partiala.push_back(cantitate);

                afiseaza_modalitati_plata(bancnote, aparitii, suma - cantitate * bancnota, solutii, solutie_partiala,
                                          index_bancnota + 1, counter);

                solutie_partiala.pop_back();
            }
        }
    }

    void
    program_modalitati(VectorDinamic &bancnote, VectorDinamic &aparitii, vector<vector<int>> &solutii, int &counter,
                       int &ok,vector<int> &modalitate_aleasa) {
        if (!solutii.empty()) {
            cout << "Modalitatile de plata sunt:" << endl;

            for (int i = 0; i < solutii.size(); ++i) {
                cout << i + 1 << ". Modalitate de plata:";

                for (int j = 0; j < bancnote.size(); ++j) {
                    if (solutii[i][j] != 0) {
                        cout << " " << bancnote[j] << ":" << solutii[i][j];
                    }
                }
                cout << endl;
            }

        } else {
            cout << "Nu exista bancnote pentru suma dvs!\n";
            ok = 0;
        }
        if (ok) {
            int optiune;
            cout << "Alegeti modalitatea de plata (introduceti numarul corespunzator sau 0 pentru a iesi): ";
            cin >> optiune;


            if (optiune > 0 && optiune <= counter - 1) {

                modalitate_aleasa = solutii[optiune - 1];
                cout << "Metoda aleasa: ";
                for (int i = 0; i < bancnote.size(); ++i) {
                    if (modalitate_aleasa[i] != 0) {
                        cout << bancnote[i] << ":" << modalitate_aleasa[i] << " ";

                        aparitii.set(i, aparitii[i] - modalitate_aleasa[i]);
                    }
                }
                cout << endl;
            } else if (optiune != 0) {
                cout << "Optiune invalida!" << endl;
            }
        }
        cout << "Numarul ramas de aparitii pentru fiecare bancnota:" << endl;
        for (int i = 0; i < bancnote.size(); ++i) {
            cout << bancnote[i] << " : " << aparitii[i] << endl;
        }

    }


    friend ostream &operator<<(ostream &os, const ATM &atm) {
        for (int i = 0; i < atm.tranz.size(); ++i) {
            os << "Tranzactie: " << atm.tranz[i] << endl;
        }
        os << " Bancnote: " << atm.bani;
        return os;
    }


};

#endif
