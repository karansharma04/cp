#include <bits/stdc++.h>
using namespace std;

const int n = 5;
mutex chopsticks[n];
mutex print_lock;

void philosopher(int id) {
  while (true) {
    if (id % 2) {
      chopsticks[id].lock();
      chopsticks[(id + 1) % n].lock();
    } else {
      chopsticks[(id + 1) % n].lock();
      chopsticks[id].lock();
    }
    // eat
    print_lock.lock();
    cout << "Phil " << id << " is eating" << endl;
    print_lock.unlock();
    this_thread::sleep_for(0.5s);
    chopsticks[id].unlock();
    chopsticks[(id + 1) % n].unlock();
    // think
    print_lock.lock();
    cout << "Phil " << id << " is thinking" << endl;
    print_lock.unlock();
    this_thread::sleep_for(0.5s);
  }
}

int main() {
  thread philosophers[n];
  for (int i = 0; i < n; i++) {
    philosophers[i] = thread(philosopher, i);
  }
  for (int i = 0; i < n; i++) {
    philosophers[i].join();
  }
  return 0;
}