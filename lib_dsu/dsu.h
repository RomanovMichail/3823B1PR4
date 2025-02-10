//developmemt
#pragma once
#define STEP_CAPACITY 1000
#include "../lib_dmassive/dmassive.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

class DSU {
    TDMassive<int> parent;  
    //TDMassive<bool> presence;
    TDMassive<int> rank;
public:
    DSU(size_t n);
    ~DSU();
    void make_set(int elem);
    int find(int elem);
    void union_sets(int elem1, int elem2);
    void clear();

};

DSU::DSU(size_t n) : parent(n), rank(n) {
    for (size_t i = 0; i < n; ++i) {
        parent.replace(i, i);
        rank.replace(i, 0);
    }
}
DSU::~DSU() {


}
void DSU::make_set(int elem) {
    if (elem >= parent.size()) {
        throw std::out_of_range("Element out of range");
    }
    parent.replace(elem, elem);  
    rank.replace(elem, 0);        
}

int DSU::find(int elem) {
    if (elem < 0 ||elem >= parent.size()) {
        throw std::out_of_range("Element out of range");
    }
    if (parent.data()[elem] != elem) {
        parent.replace(elem, find(parent.data()[elem])); 
    }
    return parent.data()[elem];
}

void DSU::union_sets(int elem1, int elem2) {
    int root1 = find(elem1);
    int root2 = find(elem2);

    if (root1 != root2) {
        if (rank.data()[root1] < rank.data()[root2]) {
            parent.replace(root1, root2);
        }
        else if (rank.data()[root1] > rank.data()[root2]) {
            parent.replace(root2, root1);
        }
        else {
            parent.replace(root2, root1);
            rank.replace(root1, rank.data()[root1] + 1);
        }
    }
}