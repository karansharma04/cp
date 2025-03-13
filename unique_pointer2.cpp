#include<bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor called!" << endl;
    }
    void printGreeting() {
        cout << "Hello there" << endl;
    }
    ~Entity() {
        cout << "Destructor called!" << endl;
    }
};

template<typename T>
class UniquePointer {
public:
    UniquePointer() = delete;
    UniquePointer(T* ptr) : m_ptr(ptr) {}
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer(UniquePointer&& other) {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& other) {
        if (this != &other) {
            delete m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    T* operator->() {
        return m_ptr;
    }

    ~UniquePointer() {
        delete m_ptr;
    }
private:
    T* m_ptr;
};

int main() {
    UniquePointer u_ptr1 = new Entity;
    cout << "1" << endl;
    UniquePointer u_ptr2(move(u_ptr1));
    return 0;
}
