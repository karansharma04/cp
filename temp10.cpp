#include<bits/stdc++.h>
using namespace std;

class Entity {
public:
    virtual ~Entity() {}
};

class Player : public Entity {

};

class Enemy : public Entity {

};

struct Pair {
    int x , y;
};

int main() {
    cout<<sizeof(int)<<' '<<sizeof(long)<<' '<<sizeof(long long)<<endl;
    return 0;
}