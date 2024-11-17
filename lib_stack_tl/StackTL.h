
#include <stdexcept>
#include"..\lib_list\List.h"
#pragma once
template <class T>
class TStackTL {
private:
	TList<T> list;
    size_t _size;
    size_t _maxSize;

public:
    TStackTL();
	TStackTL(size_t maxSize);
	~TStackTL();
	bool isEmpty() const noexcept;
    bool isFull() const noexcept;
	void push(const T& val);
	void pop();
    T top() const;
    size_t size() const noexcept;



};
template <class T>
TStackTL<T>::TStackTL() : _size(0) {};
template <class T>
TStackTL<T>::TStackTL(size_t maxSize) : _size(0), _maxSize(maxSize) {};

template <class T>
TStackTL<T>::~TStackTL() = default;

template <class T>
bool TStackTL<T>::isEmpty() const noexcept {
    return list.isEmpty();
}

template <class T>
bool TStackTL<T>::isFull() const noexcept {
    return _size >= _maxSize;
}

template <class T>
void TStackTL<T>::push(const T& val) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    list.push_front(val);
    _size++;
}

template <class T>
void TStackTL<T>::pop() {
    if (isEmpty()) {
        throw std::logic_error("Stack is empty");
    }
    list.pop_front();
    _size--;
}

template <class T>
T TStackTL<T>::top() const {
    if (isEmpty()) {
        throw std::logic_error("Stack is empty");
    }
    return list._head->value();
}

template <class T>
size_t TStackTL<T>::size() const noexcept {
    return _size;

}


