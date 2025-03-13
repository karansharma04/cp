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
class SharedPointer {
public:
    SharedPointer() = delete;
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
            decrement_ref_and_clean();
            m_ptr = other.m_ptr;
            m_ref = other.m_ref;
            m_ref->fetch_add(1);
        }
        return *this;
    }
    SharedPointer& operator=(SharedPointer&& other) {
        if (this != &other) {
            decrement_ref_and_clean();
            m_ptr = other.m_ptr;
            m_ref = other.m_ref;
            other.m_ptr = nullptr;
            other.m_ref = nullptr;
        }
        return *this;
    }
    ~SharedPointer() {
        decrement_ref_and_clean();
    }
    int get_ref_count() {
        return *m_ref;
    }
private:
    T* m_ptr;
    atomic<int>* m_ref;
    void decrement_ref_and_clean() {
        if (!m_ref) return;
        if (m_ref->fetch_sub(1 , memory_order_acquire) == 1) {
            delete m_ref;
            delete m_ptr;
        }
    }
};

int main() {
    SharedPointer s_ptr1 = new Entity;
    cout << "here 1" << endl;
    {
        SharedPointer s_ptr2 = new Entity;
        cout << "here 2" << endl;
        s_ptr1 = s_ptr2;
        cout << "here 3: " << s_ptr1.get_ref_count() << endl;
    }
    cout << "here 4: " << s_ptr1.get_ref_count() << endl;
    return 0;
}
