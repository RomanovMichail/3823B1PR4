#pragma once
#include "../lib_itable/itable.h"
#include "../lib_pair/pair.h"
#include "../lib_dmassive/dmassive.h"
#include <stdexcept>
template <class Tkey>
void generate_key(Tkey& key, int val, size_t size) {
    key = val + size;
}

template <class Tkey>
void generate_key(Tkey& key, std::string val, size_t size) {
    key = val + char(size);
}
template <class Tkey, class Tval>
class Unsorted_Table : public ITable<Tkey, Tval> {
    TDMassive<TPair<Tkey, Tval>> _data;
public:
    Unsorted_Table() = default;

    Tkey insert(Tval value) override;
    void insert(Tkey key, Tval value) override;
    void erase(Tkey key) override;
    Tval find(Tkey key) const override;
    bool search(Tkey key);

    const Tval& operator[](const Tkey key) const override;
    Tval& operator[](const Tkey key) override;
};

template <class Tkey, class Tval>
Tkey Unsorted_Table<Tkey, Tval>::insert(Tval value) {
    Tkey new_key;
    generate_key(new_key, value, _data.size());
    _data.push_back(TPair<Tkey, Tval>(new_key, value));
    return new_key;
}

template <class Tkey, class Tval>
void Unsorted_Table<Tkey, Tval>::insert(Tkey key, Tval value) {
    if (search(key))
        throw std::logic_error("such a key is already in the table.");
    _data.push_back(TPair<Tkey, Tval>(key, value));
}

template <class Tkey, class Tval>
void Unsorted_Table<Tkey, Tval>::erase(Tkey key) {
    for (size_t i = 0; i < _data.size(); ++i) {
        if (_data.data()[i].first() == key) {
            _data.remove_by_index(i);
            return;
        }
    }
    throw std::logic_error("element not found");
}

template <class Tkey, class Tval>
Tval Unsorted_Table<Tkey, Tval>::find(Tkey key) const {
    size_t index = _data.find_first(TPair<Tkey, Tval>(key, Tval()));
    if (index != static_cast<size_t>(-1)) {
        return _data.data()[index].second();
    }
    throw std::logic_error("element not found");
}

template <class Tkey, class Tval>
bool Unsorted_Table<Tkey, Tval>::search(Tkey key) {
    for (size_t i = 0; i < _data.size(); ++i) {
        if (_data.data()[i].first() == key) {
            return true;
        }
    }
    return false;
}

template <class Tkey, class Tval>
const Tval& Unsorted_Table<Tkey, Tval>::operator[](const Tkey key) const {
    return find(key);
}

template <class Tkey, class Tval>
Tval& Unsorted_Table<Tkey, Tval>::operator[](const Tkey key) {
    for (size_t i = 0; i < _data.size(); ++i) {
        if (_data.data()[i].first() == key) {
            return _data.data()[i].second();
        }
    }
    throw std::logic_error("element not found");
}
