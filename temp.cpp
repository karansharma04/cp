#include <bits/stdc++.h>
using namespace std;

// function overloading -> printNumber
// operator overloading -> complex number class
// function overriding -> shape class and circle, square classes
// RTTI -> typeid can give info about object type at runtime

// stack unwinding -> exception handling

// to only allow dynamic allocation for objects of a class, make destructor
// private delete this from inside another function destroy()

// advantage of using smart pointers
// automatic memory management, less risk of memory leaks and dangling pointers

// const function doesn't let us modify the data members of the object, unless
// they are declared as mutable

// only constant functions can be called on a constant reference to an object

// int const and const int are the same thing

// abstract class -> class which contains one or more pure virtual functions

// not allow stack allocation -> make destructor private
// not allow dynamic allocation -> make new/delete  new[]/delete[] operator
// private

// static variables - persist their value across multiple function invocations
// or multiple class instantiations

// Vector v = 10, if constructor for Vector which takes int exists: implicit
// type conversion on by default , to disable use explicit keyword

// virtual constructor XXXXX, doesn't make any sense

// virtual destructor is allowed

// opaque pointer is used to hide internal implementation details of the object
// from the user, and provide an interface to the user to interact with the
// object

int log_2(int num) {
  int cnt = 0;
  while(num>1) {
    cnt++;
    num/=2;
  }
  return cnt;
}

const int n = 20;

int query(int l, int r, int st[][n]) {
  return min(st[log_2(r - l)][l],
             st[log_2(r - l)][r + 1 - (1 << log_2(r - l))]);
};

int main() {
  int k = 25;
  vector<int> arr = {4, 7, 18, 16, 14, 16, 7, 13, 10, 2,
                     3, 8, 11, 20, 4,  7,  1, 7,  13, 17};
  int st[k][n];
  // st[i][j] - min of the range which starts from j and is of size 2^i
  for (int j = 0; j < n; j++) {
    st[0][j] = arr[j];
  }
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < n; j++) {
      st[i][j] = st[i - 1][j];
      if (j + (1 << (i - 1)) < n)
        st[i][j] = min(st[i][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }

  for(int i=6;i<=13;i++) cout<<arr[i]<<' ';
  cout<<endl;

  cout << query(11, 13, st) << endl;

  return 0;
}