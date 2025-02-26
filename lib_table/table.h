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

template <class Tkey, class Tval>
UnsortedTable<Tkey, Tval>::UnsortedTable(const Tlist<TPair<Tkey, Tval>>& list) {
    _data = list;
    _data = list.get_size();
}

template <class Tkey, class Tval>
UnsortedTable<Tkey, Tval>::UnsortedTable(const UnsortedTable<Tkey, Tval>& table) {
    _data = table._data;
    _size = table._size;
}

template <class Tkey, class Tval>
UnsortedTable<Tkey, Tval>& UnsortedTable<Tkey, Tval>::operator=(const UnsortedTable<Tkey, Tval>& table) {
    if (table != (*this)) {
        _data = table._data;
        _size = table._size;
    }
    return *this;
}

template <class Tkey, class Tval>
Tkey UnsortedTable<Tkey, Tval>::insert(Tval value) {
    Tkey new_key = generate_unique_key(); 
    TPair<Tkey, Tval> new_pair(new_key, value); 
    _data.add(new_pair);
    _size++; 
    return new_key; 
}

template <class Tkey, class Tval>
Tkey generate_unique_key() {
    static Tkey current_key = 0; 
    return ++current_key;
}