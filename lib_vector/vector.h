#pragma once
#include "../lib_dmassive/dmassive.h"
#include <cmath>
#include <stdexcept>


template <typename T>
class TVector {
private:
    TDMassive<T> _data;

public:
    TVector();
    TVector(size_t size, T value = T());
    TVector(const T* arr, size_t size);

    size_t size() const;

    const T& operator[](int index) const noexcept;
    T& operator[](int index) noexcept;

    TVector<T> operator+(const TVector<T>& other) const;
    TVector<T> operator-(const TVector<T>& other) const;
    TVector<T>& operator+=(const TVector<T>& other);
    TVector<T>& operator-=(const TVector<T>& other);
    TVector<T>& operator*=(const T& scalar);
    TVector<T>& operator*=(const TVector<T>& other);
    int operator*(const TVector<T>& other) const;
    TVector<T> operator*(T scalar) const;

    bool operator==(const TVector<T>& other) const;
    bool operator!=(const TVector<T>& other) const;

    double length() const noexcept;
};


template <typename T>
TVector<T>::TVector() : _data() {}

template <typename T>
TVector<T>::TVector(size_t size, T value) : _data(size, value) {}

template <typename T>
TVector<T>::TVector(const T* arr, size_t size) : _data(arr, size) {}


template <typename T>
size_t TVector<T>::size() const {
    return _data.size();
}

template <typename T>
const T& TVector<T>::operator[](int index) const noexcept {
    return _data.data()[index];
}

template <typename T>
T& TVector<T>::operator[](int index) noexcept {
    return const_cast<T&>(static_cast<const TVector&>(*this)[index]);
}


template <typename T>
TVector<T> TVector<T>::operator+(const TVector<T>& other) const {
    size_t n = size();
    TVector<T> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

template <typename T>
TVector<T> TVector<T>::operator-(const TVector<T>& other) const {
    size_t n = size();
    TVector<T> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = (*this)[i] - other[i];
    }
    return result;
}

template <typename T>
TVector<T>& TVector<T>::operator+=(const TVector<T>& other) {
    for (size_t i = 0; i < size(); ++i) {
        (*this)[i] += other[i];
    }
    return *this;
}

template <typename T>
TVector<T>& TVector<T>::operator-=(const TVector<T>& other) {
    for (size_t i = 0; i < size(); ++i) {
        (*this)[i] -= other[i];
    }
    return *this;
}
template <typename T>
TVector<T>& TVector<T>::operator*=(const T& scalar) {
    for (size_t i = 0; i < size(); ++i) {
        (*this)[i] *= scalar;
    }
    return *this;
}

template <typename T>
TVector<T>& TVector<T>::operator*=(const TVector<T>& other) {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must have the same size for element-wise multiplication.");
    }
    for (size_t i = 0; i < size(); ++i) {
        (*this)[i] *= other[i];
    }
    return *this;
}

template <typename T>
int TVector<T>::operator*(const TVector<T>& other) const {
    int result = 0;
    for (size_t i = 0; i < size(); ++i) {
        result += (*this)[i] * other[i];
    }
    return result;
}

template <typename T>
TVector<T> TVector<T>::operator*(T scalar) const {
    size_t n = size();
    TVector<T> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = (*this)[i] * scalar;
    }
    return result;
}

template <typename T>
bool TVector<T>::operator==(const TVector<T>& other) const {
    if (size() != other.size()) return false;
    for (size_t i = 0; i < size(); ++i) {
        if ((*this)[i] != other[i]) return false;
    }
    return true;
}

template <typename T>
bool TVector<T>::operator!=(const TVector<T>& other) const {
    return !(*this == other);
}


template <typename T>
double TVector<T>::length() const noexcept {
    double sum = 0;
    for (size_t i = 0; i < size(); ++i) {
        sum += (*this)[i] * (*this)[i];
    }
    return std::sqrt(sum);
}