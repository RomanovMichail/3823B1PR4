#include <string>
#include <iostream>  
#include <stdexcept>
#pragma once
template <class T>
class TStack {
public:
    TStack(size_t size); 
    ~TStack();
    bool isEmpty() const noexcept;
    bool isFull() const noexcept;
    void push(T val);
    void pop();

    size_t top() const;
    T* _data;
    size_t _size;
    int _top;




};


template <class T>
TStack<T>::TStack(size_t size) {
    _data = new T[size];
    _size = size;
    _top = -1;
}

template <class T>
TStack<T>::~TStack() {
    delete[] _data;
}

template <class T>
bool TStack<T>::isEmpty() const noexcept {
    return _top == -1;
}

template <class T>
bool TStack<T>::isFull() const noexcept {
    return _top == _size - 1;
}

template <class T>
void TStack<T>::push(T val) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    _top += 1;
    _data[_top] = val;
}

template <class T>
void TStack<T>::pop() {
    if (isEmpty()) {

        throw std::logic_error("Stack is empty");


    }
    _top--;
}

template <class T>

inline size_t TStack<T>::top() const {
    return _data[_top];
}


