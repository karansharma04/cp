#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

// reader - writer 

int shared_mem = 101;

int reader_cnt = 0;
mutex reader_cnt_mutex;

binary_semaphore rw(1);

mutex cout_mutex;

binary_semaphore writer_interest(0);

void reader(int id) {
    while (true) {
        writer_interest.acquire();
        reader_cnt_mutex.lock();
        reader_cnt++;
        if (reader_cnt == 1) {
            rw.acquire();
        }
        reader_cnt_mutex.unlock();
        writer_interest.release();
        cout_mutex.lock();
        cout << "Reading by " << id << " underway! Read: " << shared_mem << endl;
        cout_mutex.unlock();
        reader_cnt_mutex.lock();
        reader_cnt--;
        if (reader_cnt == 0) {
            rw.release();
        }
        reader_cnt_mutex.unlock();
        sleep(2);
    }
}

void writer(int id) {
    while (true) {
        writer_interest.acquire();
        rw.acquire();
        shared_mem++;
        cout << "Writing by " << id << " underway! Written: " << shared_mem << endl;
        rw.release();
        sleep(2);
        writer_interest.release();
    }
}

int main() {
    thread readers[] = { thread(reader, 1), thread(reader, 2), thread(reader, 3), thread(reader, 4) };
    thread writers[] = { thread(writer, 1), thread(writer, 2) };

    for (int i = 0;i < 4;i++) readers[i].join();
    for (int i = 0;i < 2;i++) writers[i].join();
    return 0;
}