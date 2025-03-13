#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    MinHeap() : m_sz(0) {
        cout << "Default constructor called!" << endl;
    }
    MinHeap(const int* arr , int sz) : m_sz(sz) {
        m_arr = new int[100];
        for (int i = 0;i < sz;i++) {
            m_arr[i] = arr[i];
        }
        cout << "Param Constructor called!" << endl;
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    MinHeap(const MinHeap& other) : m_sz(other.m_sz) {
        cout << "Copy Constructor called!" << endl;
        m_arr = new int[100];
        for (int i = 0;i < other.m_sz; i++) {
            m_arr[i] = other.m_arr[i];
        }
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    void operator=(const MinHeap& other) {
        m_sz = other.m_sz;
        cout << "Copy assignment operator called!" << endl;
        m_arr = new int[100];
        for (int i = 0;i < other.m_sz; i++) {
            m_arr[i] = other.m_arr[i];
        }
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    MinHeap(MinHeap&& other) : m_sz(other.m_sz) {
        cout << "Move Constructor called!" << endl;
        m_arr = other.m_arr;
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    void operator=(MinHeap&& other) {
        m_sz = other.m_sz;
        cout << "Move assignment operator called!" << endl;
        m_arr = other.m_arr;
        other.m_arr = nullptr;
        other.m_sz = 0;
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    void insert(int el) {
        m_sz++;
        heapify_up(m_sz - 1);
    }

    int extract_top() {
        if (m_sz == 0) return -1;
        int el = m_arr[0];
        swap(m_arr[0] , m_arr[m_sz - 1]);
        m_sz--;
        heapify_down(0);
        return el;
    }

    int top() const {
        if (m_sz == 0) throw out_of_range("Heap is empty");
        return m_arr[0];
    }

    int size() const {
        return m_sz;
    }

    bool empty() const {
        return m_sz == 0;
    }

    ~MinHeap() {
        cout << "Destructor called" << endl;
        delete[] m_arr;
    }
private:
    int* m_arr;
    int m_sz;

    void heapify_down(int ind) {
        int smallest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        if (left < m_sz && m_arr[left] < m_arr[smallest]) {
            smallest = left;
        }
        if (right < m_sz && m_arr[right] < m_arr[smallest]) {
            smallest = right;
        }
        if (smallest != ind) {
            swap(m_arr[ind] , m_arr[smallest]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent = (ind - 1) / 2;
        if (m_arr[parent] > m_arr[ind]) {
            swap(m_arr[parent] , m_arr[ind]);
            heapify_up(parent);
        }
    }
};

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    int arr[10];
    for (int i = 0;i < 10;i++) arr[i] = i;
    MinHeap h;
    cout << "next up is assignment" << endl;
    h = MinHeap(arr , 10);
    while (!h.empty()) {
        cout << h.extract_top() << endl;
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = end_time - start_time;
    start_time = chrono::high_resolution_clock::now();
    cout << "Time taken by custom min-heap: " << duration.count() << endl;
    return 0;
}