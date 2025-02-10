#pragma once
#define STEP_CAPACITY 1000
#include "../lib_dmassive/dmassive.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
class DSU {
    TDMassive<int> parent;  
    TDMassive<int> rank;
public:
    DSU(size_t n);
    ~DSU();
    void make_set(int elem);
    int find(int elem);
    void union_sets(int elem1, int elem2);
    void clear();

};

