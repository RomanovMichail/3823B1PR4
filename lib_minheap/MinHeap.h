#pragma once
#include <stdexcept>
#include <iostream>

template <class TVal>
class MinHeap {
    TVal* _data;
    size_t _capacity, _size;
public:
    MinHeap(size_t size = 10);
    MinHeap(size_t, const TVal*);
    ~MinHeap();

    inline size_t left(size_t) const;
    inline size_t right(size_t) const;
    inline size_t parent(size_t) const;
    inline bool is_empty() const noexcept;
    void insert(TVal) noexcept;
    void emplace(size_t, TVal);
    inline TVal min() const;
    TVal remove_min();

private:
    void min_heapify() noexcept;
    void sift_down(size_t) noexcept;
    void sift_up(size_t) noexcept;
};


template <class TVal>
MinHeap<TVal>::MinHeap(size_t size) : _capacity(size), _size(0) {
    _data = new TVal[_capacity];
}

template <class TVal>
MinHeap<TVal>::MinHeap(size_t size, const TVal* arr) : _capacity(size), _size(size) {
    _data = new TVal[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = arr[i];
    }
    min_heapify();
}

template <class TVal>
MinHeap<TVal>::~MinHeap() {
    delete[] _data;
}

template <class TVal>
size_t MinHeap<TVal>::left(size_t i) const { return 2 * i + 1; }

template <class TVal>
size_t MinHeap<TVal>::right(size_t i) const { return 2 * i + 2; }

template <class TVal>
size_t MinHeap<TVal>::parent(size_t i) const { return (i - 1) / 2; }

template <class TVal>
bool MinHeap<TVal>::is_empty() const noexcept {
    return _size == 0;
}

template <class TVal>
void MinHeap<TVal>::insert(TVal value) noexcept {
    _data[_size] = value;
    sift_up(_size);
    _size++;
}


template <class TVal>
TVal MinHeap<TVal>::min() const {
    if (_size == 0) {
        throw std::underflow_error("Heap is empty");
    }
    return _data[0];
}

template <class TVal>
TVal MinHeap<TVal>::remove_min() {
    if (_size == 0) {
        throw std::underflow_error("Heap is empty");
    }
    TVal min_val = _data[0];
    _data[0] = _data[_size - 1];
    _size--;
    sift_down(0);
    return min_val;
}

template <class TVal>
void MinHeap<TVal>::sift_up(size_t index) noexcept {
    while (index > 0 && _data[parent(index)] > _data[index]) {
        std::swap(_data[parent(index)], _data[index]);
        index = parent(index);
    }
}

template <class TVal>
void MinHeap<TVal>::sift_down(size_t index) noexcept {
    size_t smallest = index;
    size_t l = left(index);
    size_t r = right(index);

    if (l < _size && _data[l] < _data[smallest]) {
        smallest = l;
    }
    if (r < _size && _data[r] < _data[smallest]) {
        smallest = r;
    }
    if (smallest != index) {
        std::swap(_data[index], _data[smallest]);
        sift_down(smallest);
    }
}


template <class TVal>
void MinHeap<TVal>::min_heapify() noexcept {
    for (int i = _size / 2 - 1; i >= 0; i--) {
        sift_down(i);
    }
}

template <class TVal>
void MinHeap<TVal>::emplace(size_t index, TVal value) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    _data[index] = value;
    sift_up(index);
    sift_down(index);
}
