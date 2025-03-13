#include<bits/stdc++.h>
using namespace std;

class Entity {
    int x;
public:
    Entity(int x) : x(x) {}
    Entity() {
        cout << "Constructor" << endl;
    }
    ~Entity() {
        cout << "Destructor" << endl;
    }
    void PrintGreeting() {
        cout << "hello world " << endl;
    }
};

template<typename T>
class SharedPointer {
public:
    SharedPointer() : m_ptr(nullptr) , m_ref(nullptr) {}
    SharedPointer(T* ptr) : m_ptr(ptr) , m_ref(new atomic<int>(1)) {}
    SharedPointer(const SharedPointer& other) : m_ptr(other.m_ptr) , m_ref(other.m_ref) {
        m_ref->fetch_add(1);
    }
    SharedPointer(SharedPointer&& other) : m_ptr(other.m_ptr) , m_ref(other.m_ref) {
        other.m_ptr = nullptr;
        other.m_ref = nullptr;
    }
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            decrement_ref_and_clear();
            m_ptr = other.m_ptr;
            m_ref = other.m_ref;
            m_ref->fetch_add(1);
        }
        return *this;
    }
    SharedPointer& operator=(SharedPointer&& other) {
        if (this != &other) {
            decrement_ref_and_clear();
            m_ptr = other.m_ptr;
            m_ref = other.m_ref;
            other.m_ptr = nullptr;
            other.m_ref = nullptr;
        }
        return *this;
    }
    T* operator->() {
        return m_ptr;
    }
    ~SharedPointer() {
        decrement_ref_and_clear();
    }
private:
    void decrement_ref_and_clear() {
        if (!m_ref) return;
        if (m_ref->fetch_sub(1 , memory_order_acquire) == 1) {
            delete m_ref;
            delete m_ptr;
        }
    }
    T* m_ptr;
    atomic<int>* m_ref;
};

int main() {
    SharedPointer<Entity> s_ptr1 = new Entity;
    {
        SharedPointer<Entity> s_ptr2;
        s_ptr2 = move(s_ptr1);
    }
    cout << "Here" << endl;
    return 0;
}