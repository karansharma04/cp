#include <bits/stdc++.h>
using namespace std;

struct GrandParent {
  GrandParent() { cout << "GrandParent constructor!" << endl; }
  virtual void PrintClassName() { cout << "GrandParent class!" << endl; }
  virtual ~GrandParent() { cout << "GrandParent destructor!" << endl; }
};

struct Parent : public GrandParent {
  Parent() { cout << "Parent constructor!" << endl; }
  void PrintClassName() { cout << "Parent class!" << endl; }
  ~Parent() { cout << "Parent destructor!" << endl; }
};

struct Child : public Parent {
  Child() { cout << "Child constructor!" << endl; }
  // void PrintClassName() {
  //   cout<<"Child class!"<<endl;
  // }
  ~Child() { cout << "Child destructor!" << endl; }
};

struct GrandChild : public Child {
  GrandChild() { cout << "GrandChild constructor!" << endl; }
  void PrintClassName() { cout << "GrandChild class!" << endl; }
  ~GrandChild() { cout << "GrandChild destructor!" << endl; }
};

int main() {
  Parent* gp_ptr = new GrandChild();
  gp_ptr->PrintClassName();
  delete gp_ptr;
  return 0;
}