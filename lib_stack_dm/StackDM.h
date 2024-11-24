#pragma once
#include "../lib_dmassive/dmassive.h"
#include <stdexcept>


template <typename T>
class TStackDM {
private:
    TDMassive<T> _array; 
public:
    TStackDM();
    explicit TStackDM(size_t size);
    ~TStackDM();

    bool isEmpty() const noexcept; 
    bool isFull() const noexcept;  
    size_t size() const noexcept;  

    void push(const T& value); 
    void pop();                
    T top() const;             
};

template <typename T>
TStackDM<T>::TStackDM() = default;
template <typename T>
TStackDM<T>::TStackDM(size_t size) : _array(size) {
   
}

template <typename T>
TStackDM<T>::~TStackDM() = default;

template <typename T>
bool TStackDM<T>::isEmpty() const noexcept {
    return _array.empty();
}

template <typename T>
bool TStackDM<T>::isFull() const noexcept {
    return _array.full();
}

template <typename T>
size_t TStackDM<T>::size() const noexcept {
    return _array.size();
}

template <typename T>
void TStackDM<T>::push(const T& value) {
    _array.push_back(value);
}

template <typename T>
void TStackDM<T>::pop() {
    if (isEmpty()) {
        throw std::logic_error("Stack is empty");
    }
    _array.pop_back();
}

template <typename T>
T TStackDM<T>::top() const {
    if (isEmpty()) {
        throw std::logic_error("Stack is empty");
    }
    return _array.data()[_array.size() - 1];
}