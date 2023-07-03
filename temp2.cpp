#include <bits/stdc++.h>
using namespace std;

#define int long long

// #define alias some long thinng

// #define BEST_INT 7
// a's ascii character 97
// A's accii character 65
// 0's is 48
// total 256 chars -> -128 to 127

// array is static?
// vector is dynamic? memory allocation?

// my_ptr[0] is same as *my_ptr
// my_ptr[x] is same as *(my_ptr+x)

// Since the printGreeting() function is virtual, the function call will be
// resolved at runtime based on the actual object type rather than the reference
// type

// When base class pointer points to derived class object: if virtual function
// is defined in base class and function with same signature is defined in
// derived class, on calling function from base class pointer -> derived class'
// version will be called. If no virtual keyword, base class' version is called.
// When base class object is assigned derived class object: only members
// inherited from base class are overwritten. And virtual doesn't make any
// difference. Since object type is base, only base class' version will be
// called.

// Name mangling -> adding additional info about args in name of function

// initializer list can be used to initialize const variables of struct and
// classes in c++

// void pointers are used as generic pointers

// uninitialized pointers -> wild pointers

// const int* ptr -> value can't be modified, int* const ptr -> pointer cannot
// be modified

// dangling pointer -> points to a memory location which has been deleted or
// freed

// int,float -> 4bytes, ll,double->8

// I/O redirection -> freopen

// delete operator deallocates memory AND CALLS DESTRUCTOR of object being
// deleted. free function only deallocates memory and DOES NOT CALL destructor.

// literal is a constant variable

// functors are objects that behave like functions

// class myFunctor {
//   public:
//   int f1;
//   myFunctor(int f1):f1(f1) {}
//   int operator()(int f2) {
//     return f1*f2;
//   }
// };

// array decay

//**
// static member functions can only access other static data members and member
// functions

// when do we need to create our own copy constructor?
// When there is some dynamic memory allocation in our class, and we want to
// make deep copies of it instead of just another pointer in the new object
// pointing to the same location in heap we should create our own copy
// constructor which creates deep copy of object, with new dynamic memory
// allocation.


// normally, destructor is called when the object goes out of scope, but if
// object is created in heap using dyn. mem. all., it is the programmer's
// responsibility to deallocate and the compiler doesn't bother. The programmer
// has to explicitly delete the object in that case

// in C++, there is no overloading across scopes, so no overloading across
// parent and child, recommended to use function overriding instead of
// overloading in these scenarios

// virtual keyword is only required in base class, thereby it becomes virtual in
// every child class as well

// even if a virtual function is made private in derived class, you can still
// access it via base class pointer

// virtual functions are resolved at runtime, hence cannot be inlined because
// inlining happens during compile-time

// override keyword is a safety mechanism which gives compilation error if
// virtual function signature doesn't match that of base class'

// possible to create a pure virtual destructor

// segmentation fault -> when we try to access invalid memory, usually caused by
// null pointer dereferencing or array index out of bound

// floating point exception -> when we try to perform an illegal floating point
// operation, /0 or square root of -ve numbers

// b=dynamic_cast<Derived*>(b);

// uncaught exception -> c++ by default calls terminate which calls abort

// stack unwinding -> c++ searches for exception handler in successively higher
// scopes

// to access global variable -> ::x

// making operator new private for a class will restrict dynamic memory
// allocation using new

// class with private destructor ONLY can be instantiated with new keyword/
// dynamic memory allocation

// to only allow dynamic memory allocation for objects of a class -> make destructor private and use delete this from destroy method or delete ptr from friend function destroy

// to not allow dynamic memory allocation using new, make new private

// the diamond problem in multiple inheritance is solved using virtual inheritance, virtual inheritance ensures that only one instance of the base class is shared among all the derived classes

int gcd(int a, int b) {
  if(b==0) return a;
  return gcd(b, a%b);
}

int func(int x, int n) {
  return (x*x+1) % n;
}

int cnt = 0;

int pollard_rho(int n) {
  if(n<4) return n;
  srand(time(NULL));
  int x = 2 + rand()%(n-3);
  int y = x;
  while(true) {
    cnt++;
    x = func(x, n);
    y = func(func(y, n), n);
    int g = abs(gcd(x-y, n));
    if(g!=1 && g!=0) return g;
  }
}

int powerWithModulus(int a, int p, int mod) {
  if (p == 0) return 1;
  if (p == 1) return a % mod;
  int temp = powerWithModulus(a, p / 2, mod);
  temp = (temp >> 1) % mod;
  if (p % 2) return (temp * a) % mod;
  return temp;
}

int pollar_p_minus_1(int n) {
  if(n<4) return n;
  srand(time(NULL));
  int a = 2 + rand()%(n-3);
  for(int i=1;i<=1000;i++) {
    cnt++;
    a = powerWithModulus(a, i, n);
    int g = abs(gcd(a-1, n));
    if(g!=1 && g!=0) return g;
  }
  return n;
}


int32_t main() {
  cout<<pollar_p_minus_1(7429)<<'\n';
  cout<<cnt<<'\n';
  return 0;
}