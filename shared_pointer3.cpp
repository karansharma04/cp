#include<bits/stdc++.h>
using namespace std;

class Entity {
    int x , y;
public:
    Entity() {
        cout << "Entity Constructor!" << endl;
    }
    void printGreeting() {
        cout << "Hello World! " << x << ' ' << y << endl;
    }
    ~Entity() {
        cout << "Entity Destructor!" << endl;
    }
};

template<typename T>
class SharedPointer {
public:
    SharedPointer() = delete;
    SharedPointer(T* ptr) : m_ptr(ptr) , m_ref(new atomic<int>(1)) {}
    SharedPointer(const SharedPointer& other) : m_ptr(other.m_ptr) , m_ref(other.m_ref) {
        m_ref->fetch_add(1);
    }
    SharedPointer(SharedPointer&& other) : m_ptr(other.m_ptr) , m_ref(other.m_ref) noexcept {
        other.m_ptr = other.m_ref = nullptr;
    }
    SharedPointer& operator=(const SharedPointer& other) {
        if (this != &other) {
            clear();
            m_ptr = other.m_ptr;
            m_ref = other.m_ref;
            m_ref->fetch_add(1);
        }
        return *this;
    }
    SharedPointer& operator=(SharedPointer&& other) {
        if (this != &other) {
            clear();
            m_ptr = other.m_ptr;
            m_ref = other.m_ref;
            other.m_ptr = other.m_ref = nullptr;
        }
        return *this;
    }
    T* operator->() {
        return m_ptr;
    }
    ~SharedPointer() {
        clear();
    }
private:
    void clear() {
        if (!m_ref) return;
        if (m_ref->fetch_sub(1 , memory_order_acquire) == 1) {
            delete m_ptr;
            delete m_ref;
        }
    }
    T* m_ptr;
    atomic<int>* m_ref;
};

int main() {
    SharedPointer<Entity> s_ptr1 = new Entity;
    // {
    //     SharedPointer s_ptr2 = new Entity;
    //     s_ptr1 = s_ptr2;
    // }
    s_ptr1->printGreeting();
    return 0;
}