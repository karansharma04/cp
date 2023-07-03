#include <bits/stdc++.h>
using namespace std;

int sz = 0;
int mx_sz = 5;
queue<int> buffer;
mutex buffer_lock;

mutex consumer_lock, producer_lock;

void consumer(int id) {
  int cnt = 0;
  do {
    consumer_lock.lock();
    while (sz == 0)
      ;
    buffer_lock.lock();
    sz--;
    buffer.pop();
    cout << "consumer " << id << " read and size is " << sz << endl;
    this_thread::sleep_for(0.5s);
    buffer_lock.unlock();
    consumer_lock.unlock();
  } while (cnt++ < 10);
}

void producer(int id) {
  int cnt = 0;
  do {
    producer_lock.lock();
    while (sz == mx_sz)
      ;
    buffer_lock.lock();
    sz++;
    buffer.push(id);
    cout << "producer " << id << " wrote and size is " << sz << endl;
    this_thread::sleep_for(0.5s);
    buffer_lock.unlock();
    producer_lock.unlock();
  } while (cnt++ < 10);
}

int main() {
  thread consumers[5], producers[5];
  for (int i = 0; i < 5; i++) {
    consumers[i] = thread(consumer, i);
    producers[i] = thread(producer, i);
  }

  // wait for threads
  for (int i = 0; i < 5; i++) {
    consumers[i].join();
    producers[i].join();
  }
  return 0;
}