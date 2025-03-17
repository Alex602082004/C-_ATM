
#ifndef LAB2_SD_UI_H
#define LAB2_SD_UI_H

#include "atm.h"
#include <iostream>

using namespace std;

class UI {
private:
    ATM atm;
public:
    explicit UI(ATM &atm) : atm(atm) {}

    void print_menu() {
        cout << "1.Afisare tranzactii"
                "\n2.Afisare bancnote"
                "\n3.Adaugare bancnota"
                "\n4.Extragere bancnota"
                "\n5.Plata suma"
                "\n0.Inchidere";
    }

    void run() {
        int k;
        while (true) {
            print_menu();
            cout << "\nChoose option:";
            int option;
            cin >> option;
            if (option == 1)
                afisare_tranz();
            if (option == 2)
                afisare_banc();
            if (option == 3)
                add_banc(k);
            if (option == 4)
                extragere_banc(k);
            if (option == 5)
                plata(k);
            if (option == 0)
                exit(0);
        }
    }

    void afisare_tranz() {
        for (int i = 0; i < atm.size_tranz(); ++i) {
            cout << atm.gettranz(i);
        }
    }

    void plata(int &k) {
        VectorDinamic v1 = atm.getval();
        VectorDinamic v2 = atm.getapar();
        cout << "Suma:";
        int suma, ok = 1;
        cin >> suma;
        int cnt = 1;
        vector<vector<int>> solutii;
        vector<int> solutie_partiala;
        atm.afiseaza_modalitati_plata(v1, v2, suma, solutii, solutie_partiala, 0, cnt);
        vector<int> ales;
        atm.program_modalitati(v1, v2, solutii, cnt, ok, ales);
        VectorDinamic v3(int(ales.size()));
        VectorDinamic v4(int(ales.size()));
        for (int i = 0; i < ales.size(); ++i) {
            if (ales[i] != 0) {
                v4.push_back(v1[i]);
                v3.push_back(ales[i]);
            }
        }

        Collection c(v4, v3);
        if (ok)
            atm.extragere_tran(k, suma, c);
    }


    void afisare_banc() {
        cout << atm.getbani();
    }

    void add_banc(int &k) {
        int banc;
        cout << "Adauga bancnota:";
        cin >> banc;
        atm.add_bani(banc);
        atm.add_tranzactie(k, banc);
    }

    void extragere_banc(int &k) {
        int banc;
        cout << "Extrage bancnota:";
        cin >> banc;
        atm.extragere_bani(banc);
        atm.extragere_tranzactie(k, banc);
    }
};

#endif
