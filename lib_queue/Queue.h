#include <string>
#include <iostream>  
#include <stdexcept>
#pragma once


template<class T>
class TQueue {
public:
    TQueue(size_t size);
    ~TQueue();
    bool isEmpty() const noexcept;
    void push(T val);
    size_t top() const;
    void pop();
private:
    T* _data;        
    size_t _size;    
    size_t _front;   
    size_t _back;    
    size_t _count;   
};

template<class T>
TQueue<T>::TQueue(size_t size) : _size(size), _front(-1), _back(-1), _count(0) {
    _data = new T[size];
}


template<class T>
TQueue<T>::~TQueue() {
    delete[] _data;
}


template<class T>
bool TQueue<T>::isEmpty() const noexcept {
    return _count == 0;
}


template<class T>
void TQueue<T>::push(T val) {
    if (_count == _size) {
        throw std::overflow_error("Queue overflow");
    }
    if (isEmpty()) {
        _front = 0;
    }
    _back = (_back + 1) % _size;
    
    _data[_back] = val;
    ++_count;
    
}

template<class T>
size_t TQueue<T>::top() const {
    if (isEmpty()) {
        throw std::logic_error("Queue is empty");
    }
    return _data[_front];
}

template<class T>
void TQueue<T>::pop() {
    if (isEmpty()) {
        throw std::logic_error("Queue is empty");
    }
    _front = (_front + 1)% _size;
    --_count;
}