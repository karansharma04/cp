#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
public:
    Vector() : m_arr(nullptr) , m_sz(0) , m_cap(0) {}
    Vector(int sz) : m_sz(sz) {
        m_cap = 2 * sz;
        m_arr = (T*)malloc(m_cap * sizeof(T));
    }
    void push_back(T el) {
        if (m_sz == m_cap) {
            m_cap = 2 * m_sz + 1;
            T* new_arr = (T*)malloc(m_cap * sizeof(T));
            for (int i = 0;i < m_sz;i++) {
                new_arr[i] = m_arr[i];
            }
            free(m_arr);
            m_arr = new_arr;
        }
        m_sz++;
        m_arr[m_sz - 1] = el;
    }
    void pop_back() {
        if (m_sz == 0) return;
        m_sz--;
    }
    T& operator[](int ind) {
        return m_arr[ind];
    }
    ~Vector() {
        free(m_arr);
        m_sz = 0;
        m_cap = 0;
    }
private:
    T* m_arr;
    int m_sz;
    int m_cap;
};

int main() {
    Vector<string> v;
    v.push_back("Karan");
    v.push_back("Sharma");
    for (int i = 0;i < 2;i++) cout << v[i] << endl;
    return 0;
}