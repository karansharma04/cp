#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Entity Constructor called!" << endl;
    }
    Entity(const Entity& other) {
        cout << "Entity copy Constructor called!" << endl;
    }
    virtual void PrintName() {
        cout << "Entity" << endl;
    }
    virtual ~Entity() {
        cout << "Entity Destructor called!" << endl;
    }
private:
    void* operator new(size_t sz) {
        return malloc(sz);
    }
};

class Player : public Entity {
public:
    Player() {
        cout << "Player Constructor called!" << endl;
    }
    void PrintName() noexcept {
        cout << "Player" << endl;
    }
    ~Player() {
        cout << "Player Destructor called!" << endl;
    }
};

int main() {
    Player p;
    return 0;
}