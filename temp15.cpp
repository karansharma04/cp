#include <bits/stdc++.h>
using namespace std;

struct A {
    void print() {
        cout << a << ' ' << b << ' ' << c << endl;
    }
private:
    int a = 4;
    int b = 8;
    int c = 10;
};

struct B : public A {
    int b = 8;
};

int main() {
    B b;
    b.print();
    cout << sizeof(A) << ' ' << sizeof(B) << endl;
    return 0;
}
