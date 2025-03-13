#include <bits/stdc++.h>
using namespace std;

void* operator new(size_t size) {
    cout << "Allocating on the heap!" << endl;
    return malloc(size);
}

void operator delete(void* ptr) {
    cout << "Deallocating memory from the heap!" << endl;
    free(ptr);
}

class Entity {
public:
    Entity() { cout << "Constructor called!" << endl; }
    void PrintGreeting() {
        cout << "Hello there!" << endl;
    }
    ~Entity() { cout << "Destructor called!" << endl; }
};

template <typename T>
class SharedPointer {
private:
    T* ptr = nullptr;

public:
    int* ref_count_ptr = nullptr;
    SharedPointer() = delete;
    SharedPointer(const SharedPointer& other) {
        ptr = other.GetObjectPointer();
        ref_count_ptr = other.ref_count_ptr;
        (*ref_count_ptr)++;
    }
    T* GetObjectPointer() const { return ptr; }
    SharedPointer(T* const e_ptr) {
        ptr = e_ptr;
        ref_count_ptr = new int(1);
    }

    void PrintRefCount() {
        if (ref_count_ptr)
            cout << "Current ref count is: " << (*ref_count_ptr) << endl;
    }

    T& operator*() { return *ptr; }

    T& Get() { return *ptr; }

    ~SharedPointer() {
        (*ref_count_ptr)--;
        if ((*ref_count_ptr) == 0) {
            delete ptr;
            ptr = nullptr;
            delete ref_count_ptr;
            ref_count_ptr = nullptr;
        }
    }
};

class UniquePointer {
private:
    Entity* ptr = nullptr;

public:
    UniquePointer() = delete;
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer(Entity* e_ptr) : ptr(e_ptr) {}
    UniquePointer(UniquePointer&& other) {
        cout << "move constructor called" << endl;
        if (ptr)
            delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    UniquePointer& operator=(UniquePointer&& other) {
        cout << "move assignment operator called" << endl;
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    Entity* operator->() {
        return ptr;
    }
    ~UniquePointer() {
        if (ptr)
            delete ptr;
    }
};

int main() {
    UniquePointer u_ptr_1(new Entity);
    UniquePointer u_ptr_2(new Entity);
    u_ptr_2 = move(u_ptr_1);
    u_ptr_2->PrintGreeting();
    return EXIT_SUCCESS;
}