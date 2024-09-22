#include <iostream> 
#include <vector> 

//вставка, поиск, удаление 

template <class T>
class TStack {
    T* _data;
    size_t _size;
    size_t _top;
public:
    TStack(size_t size) {};

    ~TStack() {};

    void push(T val) {
    }; //исклюсение на то есть ли там элемент 

    //void push только для vector 

    void pop() {};

    inline bool isEmpty() const noexcept {
    }//тоже самое для vector _data.size() == 0 



    inline bool isFull() const noexcept {
    }

    inline T top() const {
    } //не нужно 
};

template <class T>
TStack<T>::TStack(size_t size = 20) {
    _data = new T[size];
    _size = size;
    _top = -1;
}

template <class T>
TStack<T>::~TStack() {
    delete[] _data;
    _data = nullptr;
}

template <class T>
bool TStack<T>::isEmpty() const noexcept {
    return _top == -1;
}

template <class T>
bool TStack<T>::isFull() const noexcept {
    return _top == _size - 1;
}

template <class T>
void Tstack<T>::push(T val) {
    if (isFull()) {
        throw
    }
    _top += 1;
    _data[_top] = val;
}

template <class T>
void TStack<T>::pop() {
    if (isEmpty()) {
        throw;
    }

    _top--;
}


int main() {
    int a;
}