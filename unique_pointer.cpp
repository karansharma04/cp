#include <bits/stdc++.h>
using namespace std;

template<typename T>
class UniquePointer {
public:
    UniquePointer() = delete;
    UniquePointer(T* ptr) : ptr(ptr) {
        cout << "Constructor called!\n";
    }
    UniquePointer(const UniquePointer&) = delete;
    T* operator->() {
        return ptr;
    }
    ~UniquePointer() {
        cout << "Destructor called!\n";
        delete ptr;
    }
private:
    T* ptr;
};

class Entity {
public:
    void PrintGreeting() {
        cout << "hello there!\n";
    }
};

int main() {
    UniquePointer ptr = new Entity;
    ptr->PrintGreeting();
    return 0;
}