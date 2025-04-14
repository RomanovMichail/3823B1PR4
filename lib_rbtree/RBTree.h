#pragma once
#include"RBTreeNode.h"
#include"../lib_tbinsearchtree/tbinsearchtree.h"
#include <iostream>
#include <iomanip>
#include <exception>

template <class T>
class RBTree {
    RBTreeNode<T>* _root;
    size_t _size;

    void rotateLeft(RBTreeNode<T>* x);
    void rotateRight(RBTreeNode<T>* y);
    void fixInsertion(RBTreeNode<T>* z);

public:
    RBTree() : _root(nullptr), _size(0) {}
    RBTreeNode<T>* insert(T val);
    RBTreeNode<T>* search(T val) const noexcept;
    void print() const;
    size_t size() const noexcept { return _size; }

private:
    void print(RBTreeNode<T>* node, int indent = 0) const;

    const char* _red_color = "\033[31m";
    const char* _black_color = "\033[37m"; 
    const char* _reset_color = "\033[0m";
};

template <class T>
RBTreeNode<T>* RBTree<T>::insert(T val) {
    RBTreeNode<T>* parent = nullptr;
    RBTreeNode<T>* current = _root;

    while (current != nullptr) {
        parent = current;
        if (val < current->value())
            current = current->left();
        else if (val > current->value())
            current = current->right();
        else
            throw std::logic_error("Duplicate value");
    }

    RBTreeNode<T>* newNode = new RBTreeNode<T>(val, parent);

    if (parent == nullptr) {
        _root = newNode; 
    }
    else if (val < parent->value()) {
        parent->left(newNode);
    }
    else {
        parent->right(newNode);
    }

    fixInsertion(newNode);
    _size++;
    return newNode;
}

template <class T>
void RBTree<T>::fixInsertion(RBTreeNode<T>* z) {
    while (z->parent() != nullptr && z->parent()->color()) {
        RBTreeNode<T>* grandparent = z->parent()->parent();
        if (grandparent == nullptr) break;

        bool parentIsLeft = (z->parent() == grandparent->left());
        RBTreeNode<T>* uncle = parentIsLeft ? grandparent->right() : grandparent->left();

        if (uncle != nullptr && uncle->color()) {
            z->parent()->color(false);
            uncle->color(false);
            grandparent->color(true);
            z = grandparent;
        }
        else {
            if (parentIsLeft != (z == (parentIsLeft ? z->parent()->left() : z->parent()->right()))) {
                if (parentIsLeft)
                    rotateRight(z->parent());
                else
                    rotateLeft(z->parent());
                    z = parentIsLeft ? z->right() : z->left();
            }

            z->parent()->color(false);
                grandparent->color(true);
                if (parentIsLeft)
                    rotateRight(grandparent);
                else
                    rotateLeft(grandparent);
        }
    }
    _root->color(false); 
}

template <class T>
void RBTree<T>::rotateLeft(RBTreeNode<T>* x) {
    RBTreeNode<T>* y = x->right();
    x->right(y->left());

    if (y->left() != nullptr)
        y->left()->parent(x);

    y->parent(x->parent());

    if (x->parent() == nullptr)
        _root = y;
    else if (x == x->parent()->left())
        x->parent()->left(y);
    else
        x->parent()->right(y);

    y->left(x);
    x->parent(y);
}

template <class T>
void RBTree<T>::rotateRight(RBTreeNode<T>* y) {
    RBTreeNode<T>* x = y->left();
    y->left(x->right());

    if (x->right() != nullptr)
        x->right()->parent(y);

    x->parent(y->parent());

    if (y->parent() == nullptr)
        _root = x;
    else if (y == y->parent()->right())
        y->parent()->right(x);
    else
        y->parent()->left(x);

    x->right(y);
    y->parent(x);
}

template <class T>
RBTreeNode<T>* RBTree<T>::search(T val) const noexcept {
    RBTreeNode<T>* current = _root;
    while (current != nullptr) {
        if (val < current->value())
            current = current->left();
        else if (val > current->value())
            current = current->right();
        else
            return current;
    }
    return nullptr;
}

template <class T>
void RBTree<T>::print() const {
    if (_root == nullptr) {
        std::cout << "Tree is empty.\n";
    }
    else {
        print(_root, 0);
    }
}

template <class T>
void RBTree<T>::print(RBTreeNode<T>* node, int indent) const {
    if (node != nullptr) {
        if (node->right()) {
            print(node->right(), indent + 8);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << (node->color() ? _red_color : _black_color)
            << node->value()
            << _reset_color << "\n";
        if (node->left()) {
            print(node->left(), indent + 8);
        }
    }
}