#pragma once
#include"iostream"
#include"../lib_list/List.h"

template <class Tkey, class Tval>
class ITable {
    virtual Tkey insert(Tval value);
    virtual void insert(Tkey key, Tval value);
    virtual void erase(Tkey key);
    virtual find(Tkey key);
};