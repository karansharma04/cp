#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int shared_num = 1;

int reader_cnt = 0;
mutex reader_cnt_mutex;

binary_semaphore rw(1);

mutex cout_mutex;

void reader(int id) {
    while (true) {
        reader_cnt_mutex.lock();
        reader_cnt++;
        if (reader_cnt == 1) {
            rw.acquire();
        }
        reader_cnt_mutex.unlock();
        // reading
        cout_mutex.lock();
        cout << "Reading haha: " << shared_num << ", reader_count: " << reader_cnt << endl;
        cout_mutex.unlock();
        reader_cnt_mutex.lock();
        reader_cnt--;
        if (reader_cnt == 0) {
            rw.release();
        }
        reader_cnt_mutex.unlock();
        sleep(3);
    }
}

void writer(int id) {
    while (true) {
        rw.acquire();
        // writing
        shared_num++;
        cout_mutex.lock();
        cout << "Writing haha: " << shared_num << endl;
        cout_mutex.unlock();
        rw.release();
        sleep(1);
    }
}

int main() {
    thread readers[] = { thread(reader, 1), thread(reader, 2) ,  thread(reader, 3) ,  thread(reader, 4) };
    thread writers[] = { thread(writer, 1), thread(writer, 2) };
    for (int i = 0;i < 4;i++) readers[i].join();
    for (int i = 0;i < 2;i++) writers[i].join();
    return 0;
}