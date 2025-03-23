#include "exception"
#include "iostream"
#include "string"
#include "BTreeNode.h"
#pragma once

template <class T>
class BTree {
    BTreeNode<T>* _head;
    size_t _size;
public:
    BTree();
    BTreeNode<T>* copy(BTreeNode<T>* node) noexcept;
    BTree(const BTree<T>& tree);
    BTree<T>& operator=(const BTree<T>& tree);
    BTreeNode<T>* insert(T val);
    BTreeNode<T>* search(T val) const noexcept;
    BTreeNode<T>* search_prev(T& val) const noexcept;
    BTreeNode<T>* min(BTreeNode<T>* node);
    void erase(T val) noexcept;
    ~BTree();
    void clear(BTreeNode<T>* node) noexcept;
    BTreeNode<T>* head();
    size_t size() const noexcept;
    void print(BTreeNode<T>* node, int indent = 0) const;
    void print() const;
};

template<class T>
BTree<T>::BTree() {
    _head = nullptr;
    _size = 0;
}

template<class T>
BTreeNode<T>* BTree<T>::copy(BTreeNode<T>* node) noexcept {
    if (node == nullptr)
        return nullptr;
    BTreeNode<T>* new_node = new BTreeNode<T>(node->value());
    new_node->left(copy(node->left()));
    new_node->right(copy(node->right()));
    return new_node;
}

template<class T>
BTree<T>::BTree(const BTree<T>& tree) {
    _head = copy(tree._head);
    _size = tree._size;
}

template<class T>
BTree<T>& BTree<T>::operator=(const BTree<T>& tree) {
    if (&tree != this) {
        clear(_head);
        _head = copy(tree._head);
        _size = tree._size;
    }
    return *this;
}

template<class T>
BTreeNode<T>* BTree<T>::insert(T val) {
    BTreeNode<T>* node = new BTreeNode<T>(val);
    if (_head == nullptr)
        _head = node;
    else {
        BTreeNode<T>* cur = _head;
        while (true) {
            if (val > cur->value()) {
                if (cur->right() == nullptr) {
                    cur->right(node);
                    break;
                }
                else
                    cur = cur->right();
            }
            else if (val < cur->value()) {
                if (cur->left() == nullptr) {
                    cur->left(node);
                    break;
                }
                else
                    cur = cur->left();
            }
            else {
                throw std::logic_error("A node with this value is already in the tree.");
            }
        }
    }
    _size++;
    return node;
}

template <class T>
BTreeNode<T>* BTree<T>::search(T val) const noexcept {
    BTreeNode<T>* cur = _head;
    while (cur != nullptr) {
        if (val > cur->value())
            cur = cur->right();
        else if (val < cur->value())
            cur = cur->left();
        else
            return cur;
    }
    return nullptr;
}

template <class T>
BTreeNode<T>* BTree<T>::search_prev(T& val) const noexcept {
    if (_head == nullptr || _head->value() == val) return nullptr;

    BTreeNode<T>* cur = _head;
    BTreeNode<T>* prev = nullptr;
    while (cur != nullptr && cur->value() != val) {
        prev = cur;
        cur = (val > cur->value()) ? cur->right() : cur->left();
    }
    return prev;
}
template <class T>
BTreeNode<T>* BTree<T>::min(BTreeNode<T>* node) {
    BTreeNode<T>* cur = node->right();
    BTreeNode<T>* next = node->right();
    while (next->left() != nullptr) {
        cur = next;
        next = next->left();
    }
    cur->left(next->right());
    return next;
}

template <class T>
void BTree<T>::erase(T val) noexcept {
    BTreeNode<T>* del = this->search(val);
    BTreeNode<T>* prev = this->search_prev(val);
    if (del->left() == nullptr && del->right() == nullptr) {
        if (prev->left() == del)
            prev->left(nullptr);
        else
            prev->right(nullptr);
        delete del;
    }
    else if (del->left() != nullptr && del->right() != nullptr) {
        BTreeNode<T>* rep = this->min(del);
        if (rep != del->right())
            rep->right(del->right());
        rep->left(del->left());
        if (prev->left() == del)
            prev->left(rep);
        else
            prev->right(rep);
        delete del;
    }
    else {
        BTreeNode<T>* child = del->left() != nullptr ? del->left() : del->right();
        if (prev->left() == del)
            prev->left(child);
        else
            prev->right(child);
        delete del;
    }
    _size--;
}

template <class T>
BTree<T>::~BTree() {
    clear(_head);
}
template <class T>
void BTree<T>::clear(BTreeNode<T>* node) noexcept {
    if (node != nullptr) {
        clear(node->left());
        clear(node->right());
        delete node;
    }
    _head = nullptr;
    _size = 0;
}

template <class T>
BTreeNode<T>* BTree<T>::head() {
    return _head;
}

template <class T>
size_t BTree<T>::size() const noexcept {
    return _size;
}

template <class T>
void BTree<T>::print(BTreeNode<T>* node, int indent) const {
    if (node != nullptr) {
        if (node->right()) {
            print(node->right(), indent + 20);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << node->value() << "\n";
        if (node->left()) {
            print(node->left(), indent + 20);
        }
    }
}

template <class T>
void BTree<T>::print() const {
    if (_head == nullptr) {
        std::cout << "Tree is empty.\n";
    }
    else {
        print(_head, 0);
    }
}