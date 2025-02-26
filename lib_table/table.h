#pragma once
#include"iostream"
#include"../lib_list/List.h"
#include"../lib_pair/pair.h"
#include"string.h"
#include"../lib_itable/Itable.h"


template <class Tkey, class Tval>
class UnsortedTable : ITable<Tkey, Tval> {
    Tlist<TPair<Tkey, Tval>> _data;
    size_t _size;
public:
    UnsortedTable(const Tlist<TPair<Tkey, Tval>>& list);
    UnsortedTable(const UnsortedTable<Tkey, Tval>& table);
    UnsortedTable& operator = (const UnsortedTable<Tkey, Tval>& table);
    Tkey insert(Tval value);
};

