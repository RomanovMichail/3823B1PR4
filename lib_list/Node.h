#pragma once
#include "iostream"

template <class T>
class TNode {
    T _value;
    TNode <T>* _pnext;
public:
    TNode(T value, TNode <T>* node = nullptr);
    TNode(const TNode<T>& node);
    TNode<T>& operator = (const TNode <T>& node);
    TNode <T>* next();
    void next(const TNode<T>* node);
    bool operator == (const TNode <T> node) const noexcept;
    bool operator == (const T* node) const noexcept;
    T value();
};

template <class T>
TNode<T>::TNode(T value, TNode <T>* node) {
    _value = value;
    _pnext = node;
}

template <class T>
T TNode<T>::value() {
    return _value;
}

template <class T>
TNode<T>::TNode(const TNode<T>& node) {
    _value = node._value;
    _pnext = node._pnext;
}

template <class T>
TNode <T>* TNode<T>::next() {
    return _pnext;
}

template <class T>
void TNode<T>::next(const TNode<T>* node) {
    _pnext = node;
}

template<class T>
bool TNode<T>::operator == (const TNode <T> node) const noexcept {
    return _value == node._value;
}

template<class T>
bool TNode<T>::operator == (const T* value) const noexcept {
    return _value == value;
}
template<class T>
TNode<T>& TNode<T>:: operator= (const TNode <T>& node) {
    if (this == &node);
    return this;

    _value = node._value;
    _pnext = node.pnext;

    return *this;
}