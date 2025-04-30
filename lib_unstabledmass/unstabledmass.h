#pragma once
#include "../lib_itable/itable.h"
#include "../lib_pair/pair.h"
#include "../lib_dmassive/dmassive.h"
#include <stdexcept>
template <class Tkey, class Tval>
class Unsorted_Table : public ITable<Tkey, Tval> {
    TDMassive<TPair<Tkey, Tval>> _data;

    void generate_key(Tkey& key, const Tval& val, size_t size) {
        if constexpr (std::is_arithmetic_v<Tkey>) {
            key = static_cast<Tkey>(size);
        }
        else {
            key = Tkey(std::to_string(size));
        }
    }

public:
    Unsorted_Table() = default;

    Tkey insert(Tval value) override {
        Tkey new_key;
        generate_key(new_key, value, _data.size());
        _data.push_back(TPair<Tkey, Tval>(new_key, value));
        return new_key;
    }

    void insert(Tkey key, Tval value) override {
        if (search(key))
            throw std::logic_error("Key already exists");
        _data.push_back(TPair<Tkey, Tval>(key, value));
    }

    void erase(Tkey key) override {
        for (size_t i = 0; i < _data.size(); ++i) {
            if (_data[i].first() == key) {
                _data.remove_by_index(i);
                return; 
            }
        }
        throw std::logic_error("Key not found");
    }

    Tval find(Tkey key) const override {
        for (size_t i = 0; i < _data.size(); ++i) {
            if (_data[i].first() == key) {
                return _data[i].second();
            }
        }
        throw std::logic_error("Key not found");
    }
    bool search(const Tkey& key) const {  
        for (size_t i = 0; i < _data.size(); ++i) {
            if (_data[i].first() == key) return true;
        }
        return false;
    }

    const Tval& operator[](const Tkey key) const override {
        return find(key);
    }

    Tval& operator[](const Tkey key) override {
        for (size_t i = 0; i < _data.size(); ++i) {
            if (_data[i].first() == key) {
                return _data[i].second();
            }
        }
        throw std::logic_error("Key not found");
    }
};