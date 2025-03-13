#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

const int BUFFER_SIZE = 5;

counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);
counting_semaphore<BUFFER_SIZE> taken_slots(0);
vector<int> buffer;
mutex buffer_mutex;

void producer(int id) {
    int num;
    while (true) {
        num = rand() % 100;
        empty_slots.acquire();
        // produce
        buffer_mutex.lock();
        buffer.push_back(num);
        cout << "Produced " << num << endl;
        cout << "current buffer after producing: ";
        for (auto x : buffer) cout << x << ' ';
        cout << endl;
        sleep(2);
        buffer_mutex.unlock();
        taken_slots.release();
    }
}

void consumer(int id) {
    while (true) {
        taken_slots.acquire();
        // consume
        buffer_mutex.lock();
        int num = buffer[buffer.size() - 1];
        buffer.pop_back();
        cout << "Consumed " << num << endl;
        cout << "current buffer after consuming: ";
        for (auto x : buffer) cout << x << ' ';
        cout << endl;
        sleep(2);
        buffer_mutex.unlock();
        empty_slots.release();
    }
}

int main() {
    thread producers[] = { thread(producer, 1), thread(producer,2) , thread(producer, 3) , thread(producer, 4) };
    thread consumers[] = { thread(consumer, 1), thread(consumer,2) };

    for (int i = 0;i < 4;i++) producers[i].join();
    for (int i = 0;i < 2;i++) consumers[i].join();
    return 0;
}