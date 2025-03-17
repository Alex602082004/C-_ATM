
#ifndef CURS4_VECTORDINAMIC_H
#define CURS4_VECTORDINAMIC_H


#include <iostream>

using namespace std;

class VectorDinamic {
private:

    int capacity;
    int nrElems;
    int *elems;

    void resize() {
        int *aux = new int[capacity++];
        for (int i = 0; i < nrElems; i++)
            aux[i] = this->elems[i];
        delete[] elems;
        this->elems = aux;
        this->capacity = capacity++;
    }

public:
    VectorDinamic() {
        capacity = 0;
        nrElems = 0;
        elems = nullptr;
    }


    VectorDinamic(int capacitate) {
        if (capacitate < 1) {
            throw invalid_argument("capacitate negativa");
        }
        this->elems = new int[capacitate];
        this->nrElems = 0;
        this->capacity = capacitate;
    }

    void set_size(int size) {
        nrElems = size;
    }

    void set_cap(int cap) {
        capacity = cap;
    }

    int getAt(int i) const {
        if ((i >= 0) && (i < nrElems)) {
            return this->elems[i];
        } else {
            throw invalid_argument("pozitia nu este valida ");
        }
    }

    const int &operator[](int index) const {
        return elems[index];
    }

    void change(int i, int j) {
        swap(elems[i], elems[j]);
    }

    void remove(int index) {
        for (int i = index; i < nrElems - 1; ++i) {
            {
                for (int j = i; j < nrElems; ++j) {
                    elems[j] = elems[j + 1];
                }
                nrElems--;
            }
        }
    }

    void push_back(int e) {
        if (nrElems == capacity)
            resize();

        this->elems[nrElems++] = e;
    }

    void set(int index, int value) {
        elems[index] = value;
    }

    int size() const {
        return this->nrElems;
    }

    VectorDinamic &operator=(const VectorDinamic &v) {
        capacity = v.capacity;
        nrElems = v.nrElems;
        elems = v.elems;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const VectorDinamic &dinamic) {
        for (int i = 0; i < dinamic.nrElems; ++i)
            os << dinamic[i] << endl;
        return os;
    }

};

#endif
