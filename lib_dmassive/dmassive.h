#pragma once
#define STEP_CAPACITY 15
#include <cmath>
#include <stdexcept>
enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
}

template <typename T>
class TDMassive {
    T* _data;                  
    State* _states;           
    size_t _capacity;          
    size_t _size;             
    size_t _deleted;          
public:
    TDMassive();
    TDMassive(const TDMassive& archive);
    TDMassive(const T* arr, size_t n);
    TDMassive(size_t n, T value);
    TDMassive(const TDMassive& archive, size_t pos, size_t n);
    ~TDMassive();

    void print() const noexcept;
    inline bool empty() const noexcept;
    inline bool full() const noexcept;
    size_t size() const;
    size_t capacity();
    const T* data() const;
    void swap(TDMassive& archive);
    TDMassive& assign(const TDMassive& archive);
    void clear();
    void resize(size_t n, T value);
    void reserve(size_t n, size_t start_index = 0);
    void push_back(T value);             
    void pop_back();                  
    void push_front(T value);           
    void pop_front();   
    TDMassive& insert(const T* arr, size_t n, size_t pos);
    TDMassive& insert(T value, size_t pos);
    TDMassive& replace(size_t pos, T new_value);
    TDMassive& erase(size_t pos, size_t n);
    TDMassive& remove_all(T value);
    TDMassive& remove_first(T value);
    TDMassive& remove_last(T value);
    TDMassive& remove_by_index(size_t pos);
    size_t* find_all(T value) const noexcept;
    size_t find_first(T value);
    size_t find_last(T value);
private:
    size_t count_value(T value);
};

template <typename T>
TDMassive<T>::TDMassive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}
template <typename T>
TDMassive<T>::TDMassive(const TDMassive& archive)
    : _capacity(archive._capacity), _size(archive._size), _deleted(archive._deleted) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    std::copy(archive._data, archive._data + _size, _data);
    std::copy(archive._states, archive._states + _size, _states);
}


template <typename T>
TDMassive<T>::TDMassive(const T* arr, size_t n) : _capacity(n), _size(n), _deleted(0) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < n; i++) {
        _data[i] = arr[i];
        _states[i] = State::busy;
    }
    std::cout << "{ ";
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i];
            if (i < _size - 1) std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}


template <typename T>
TDMassive<T>::TDMassive(size_t n, T value) : _capacity(n), _size(n), _deleted(0) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < n; i++) {
        _data[i] = value;
        _states[i] = State::busy;
    }
}

template <typename T>
TDMassive<T>::TDMassive(const TDMassive& archive, size_t pos, size_t n)
    : _capacity(n), _size(n), _deleted(0) {
    if (pos + n > archive._size) {
        throw std::out_of_range("Position and size out of range");
    }
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < n; i++) {
        _data[i] = archive._data[pos + i];
        _states[i] = archive._states[pos + i];
    }
}

template <typename T>
TDMassive<T>::~TDMassive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TDMassive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TDMassive<T>::full() const noexcept {
    return _size == _capacity;
}
template <typename T>
size_t TDMassive<T>::size() const {
    return _size;
}

template <typename T>
size_t TDMassive<T>::capacity() {
    return _capacity;
}


template <typename T>
const T* TDMassive<T>::data() const{
    return _data;
}



template <typename T>
void TDMassive<T>::swap(TDMassive& archive) {
    std::swap(_data, archive._data);
    std::swap(_states, archive._states);
    std::swap(_capacity, archive._capacity);
    std::swap(_size, archive._size);
    std::swap(_deleted, archive._deleted);
}
template <typename T>
TDMassive<T>& TDMassive<T>::assign(const TDMassive& archive) {
    if (this == &archive) return *this;
    delete[] _data;
    delete[] _states;
    _capacity = archive._capacity;
    _size = archive._size;
    _deleted = archive._deleted;
    _data = new T[_capacity];
    _states = new State[_capacity];
    std::copy(archive._data, archive._data + _size, _data);
    std::copy(archive._states, archive._states + _size, _states);
    return *this;
}

template <typename T>
void TDMassive<T>::clear() {
    delete[] _data;
    delete[] _states;
    _data = new T[_capacity];
    _states = new State[_capacity];
    _size = 0;
    _deleted = 0;
}


template <typename T>
void TDMassive<T>::push_back(T value) {
    if (full()) {
        reserve(_capacity + STEP_CAPACITY);
    }
    _data[_size] = value;
    _states[_size] = State::busy;
    _size++;
}


template <typename T>
void TDMassive<T>::pop_back() {
    if (empty()) return;
    _states[--_size] = State::deleted;
}


template <typename T>
void TDMassive<T>::push_front(T value) {
    if (full()) {
        reserve(_capacity + STEP_CAPACITY);
    }
    for (size_t i = _size; i > 0; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }
    _data[0] = value;
    _states[0] = State::busy;
    _size++;
}


template <typename T>
void TDMassive<T>::pop_front() {
    if (empty()) return;
    for (size_t i = 0; i < _size - 1; i++) {
        _data[i] = _data[i + 1];
        _states[i] = _states[i + 1];
    }
    _size--;
    _states[_size] = State::deleted;
}


template <typename T>
TDMassive<T>& TDMassive<T>::insert(const T* arr, size_t n, size_t pos) {
    if (full()) {
        reserve(_capacity + n + STEP_CAPACITY);
    }
    for (size_t i = _size; i > pos; i--) {
        _data[i + n - 1] = _data[i - 1];
        _states[i + n - 1] = _states[i - 1];
    }
    for (size_t i = 0; i < n; i++) {
        _data[pos + i] = arr[i];
        _states[pos + i] = State::busy;
    }
    _size += n;
    return *this;
}

template <typename T>
TDMassive<T>& TDMassive<T>::replace(size_t pos, T new_value) {
    if (pos >= _size) {
        throw std::out_of_range("Position out of range");
    }
    _data[pos] = new_value;
    return *this;
}


template <typename T>
TDMassive<T>& TDMassive<T>::erase(size_t pos, size_t n) {
    if (pos + n > _size) {
        throw std::out_of_range("Position and range out of bounds");
    }
    for (size_t i = pos; i < pos + n; i++) {
        _states[i] = State::deleted;
    }
    return *this;
}


template <typename T>
TDMassive<T>& TDMassive<T>::remove_all(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value && _states[i] == State::busy) {
            _states[i] = State::deleted;
        }
    }
    return *this;
}


template <typename T>
TDMassive<T>& TDMassive<T>::remove_first(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value && _states[i] == State::busy) {
            _states[i] = State::deleted;
            return *this;
        }
    }
    return *this;
}


template <typename T>
TDMassive<T>& TDMassive<T>::remove_last(T value) {
    for (size_t i = _size; i-- > 0;) {
        if (_data[i] == value && _states[i] == State::busy) {
            _states[i] = State::deleted;
            return *this;
        }
    }
    return *this;
}


template <typename T>
TDMassive<T>& TDMassive<T>::remove_by_index(size_t pos) {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    _states[pos] = State::deleted;
    return *this;
}


template <typename T>
size_t TDMassive<T>::find_first(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value && _states[i] == State::busy) {
            return i;
        }
    }
    return -1;
}

template <typename T>
size_t TDMassive<T>::find_last(T value) {
    for (size_t i = _size; i-- > 0;) {
        if (_data[i] == value && _states[i] == State::busy) {
            return i;
        }
    }
    return -1;
}

template <typename T>
TDMassive<T>& TDMassive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \"TDMassive<T>& insert(T value, size_t pos)\": wrong position value.");
    }
    if (this->full()) {
        reserve(_capacity + STEP_CAPACITY);
    }
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
void TDMassive<T>::resize(size_t n, T value) {
    if (n < _size) {
        _size = n;
    }
    else if (n > _capacity) {
        reserve(n);
        for (size_t i = _size; i < n; i++) {
            _data[i] = value;
            _states[i] = State::busy;
        }
        _size = n;
    }
}

template <typename T>
void TDMassive<T>::reserve(size_t n, size_t start_index = 0) {
    if (n <= _capacity) return;

    T* new_data = new T[n];
    State* new_states = new State[n];

    size_t j = 0;
    for (size_t i = start_index; i < _capacity; i++, j++) {
        new_data[j] = _data[i];
        new_states[j] = _states[i];
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;
    _capacity = n;
    _size = j;  
}


template <typename T>
void TDMassive<T>::print() const noexcept {
    std::cout << "{ ";
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i];
            if (i < _size - 1) std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

template <typename T>
size_t* TDMassive<T>::find_all(T value) const noexcept {
    size_t count = count_value(value);
    if (count == 0) return nullptr;
    size_t* found_positions = new size_t[count + 1];
    found_positions[0] = count;

    size_t index = 1;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy && _data[i] == value) {
            found_positions[index++] = i;
        }
    }
    return found_positions;
}

template <typename T>
size_t TDMassive<T>::count_value(T value) {
    size_t count = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy && _data[i] == value) {
            count++;
        }
    }
    return count;
}