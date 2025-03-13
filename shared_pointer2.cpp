#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor called!" << endl;
    }
    void printGreeting() {
        cout << "Hello world" << endl;
    }
    ~Entity() {
        cout << "Destructor called!" << endl;
    }
};

template<typename T>
class SharedPointer {
public:
    SharedPointer() : m_ptr(nullptr) , ref_ptr(nullptr) {}
    SharedPointer(T* ptr) : m_ptr(ptr) , ref_ptr(new int(1)) {
        cout << "Param Constructor" << endl;
    }
    SharedPointer(const SharedPointer& other) : m_ptr(other.m_ptr) , ref_ptr(other.ref_ptr) {
        cout << "Copy Constructor" << endl;
        (*ref_ptr)++;
    }
    SharedPointer& operator=(SharedPointer& other) {
        if (ref_ptr) {
            (*ref_ptr)--;
            if (*ref_ptr == 0) {
                delete m_ptr;
                delete ref_ptr;
            }
        }
        m_ptr = other.m_ptr;
        ref_ptr = other.ref_ptr;
        (*ref_ptr)++;
        return *this;
    }
    T* operator->() {
        return m_ptr;
    }
    ~SharedPointer() {
        (*ref_ptr)--;
        if (*ref_ptr == 0) {
            delete m_ptr;
        }
    }
private:
    T* m_ptr;
    int* ref_ptr;
};

SharedPointer<Entity> func() {
    return SharedPointer(new Entity);
}

int main() {
    SharedPointer<Entity> s_ptr = func();
    s_ptr->printGreeting();
    return 0;
}