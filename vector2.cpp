#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
public:
    Vector() : m_sz(0) , m_act_sz(0) , m_arr(nullptr) {
        cout << "Default constructor called!" << endl;
    }
    Vector(size_t sz , T default_el) : m_act_sz(sz) {
        cout << "Param constructor called!" << endl;
        m_sz = 1;
        while (m_sz < m_act_sz) m_sz <<= 1;
        m_arr = new T[m_sz];
        for (int i = 0;i < m_act_sz;i++) {
            m_arr[i] = default_el;
        }
    }
    Vector(const T* arr , size_t sz) : m_act_sz(sz) {
        m_sz = 1;
        while (m_sz < m_act_sz) m_sz <<= 1;
        m_arr = new T[m_sz];
        for (int i = 0;i < m_act_sz;i++) {
            m_arr[i] = arr[i];
        }
    }
    Vector(const Vector& other) : m_sz(other.m_sz) , m_act_sz(other.m_act_sz) {
        cout << "Copy constructor called!" << endl;
        m_arr = new T[m_sz];
        for (int i = 0;i < m_act_sz;i++) m_arr[i] = other.m_arr[i];
    }
    Vector& operator=(const Vector& other) {
        cout << "Copy assignment op. called!" << endl;
        if (this != &other) {
            m_sz = other.m_sz;
            m_act_sz = other.m_act_sz;
            m_arr = new T[m_sz];
            for (int i = 0;i < m_act_sz;i++) m_arr[i] = other.m_arr[i];
        }
        return *this;
    }
    Vector(Vector&& other) : m_sz(other.m_sz) , m_act_sz(other.m_act_sz) {
        cout << "Move constructor called!" << endl;
        m_arr = other.m_arr;
        other.m_arr = nullptr;
        other.m_sz = other.m_act_sz = 0;
    }
    Vector& operator=(Vector&& other) {
        cout << "Move assignment op. called!" << endl;
        if (this != &other) {
            m_sz = other.m_sz;
            m_act_sz = other.m_act_sz;
            m_arr = other.m_arr;
            other.m_arr = nullptr;
            other.m_sz = other.m_act_sz = 0;
        }
        return *this;
    }

    void push_back(T el) {
        if (m_act_sz == m_sz) {
            if (m_sz) m_sz <<= 1;
            else m_sz = 1;
            T* new_arr = new T[m_sz];
            for (int i = 0;i < m_act_sz;i++) {
                new_arr[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = new_arr;
        }
        m_act_sz++;
        m_arr[m_act_sz - 1] = el;
    }
    void pop_back() {
        if (m_act_sz == 0) return;
        m_act_sz--;
        if (m_act_sz == 0) {
            m_sz = 0;
            delete[] m_arr;
            return;
        }
        if (m_act_sz == m_sz / 2) {
            m_sz >>= 1;
            T* new_arr = new T[m_sz];
            for (int i = 0;i < m_act_sz;i++) {
                new_arr[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = new_arr;
        }
    }
    size_t size() const {
        return m_act_sz;
    }
    T& operator[](int ind) const {
        if (ind<0 || ind>m_act_sz - 1) throw out_of_range("index out of bounds");
        return m_arr[ind];
    }

    T* begin() {
        return m_arr;
    }

    T* end() {
        return m_arr + m_act_sz;
    }

    ~Vector() {
        delete[] m_arr;
        m_sz = m_act_sz = 0;
    }
private:
    T* m_arr;
    size_t m_sz;
    size_t m_act_sz;
};

int main() {
    Vector<const char*> v;
    v = Vector(3 , "Karan");
    for (auto x : v) cout << x << endl;
    return 0;
}