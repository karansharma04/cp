#include <bits/stdc++.h>
using namespace std;

struct Entity {
    Entity() {
        cout << "Constructor called!" << endl;
    }
    ~Entity() {
        cout << "Destructor called!" << endl;
    }
};

template<typename T>
class UniquePointer {
public:
    UniquePointer() = delete;
    UniquePointer(T* m_ptr) : m_ptr(m_ptr) {}
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer(UniquePointer&& other) : m_ptr(other.m_ptr) {
        other.m_ptr = nullptr;
    }
    int* operator->() {
        return m_ptr;
    }
    ~UniquePointer() {
        delete m_ptr;
    }
private:
    T* m_ptr;
};

int main() {
    UniquePointer u_ptr = new Entity;
    cout << "here" << endl;
    UniquePointer u_ptr2 = move(u_ptr);
    cout << "here" << endl;
    return 0;
}
