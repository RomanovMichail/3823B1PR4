#include "node.h"
#pragma once
#include "iostream"
template <class T>
class TList {
  

public:
    TList();
    TList(const TList<T>& list);
    ~TList();

    void push_front(const T& value) noexcept;
    void push_back(const T& value) noexcept;
    void insert(const TNode<T>* node, T value);
    void insert(size_t pos, const T& value);
    TNode<T>* find(const T& value) const noexcept;
    int get_size() const noexcept;
    void pop_front();
    void pop_back();
    void erase(TNode<T>* node);
    void erase(size_t pos);

    bool isEmpty() const noexcept;

    void replace(TNode<T>* node, const T& value);
    void replace(size_t pos, const T& value);


    TNode<T>* _head;
    TNode<T>* _tail;


};
template <class T>
TList<T>::TList() : _head(nullptr), _tail(nullptr) {}
template <class T>
TList<T>::TList(const TList<T>& list) : _head(nullptr), _tail(nullptr) {
    TNode<T>* current = list._head;
    while (current != nullptr) {
        push_back(current->value());
        current = current->next();
    }
}
template <class T>
TList<T>::~TList() {
    while (!isEmpty()) {
        pop_front();
    }
}
template <class T>
bool TList<T>::isEmpty() const noexcept {
    return _head == nullptr;
}

template <class T>
void TList<T>::push_front(const T& value) noexcept {
    TNode<T>* new_node = new TNode<T>(value, _head);
    _head = new_node;
    if (_tail == nullptr) {
        _tail = new_node;
    }
}
template <class T>
void TList<T>::push_back(const T& value) noexcept {
    TNode<T>* new_node = new TNode<T>(value, nullptr);
    if (_tail != nullptr) {
        _tail->next(new_node);
    }
    _tail = new_node;
    if (_head == nullptr) {
        _head = new_node;
    }
}
template <class T>
TNode<T>* TList<T>::find(const T& value) const noexcept {
    TNode<T>* cur = _head;
    while (cur != nullptr) {
        if (cur->value() == value) {
            return cur;
        }
        cur = cur->next();
    }
    return nullptr;
}
template <class T>
int TList<T>::get_size() const noexcept {
    int size = 0;
    TNode<T>* current = _head;
    while (current != nullptr) {
        ++size;
        current = current->next();
    }
    return size;
}
template <class T>
void TList<T>::insert(const TNode<T>* node, T value) {
    if (node == nullptr) {
        throw std::logic_error("Invalid node");
    }
    TNode<T>* new_node = new TNode<T>(value, node->next());
    const_cast<TNode<T>*>(node)->next(new_node);
    if (node == _tail) {
        _tail = new_node;
    }
}
template <class T>
void TList<T>::insert(size_t pos, const T& value) {
    if (pos == 0) {
        push_front(value);
        return;
    }
    TNode<T>* current = _head;
    size_t index = 0;
    while (current != nullptr && index < pos - 1) {
        current = current->next();
        ++index;
    }
    if (current == nullptr) {
        throw std::out_of_range("Position out of bounds");
    }

    insert(current, value);
}
template <class T>
void TList<T>::pop_front() {
    if (isEmpty()) {
        throw std::logic_error("List is empty");
    }

    TNode<T>* temp = _head;
    _head = _head->next();
    if (_head == nullptr) {
        _tail = nullptr;
    }
    delete temp;
}
template <class T>
void TList<T>::pop_back() {
    if (isEmpty()) {
        throw std::logic_error("List is empty");
    }

    if (_head == _tail) {
        delete _head;
        _head = _tail = nullptr;
    }
    else {
        TNode<T>* current = _head;
        while (current->next() != _tail) {
            current = current->next();
        }
        delete _tail;
        _tail = current;
        _tail->next(nullptr);
    }
}
template <class T>
void TList<T>::erase(TNode<T>* node) {
    if (node == nullptr || isEmpty()) {
        throw std::logic_error("Invalid node or list is empty");
    }

    if (node == _head) {
        pop_front();
        return;
    }

    TNode<T>* current = _head;
    while (current->next() != node) {
        current = current->next();
    }

    if (current->next() == node) {
        current->next(node->next());
        if (node == _tail) {
            _tail = current;
        }
        delete node;
    }
}
template <class T>
void TList<T>::erase(size_t pos) {
    if (pos == 0) {
        pop_front();
        return;
    }

    TNode<T>* current = _head;
    size_t index = 0;
    while (current != nullptr && index < pos - 1) {
        current = current->next();
        ++index;
    }

    if (current == nullptr || current->next() == nullptr) {
        throw std::out_of_range("Position out of bounds");
    }

    TNode<T>* node_to_erase = current->next();
    current->next(node_to_erase->next());

    if (node_to_erase == _tail) {
        _tail = current;
    }

    delete node_to_erase;
}
template <class T>
void TList<T>::replace(TNode<T>* node, const T& value) {
    if (node == nullptr) {
        throw std::logic_error("Invalid node");
    }
    node->value(value);
}
template <class T>
void TList<T>::replace(size_t pos, const T& value) {
    if (pos<0 || pos>get_size() - 1) {
        throw std::logic_error("Invalid node");
    }
    TNode<T>* node = find(pos);
    node->value(value);
}