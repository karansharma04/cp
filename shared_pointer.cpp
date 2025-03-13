#include<bits/stdc++.h>
using namespace std;

class Entity {
    int val;
public:
    Entity() {
        cout << "Entity Constructor called\n";
    }
    Entity(int val) : val(val) {
        cout << "Entity Param Constructor called\n";
    }
    void printGreeting() {
        cout << "Entity Hello there! " << val << endl;
    }
    ~Entity() {
        cout << "Entity Destructor called\n";
    }
};

template<typename T>
class SharedPointer {
public:
    SharedPointer() = delete;
    SharedPointer(T* ptr) : ptr(ptr) , cnt_ptr(new atomic<int>(1)) {
        cout << "Param constructor called!\n";
    }
    SharedPointer(const SharedPointer& other) : ptr(other.ptr) , cnt_ptr(other.cnt_ptr) {
        cout << "Copy constructor called!\n";
        (*cnt_ptr)++;
    }
    SharedPointer& operator=(const SharedPointer& other) {
        if (this == &other) return *this;
        decrement_and_cleanup();
        ptr = other.ptr;
        cnt_ptr = other.cnt_ptr;
        (*cnt_ptr)++;
        return *this;
    }

    SharedPointer(SharedPointer&& other) : ptr(other.ptr) , cnt_ptr(other.cnt_ptr) {
        other.ptr = nullptr;
        other.cnt_ptr = nullptr;
    }

    SharedPointer& operator=(SharedPointer&& other) {
        cout << "Move assignment!\n";
        if (this == &other) return *this;
        decrement_and_cleanup();
        ptr = other.ptr;
        cnt_ptr = other.cnt_ptr;
        other.ptr = nullptr;
        other.cnt_ptr = nullptr;
        return *this;
    }

    T* operator->() {
        return ptr;
    }

    ~SharedPointer() {
        cout << "Destructor got called!" << endl;
        decrement_and_cleanup();
    }
private:
    T* ptr;
    atomic<int>* cnt_ptr;

    void decrement_and_cleanup() {
        if (!cnt_ptr) return;
        (*cnt_ptr)--;
        if (*cnt_ptr == 0) {
            delete cnt_ptr;
            delete ptr;
        }
    }
};

// template<typename T>
// class WeakPointer {
// public:
//     WeakPointer() = delete;
//     WeakPointer(const SharedPointer& other) : ptr(other.ptr) , cnt_ptr(other.cnt_ptr) {}
//     WeakPointer(const WeakPointer& other) : ptr(other.ptr) , cnt_ptr(other.cnt_ptr) {}
//     WeakPointer& operator=(const WeakPointer& other) {
//         if (this == &other) return *this;
//         ptr = other.ptr;
//         cnt_ptr = other.cnt_ptr;
//     }

//     T* operator->() {
//         return ptr;
//     }

//     T& access() {
//         if (
//     }

//     ~WeakPointer() {}
// private:
//     T* ptr;
//         int* cnt_ptr;
// };



int main() {
    SharedPointer s1(new Entity());
    s1 = SharedPointer(new Entity());
    cout << "here" << endl;
    return 0;
}