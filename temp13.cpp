#include<bits/stdc++.h>
using namespace std;

void* operator new(size_t sz) {
    cout << "here 1" << endl;
    return malloc(sz);
}

class Entity {
    int x , y;
public:
    Entity() {
        cout << "Constructor called!" << endl;
    }
    Entity(int x , int y) : x(x) , y(y) {
        cout << "Param Constructor called!" << endl;
    }
    void printGreeting() {
        cout << "Hello" << endl;
    }
    ~Entity() {
        cout << "Destructor called!" << endl;
    }
};

int main() {
    Entity* e = new Entity(1 , 2);
    int* arr = reinterpret_cast<int*>(e);
    for (int i = 0;i < 2;i++) cout << arr[i] << ' ';
    cout << endl;
    delete e;
    return 0;
}