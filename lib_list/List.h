#pragma once
#include "node.h"

template <class T>
class Tlist {
    TNode<T>* _head;
    TNode<T>* _tail;
public:
    TList();
    TList(const TList<T>& list);
    ~TList();
    void push_front(const T& value) noexcept;
    void push_back(const T& value) noexcept;
    void insert(const TNode<T>* node, T value);
    void insert(size_t pos);
    TNode<T>* find(const T& value) const noexcept;
    void pop_front();
    void pop_back();
    erase(TNode <T>* node);
    erase(size_t pos);
    bool isEmpty();
    void replace(TNode<T>* node);
    void raplace(size_t pos);
    //=
    friend void qsort(TList <T> list) noexcept;
};
template <class T>
Tlist<T>::TList() : _head(nullptr), _tail(nullptr) {
_

}

template <class T>
Tl ist<T>::TList(const TList<T>& list) : _head(nullptr), _tail(nullptr) {
    TNode<T>* current = list._head;
    while (current != nullptr) {
        push_back(current->value());
        current = current->next();
    }
}


template <class T>
Tlist<T>::~TList() {
    while (!isEmpty()) {
        pop_front();
    }
}
template <class T>
void Tlist<T>::insert(const TNode<T>* node, T value) {
    if (node == nullptr) {
        throw;
    }
    TNode<T>* new_node = new TNode<T>(value, node->next());
    node->next(new_node);
    if (node == _tail) {
        _tail = new_node;
    }
}

template <class T>
void push_front(const T& value);
