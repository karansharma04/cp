#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

vector<int> buffer;
mutex buffer_mutex;

const int BUFFER_SIZE = 5;
counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);
counting_semaphore<BUFFER_SIZE> full_slots(0);


void producer(int id) {
    while (true) {
        empty_slots.acquire();
        int produce = id;
        buffer_mutex.lock();
        buffer.push_back(produce);
        cout << "Just Produced " << produce << endl;
        cout << "current buffer: ";
        for (auto x : buffer) cout << x << ' ';
        cout << endl;
        buffer_mutex.unlock();
        full_slots.release();
        sleep(2);
    }
}

void consumer(int id) {
    while (true) {
        full_slots.acquire();
        buffer_mutex.lock();
        cout << "Just Consumed " << buffer[buffer.size() - 1] << endl;
        buffer.pop_back();
        cout << "current buffer: ";
        for (auto x : buffer) cout << x << ' ';
        cout << endl;
        buffer_mutex.unlock();
        empty_slots.release();
        sleep(2);
    }
}

int main() {
    thread producers[] = { thread(producer, 1), thread(producer, 2) };
    thread consumers[] = { thread(consumer, 1), thread(consumer, 2) };
    for (int i = 0;i < 2;i++) {
        producers[i].join();
        consumers[i].join();
    }
    return 0;
}