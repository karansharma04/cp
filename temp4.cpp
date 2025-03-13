#include <bits/stdc++.h>
using namespace std;

struct Vector {
  virtual void PrintVector() const = 0;
};

struct Vector2 : public Vector {
  float x, y;

  Vector2(float x, float y) : x(x), y(y) {}

  Vector2 Add(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
  }

  Vector2 Multiply(const Vector2& other) const {
    return Vector2(x * other.x, y * other.y);
  }

  Vector2 Multiply(int scalar) const { return Vector2(scalar * x, scalar * y); }

  Vector2 operator+(const Vector2& other) const { return Add(other); }

  Vector2 operator*(const Vector2& other) const { return Multiply(other); }

  Vector2 operator*(int scalar) const { return Multiply(scalar); }

  bool operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
  }

  void PrintVector() const { cout << "{" << x << ", " << y << "}" << endl; }
};

class ScopedPtr {
 public:
  Vector2* ptr;

 public:
	ScopedPtr(Vector2* other): ptr(other) {}

	~ScopedPtr() {
		delete ptr;
		cout<<"Destroyed!"<<endl;
	}

	Vector2* operator->() {
		return ptr;
	}
};

int main() {
  ScopedPtr s_ptr = new Vector2(1, 2);
  s_ptr->PrintVector();
  return 0;
}