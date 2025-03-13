#include <bits/stdc++.h>
using namespace std;

void* operator new(size_t size) {
    cout << "Heap memory allocated" << endl;
    return malloc(size);
}

void operator delete(void* ptr) {
    cout << "Heap memory deallocated" << endl;
    free(ptr);
}

class String {
    size_t m_sz;
    char* m_str;

public:
    String() {}
    String(const char* str) {
        m_sz = strlen(str);
        m_str = new char[m_sz];
        for (int i = 0; i < m_sz; i++) {
            m_str[i] = str[i];
        }
    }
    String(const String& other) : m_sz(other.m_sz) {
        cout << "Copy constructor called" << endl;
        m_str = new char[m_sz];
        for (int i = 0; i < m_sz; i++)
            m_str[i] = other.m_str[i];
    }
    String(String&& other) noexcept {
        cout << "Move constructor called" << endl;
        m_str = other.m_str;
        m_sz = other.m_sz;
        other.m_str = nullptr;
        other.m_sz = 0;
    }
    void printName() {
        if (m_str)
            cout << m_str << endl;
        else
            cout << "No value to print" << endl;
    }
    ~String() {
        cout << "Destroyed" << endl;
        if (m_str)
            delete[] m_str;
        m_str = nullptr;
        m_sz = 0;
    }
};

class Entity {
    String name;
public:
    Entity(String name) : name(move(name)) {}
};

int main() {
    Entity e("Karan Sharma");
    String s("Karan Sharam");
    String p = move(s);

    return 0;
}