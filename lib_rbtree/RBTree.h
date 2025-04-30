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
    void transplant(RBTreeNode<T>* u, RBTreeNode<T>* v);
    void fixAfterErase(RBTreeNode<T>* x);
    RBTreeNode<T>* minimum(RBTreeNode<T>* node);
public:
    RBTree() : _root(nullptr), _size(0) {}
    RBTreeNode<T>* insert(T val);
    void erase(T val);
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
    while (z != _root && z->parent()->color()) {
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
       
            if ((parentIsLeft && z == z->parent()->right()) || (!parentIsLeft && z == z->parent()->left())) {
                z = z->parent();
                parentIsLeft ? rotateLeft(z) : rotateRight(z);
            }

            z->parent()->color(false);
            grandparent->color(true);
            parentIsLeft ? rotateRight(grandparent) : rotateLeft(grandparent);
        }
    }
    _root->color(false);
}
template <class T>
void RBTree<T>::rotateLeft(RBTreeNode<T>* x) {
    if (x == nullptr || x->right() == nullptr) return;

    RBTreeNode<T>* y = x->right();
    x->right(y->left());

    if (y->left() != nullptr) {
        y->left()->parent(x);
    }

    y->parent(x->parent());

    if (x->parent() == nullptr) {
        _root = y;
    }
    else if (x == x->parent()->left()) {
        x->parent()->left(y);
    }
    else {
        x->parent()->right(y);
    }

    y->left(x);
    x->parent(y);
}

template <class T>
void RBTree<T>::rotateRight(RBTreeNode<T>* y) {
    if (y == nullptr || y->left() == nullptr) return;

    RBTreeNode<T>* x = y->left();
    y->left(x->right());

    if (x->right() != nullptr) {
        x->right()->parent(y);
    }

    x->parent(y->parent());

    if (y->parent() == nullptr) {
        _root = x;
    }
    else if (y == y->parent()->right()) {
        y->parent()->right(x);
    }
    else {
        y->parent()->left(x);
    }

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
}//картинки, цвета - изменить на дефайн, чтобы просто вставляло каждый раз при выводе


template <class T>
void RBTree<T>::erase(T val) {
    RBTreeNode<T>* z = search(val);
    if (!z) return;

    RBTreeNode<T>* y = z;
    bool yOriginalColor = y->color();
    RBTreeNode<T>* x = nullptr;

    if (z->left() == nullptr) {
        x = z->right();
        transplant(z, z->right());
    }
    else if (z->right() == nullptr) {
        x = z->left();
        transplant(z, z->left());
    }
    else {
        y = minimum(z->right());
        yOriginalColor = y->color();
        x = y->right();
        if (y->parent() == z) {
            if (x) x->parent(y);
        }
        else {
            transplant(y, y->right());
            y->right(z->right());
            y->right()->parent(y);
        }
        transplant(z, y);
        y->left(z->left());
        y->left()->parent(y);
        y->color(z->color());
    }

    delete z;
    _size--;

    if (yOriginalColor == false && x) {
        fixAfterErase(x);
    }
}

template <class T>
void RBTree<T>::transplant(RBTreeNode<T>* u, RBTreeNode<T>* v) {
    if (u->parent() == nullptr) {
        _root = v;
    }
    else if (u == u->parent()->left()) {
        u->parent()->left(v);
    }
    else {
        u->parent()->right(v);
    }
    if (v) v->parent(u->parent());
}

template <class T>
RBTreeNode<T>* RBTree<T>::minimum(RBTreeNode<T>* node) {
    while (node->left() != nullptr) {
        node = node->left();
    }
    return node;
}

template <class T>
void RBTree<T>::fixAfterErase(RBTreeNode<T>* x) {
    while (x != _root && (x == nullptr || x->color() == false)) {
        if (x == x->parent()->left()) {
            RBTreeNode<T>* s = x->parent()->right();

            if (s != nullptr && s->color()) {
                s->color(false);
                x->parent()->color(true);
                rotateLeft(x->parent());
                s = x->parent()->right();
                if (s == nullptr) break;
            }

            if (s == nullptr) break; 

            bool leftBlack = (s->left() == nullptr || !s->left()->color());
            bool rightBlack = (s->right() == nullptr || !s->right()->color());
            if (leftBlack && rightBlack) {
                s->color(true);
                x = x->parent();
            }
            else {

                if (rightBlack) {
                    if (s->left() != nullptr) s->left()->color(false);
                    s->color(true);
                    rotateRight(s);
                    s = x->parent()->right();
                    if (s == nullptr) break;
                }


                s->color(x->parent()->color());
                x->parent()->color(false);
                if (s->right() != nullptr) s->right()->color(false);
                rotateLeft(x->parent());
                x = _root; 
            }
        }
        else {
            RBTreeNode<T>* s = x->parent()->left();

            if (s != nullptr && s->color()) {
                s->color(false);
                x->parent()->color(true);
                rotateRight(x->parent());
                s = x->parent()->left();
                if (s == nullptr) break;
            }

            if (s == nullptr) break;

            bool rightBlack = (s->right() == nullptr || !s->right()->color());
            bool leftBlack = (s->left() == nullptr || !s->left()->color());
            if (rightBlack && leftBlack) {
                s->color(true);
                x = x->parent();
            }
            else {
                if (leftBlack) {
                    if (s->right() != nullptr) s->right()->color(false);
                    s->color(true);
                    rotateLeft(s);
                    s = x->parent()->left();
                    if (s == nullptr) break;
                }

                s->color(x->parent()->color());
                x->parent()->color(false);
                if (s->left() != nullptr) s->left()->color(false);
                rotateRight(x->parent());
                x = _root;
            }
        }
    }

    if (x != nullptr) x->color(false); 
}