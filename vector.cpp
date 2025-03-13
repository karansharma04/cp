#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
    T* ptr = nullptr;
    size_t size = 0;
    size_t internal_size = 0;
public:
    Vector() : ptr(nullptr) , size(0) {
        internal_size = 0;
    }
    Vector(size_t size) : size(size) {
        internal_size = 1;
        while (internal_size < size) internal_size <<= 1;
        ptr = new T[internal_size];
    }

    void push_back(T el) {
        size++;
        if (internal_size < size) {
            if (internal_size == 0) internal_size = 1;
            else internal_size <<= 1;
            T* new_ptr = new T[internal_size];
            memcpy(new_ptr , ptr , (size - 1) * sizeof(T));
            delete[] ptr;
            ptr = new_ptr;
        }
        ptr[size - 1] = el;
    }

    void pop_back() {
        if (size == 0) return;
        if (size == 1) {
            size = 0;
            internal_size = 0;
            delete[] ptr;
            ptr = nullptr;
            return;
        }
        size--;
        if (size == internal_size / 2) {
            internal_size >>= 1;
            T* new_ptr = new T[internal_size];
            memcpy(new_ptr , ptr , size * sizeof(T));
            delete[] ptr;
            ptr = new_ptr;
        }
    }

    T& operator[](uint32_t index) {
        return ptr[index];
    }

    void PrintSize() {
        cout << "Current size: " << size << endl;
        cout << "Actual size: " << internal_size << endl;
    }

    T* begin() {
        return ptr;
    }

    T* end() {
        return ptr + size;
    }

    ~Vector() {
        if (ptr) {
            delete[] ptr;
        }
        size = 0;
    }
};

int main() {
    Vector<int> v;
    for (int i = 1;i <= 5;i++) {
        v.push_back(i);
    }
    v.PrintSize();
    for (int i = 0;i < 5;i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    for (auto it = v.begin(); it != v.end();it++) {
        cout << *it << ' ';
    }
    cout << endl;
    for (auto el : v) {
        cout << el << ' ';
    }
    cout << endl;
    return 0;
}