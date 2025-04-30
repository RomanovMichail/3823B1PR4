#pragma once
#include"iostream"
#include"../lib_list/List.h"
#include"../lib_pair/pair.h"
#include"string.h"
#include"../lib_itable/Itable.h"

template <class Tkey, class Tval>
class Unsorted_Table : public ITable<Tkey, Tval> {
    TList<TPair<Tkey, Tval>> _data;
    size_t _size;

public:
    Unsorted_Table() : _size(0) {}

    Unsorted_Table(const TList<TPair<Tkey, Tval>>& list) : _data(list), _size(list.get_size()) {}

    Unsorted_Table(const Unsorted_Table<Tkey, Tval>& table) : _data(table._data), _size(table._size) {}

    Unsorted_Table& operator=(const Unsorted_Table<Tkey, Tval>& table) {
        if (this != &table) {
            _data = table._data;
            _size = table._size;
        }
        return *this;
    }

    size_t size() const noexcept { return _size; }
    bool empty() const noexcept { return _size == 0; }

    Tkey insert(Tval value) override {
        Tkey key = static_cast<Tkey>(_size);
        _data.push_back(TPair<Tkey, Tval>(key, value));
        _size++;
        return key;
    }

    void insert(Tkey key, Tval value) override {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if ((*it).first() == key) {
                TPair<Tkey, Tval> new_pair(key, value);
                _data.replace(it.get_node(), new_pair);
                return;
            }
        }
        _data.push_back(TPair<Tkey, Tval>(key, value));
        _size++;
    }

    void erase(Tkey key) override {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if ((*it).first() == key) {
                _data.erase(it.get_node());
                _size--;
                return;
            }
        }
    }

    Tval find(Tkey key) const override {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if ((*it).first() == key) {
                return (*it).second();
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool search(Tkey key) const {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if ((*it).first() == key) {
                return true;
            }
        }
        return false;
    }

    const Tval& operator[](const Tkey key) const override {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if ((*it).first() == key) {
                return (*it).second();
            }
        }
        throw std::out_of_range("Key not found");
    }

    Tval& operator[](const Tkey key) override {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if ((*it).first() == key) {
                return (*it).second();
            }
        }
        _data.push_back(TPair<Tkey, Tval>(key, Tval()));
        _size++;

        auto it = _data.begin();
        if (it == _data.end()) throw std::runtime_error("Unexpected empty list after insert");

        auto last = it;
        for (; it != _data.end(); ++it) {
            last = it;
        }
        return (*last).second();
    }
};