#pragma once
#include"iostream"
#include"../lib_list/List.h"
#include"../lib_pair/pair.h"
#include"string.h"
#include"../lib_itable/Itable.h"
template <class Tkey>
void generate_key(Tkey& key, int val, size_t size) {
    key = val + size;
}

template <class Tkey>
void generate_key(Tkey& key, std::string val, size_t size) {
    key = val + char(size);
}

template <class Tkey, class Tval>
class UnsortedTable : public ITable<Tkey, Tval> {
    TList<TPair<Tkey, Tval>> _data;
    size_t _size;
public:
    UnsortedTable();
    UnsortedTable(const TList<TPair<Tkey, Tval>>& list);
    UnsortedTable(const UnsortedTable<Tkey, Tval>& table);
    UnsortedTable& operator = (const UnsortedTable<Tkey, Tval>& table);
    Tkey insert(Tval value);
    void insert(Tkey key, Tval value);
    void erase(Tkey key);
    Tval find(Tkey key) const ;
    bool search(Tkey key);
    const Tval& operator[](const Tkey key) const;
    Tval& operator[](const Tkey key);
};

template <class Tkey, class Tval>
 UnsortedTable<Tkey, Tval>:: UnsortedTable() {
    _size = 0;
}

template <class Tkey, class Tval>
 UnsortedTable<Tkey, Tval>:: UnsortedTable(const TList<TPair<Tkey, Tval>>& list) {
    _data = list;
    _size = list.get_size();
}

template <class Tkey, class Tval>
 UnsortedTable<Tkey, Tval>:: UnsortedTable(const UnsortedTable<Tkey, Tval>& table) {
    _data = table._data;
    _size = table._size;
}

template <class Tkey, class Tval>
 UnsortedTable<Tkey, Tval>& UnsortedTable<Tkey, Tval>::operator=(const UnsortedTable<Tkey, Tval>& table) {
    if (this != &table) {
        _data = table._data;
        _size = table._size;
    }
    return *this;
}

 template <class Tkey, class Tval>
 Tkey UnsortedTable<Tkey, Tval>::insert(Tval value) {
     Tkey new_key;
     generate_key(new_key, value, _size);
     if (!search(new_key)) {  
         _data.push_back(TPair<Tkey, Tval>(new_key, value));
         _size++;
     }
     return new_key;
 }

template <class Tkey, class Tval>
void UnsortedTable<Tkey, Tval>::insert(Tkey key, Tval value) {
    if (!search(key)) { 
        _data.push_back(TPair<Tkey, Tval>(key, value));
        _size++;
    }
}
template <class Tkey, class Tval>
void UnsortedTable<Tkey, Tval>::erase(Tkey key) {
    for (auto i = _data.begin(); i != _data.end(); i++) {
        if ((*i).first() == key) {
            _data.erase(i.get_node());
            break;
        }
    }
    _size--;
}

template <class Tkey, class Tval>
Tval UnsortedTable<Tkey, Tval>::find(Tkey key) const {
    for (auto i = _data.begin(); i != _data.end(); ++i) {
        if ((*i).first() == key) {
            return (*i).second();
        }
    }
    throw std::logic_error("Element not found");
}

template <class Tkey, class Tval>
bool UnsortedTable<Tkey, Tval>::search(Tkey key) {
    for (auto i = _data.begin(); i != _data.end(); i++) {
        if ((*i).first() == key) {
            return true;
        }
    }
    return false;
}

template<class Tkey, class Tval>
const Tval& UnsortedTable<Tkey, Tval>::operator[](const Tkey key) const {
    return this->find(key);
}

template<class Tkey, class Tval>
Tval& UnsortedTable<Tkey, Tval>::operator[](const Tkey key) {
    return this->find(key);
}