
#pragma once
#include"../lib_tbinsearchtree/BTreeNode.h"

template <class T>
class RBTreeNode {
    T _value;
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;
    bool _color; 

public:
    RBTreeNode(T value,
        RBTreeNode<T>* parent = nullptr,
        RBTreeNode<T>* left = nullptr,
        RBTreeNode<T>* right = nullptr,
        bool color = true); 

    const T& value() const noexcept;
    bool color() const noexcept;
    RBTreeNode<T>* left() const noexcept;
    RBTreeNode<T>* right() const noexcept;
    RBTreeNode<T>* parent() const noexcept;

    void left(RBTreeNode<T>* node);
    void right(RBTreeNode<T>* node);
    void parent(RBTreeNode<T>* node);
    void color(bool c) noexcept;
};

template<class T>
RBTreeNode<T>::RBTreeNode(T value,
    RBTreeNode<T>* parent,
    RBTreeNode<T>* left,
    RBTreeNode<T>* right,
    bool color)
    : _value(value), _parent(parent), _left(left), _right(right), _color(color) {
}

template<class T>
const T& RBTreeNode<T>::value() const noexcept {
    return _value;
}

template<class T>
bool RBTreeNode<T>::color() const noexcept {
    return _color;
}

template<class T>
RBTreeNode<T>* RBTreeNode<T>::left() const noexcept {
    return _left;
}

template<class T>
RBTreeNode<T>* RBTreeNode<T>::right() const noexcept {
    return _right;
}

template<class T>
RBTreeNode<T>* RBTreeNode<T>::parent() const noexcept {
    return _parent;
}

template<class T>
void RBTreeNode<T>::left(RBTreeNode<T>* node) {
    _left = node;
}

template<class T>
void RBTreeNode<T>::right(RBTreeNode<T>* node) {
    _right = node;
}

template<class T>
void RBTreeNode<T>::parent(RBTreeNode<T>* node) {
    _parent = node;
}

template<class T>
void RBTreeNode<T>::color(bool c) noexcept {
    _color = c;
}