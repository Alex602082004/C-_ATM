

#ifndef SEM3_COLLECTION_H
#define SEM3_COLLECTION_H

#include <iostream>
#include <utility>
#include <vector>
#include "vector_dinamic.h"

using namespace std;

class Collection {
private:
    VectorDinamic v1; ///valori
    VectorDinamic v2; ///aparitii

public:
    Collection() {
        v1 = VectorDinamic();
        v2 = VectorDinamic();
    }

    Collection(const VectorDinamic &V1, const VectorDinamic &V2) : v1(V1), v2(V2) {}

    void set_val(VectorDinamic v){
        v1=v;
    }

    void add(int elem) {

        for (int i = 0; i < v1.size(); ++i)
            if (v1[i] == elem) {
                v2.set(i, v2[i] + 1);
                return;
            }

        v1.push_back(elem);
        v2.push_back(1);

    }


    void sort() {
        for (int i = 0; i < v1.size() - 1; ++i) {
            for (int j = i + 1; j < v1.size(); ++j) {
                if (v1[i] < v1[j]) {
                    v1.change(i, j);
                    v2.change(i, j);
                }
            }

        }
    }

    void create_ap(vector<int> v){
        v2.set_size(int(v.size()));
        v2.set_cap(int(v.size()));
        for (int i = 0; i < v2.size(); ++i) {
            v2.set(i,v[i]);
        }
    }


    VectorDinamic valori() {
        return v1;
    }

    VectorDinamic apar() {
        return v2;
    }

    void remove(int elem) {
        v1.remove(elem);
    }

    void extragere(int elem) {
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] == elem) {
                if (v2[i] == 0) {
                    cout << "Nu exista bancnote!";
                    return;
                }
                if (v2[i] != 0)
                    v2.set(i, v2[i] - 1);
            }
        }
    }

    int search(int elem) {
        int position = -1;
        for (int i = 0; i < v1.size(); ++i)
            if (elem == v1[i])
                position = i;

        return position;
    }

    int cap() {
        return v1.size();
    }

    int nroccurrences(int elem) {
        for (int i = 0; i < v1.size(); ++i)
            if (v1[i] == elem)
                return v2[i];
        return 0;
    }

    void set_occurrences(int index, int value) {
        v2.set(index, value);
    }

    int getAt(int position) {
        return v1[position];
    }

    friend ostream &operator<<(ostream &os, const Collection &collection) {
        for (int i = 0; i < collection.v1.size(); ++i)
            os << collection.v1[i] << ":" << collection.v2[i] << endl;

        return os;
    }
};

#endif
