<<<<<<< HEAD
#include <string>
=======

>>>>>>> c85c33f3385ee486d4548e0015fdc7fba9ae565f
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
<<<<<<< HEAD
    size_t top() const;
    T* _data;
    size_t _size;
    int _top;


   
    

private:
  
=======


private:
    T* _data;
    size_t _size;
    int _top;
>>>>>>> c85c33f3385ee486d4548e0015fdc7fba9ae565f
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
<<<<<<< HEAD
        throw std::logic_error("Stack is empty");
=======
        throw std::underflow_error("Stack is empty");
>>>>>>> c85c33f3385ee486d4548e0015fdc7fba9ae565f
    }
    _top--;
}

<<<<<<< HEAD
template <class T>

inline size_t TStack<T>::top() const {
    return _data[_top];
}


=======
>>>>>>> c85c33f3385ee486d4548e0015fdc7fba9ae565f
