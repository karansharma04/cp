#include <cstring>
#include <iostream>

class String {
 private:
  char* m_String;
  int m_Size;

 public:
  String() : m_String(nullptr), m_Size(0) {
    std::cout << "Default Constructor called\n";
  }
  String(const char* string) {
    std::cout << "Created\n";
    m_Size = strlen(string);
    m_String = new char[m_Size];
    memcpy(m_String, string, m_Size);
  }
  String(const String& other) {
    std::cout << "Copy Constructor\n";
    m_Size = other.m_Size;
    m_String = new char[m_Size];
    memcpy(m_String, other.m_String, m_Size);
  }
  String(String&& other) {
    std::cout << "Move constructor\n";
    m_Size = other.m_Size;
    m_String = other.m_String;

    other.m_Size = 0;
    other.m_String = nullptr;
  }
  String& operator=(String&& other) {
    std::cout << "Move assignment\n";

    if (this != &other) {
      if (m_String) delete[] m_String;
      m_Size = other.m_Size;
      m_String = other.m_String;

      other.m_Size = 0;
      other.m_String = nullptr;
    }
    return *this;
  }
  String& operator=(String& other) {
    std::cout << "Copy Assignment\n";

    if (m_String) delete[] m_String;
    m_Size = other.m_Size;
    m_String = new char[m_Size];
    memcpy(m_String, other.m_String, m_Size);
    return *this;
  }
  void printString() {
    if (m_String) std::cout << m_String << '\n';
  }
  ~String() {
    std::cout << "Destroyed\n";
    delete[] m_String;
  }
};

class Entity {
  String name;

 public:
  Entity(const String& name) : name(name) {}
  Entity(String&& name) : name(std::move(name)) {}
  void printName() { name.printString(); }
};

int main() {
  String a{"Karan"};
  String b;
  b = std::move(a);
  b.printString();
  return 0;
}