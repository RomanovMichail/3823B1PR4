//developmemt
#pragma once
#define STEP_CAPACITY 1000
#include "../lib_dmassive/dmassive.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
class DSU {
    TDMassive<int> parent;  
    TDMassive<bool> presence;
    //TDMassive<int> rank;
public:
    DSU(size_t n);
    ~DSU();
    void make_set(int elem);
    int find(int elem);
    void union_sets(int elem1, int elem2);
    //void clear();

};

DSU::DSU(size_t n) : presence(n), parent(n) {
    for (size_t i = 0; i < n; ++i) {
        presence.replace(i, false); 
        parent.replace(i, i);        
    }
}
DSU::~DSU() {


}
void DSU::make_set(int elem) {
    if (elem < 0 || elem >= presence.size()) {
        throw std::out_of_range("Element out of range");
    }
    presence.replace(elem, true);  
    parent.replace(elem, elem);     
}

int DSU::find(int elem) {
    if (elem < 0 || elem >= presence.size() || !presence.data()[elem]) {
        throw std::out_of_range("Element out of range or not present in the set");
    }
    if (parent.data()[elem] != elem) {
        parent.replace(elem, find(parent.data()[elem]));  
    }
    return parent.data()[elem];
}

void DSU::union_sets(int first, int second) {
    int root1 = find(first);
    int root2 = find(second);

    if (root1 != root2) {
        parent.replace(root2, root1); 
    }
}