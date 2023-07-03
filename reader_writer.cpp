#include <bits/stdc++.h>
using namespace std;

int reader_count = 0;
mutex rw_lock;
mutex r_lock;

mutex cout_lock;

int writer_interest = 0;
mutex writer_interest_lock;

void reader(int id) {
  for (int i = 0; i < 3; i++) {
    r_lock.lock();
    while(writer_interest>0);
    if (reader_count == 0) {
      rw_lock.lock();
    }
    reader_count++;
    r_lock.unlock();

    // reading
    this_thread::sleep_for(0.5s);
    cout_lock.lock();
    cout << "reader " << id << " is reading along with " << reader_count
         << " others." << endl;
    cout_lock.unlock();

    r_lock.lock();
    reader_count--;
    if (reader_count == 0) rw_lock.unlock();
    r_lock.unlock();
  }
}

void writer(int id) {
  for (int i = 0; i < 3; i++) {
    writer_interest_lock.lock();
    writer_interest++;
    writer_interest_lock.unlock();

    rw_lock.lock();

    // writing
    this_thread::sleep_for(0.5s);
    cout_lock.lock();
    cout << "writer " << id << " is writing" << endl;
    cout_lock.unlock();

    rw_lock.unlock();

    writer_interest_lock.lock();
    writer_interest--;
    writer_interest_lock.unlock();
  }
}

int main() {
  thread readers[5], writers[5];
  for (int i = 0; i < 5; i++) {
    readers[i] = thread(reader, i);
    writers[i] = thread(writer, i);
  }

  for (int i = 0; i < 5; i++) {
    readers[i].join();
    writers[i].join();
  }
  return 0;
}