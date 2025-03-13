#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    MaxHeap() : m_sz(0) {}

    MaxHeap(const vector<int>& v) : m_sz(v.size()) , m_arr(v) {
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    int extract_top() {
        if (m_sz == 0) return -1;
        int el = m_arr[0];

        m_arr[0] = m_arr[m_sz - 1];
        m_arr.pop_back();
        m_sz--;

        heapify_down(0);

        return el;
    }

    void insert(int el) {
        m_arr.push_back(el);
        m_sz++;
        heapify_up(m_sz - 1);
    }

    int top() {
        if (m_sz == 0) return -1;
        return m_arr[0];
    }

    int size() {
        return m_sz;
    }

    bool empty() {
        return m_sz == 0;
    }

private:
    vector<int> m_arr;
    int m_sz;

    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent = (ind - 1) / 2;
        if (m_arr[parent] < m_arr[ind]) {
            swap(m_arr[parent] , m_arr[ind]);
            heapify_up(parent);
        }
    }

    void heapify_down(int ind) {
        int largest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        if (left<m_sz && m_arr[left]>m_arr[largest]) {
            largest = left;
        }
        if (right<m_sz && m_arr[right]>m_arr[largest]) {
            largest = right;
        }
        if (largest != ind) {
            swap(m_arr[largest] , m_arr[ind]);
            heapify_down(largest);
        }
    }
};

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    vector<int> v;
    for (int i = 0; i < 1e5;i++) v.push_back(i);
    MaxHeap h(v);
    while (!h.empty()) {
        h.extract_top();
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = end_time - start_time;
    cout << "Time taken by custom heap: " << duration.count() << endl;

    start_time = chrono::high_resolution_clock::now();
    priority_queue<int> pq;
    for (int i = 0; i < 1e5;i++) pq.push(i);
    while (!pq.empty()) {
        pq.pop();
    }
    end_time = chrono::high_resolution_clock::now();
    duration = end_time - start_time;
    cout << "Time taken by pq: " << duration.count() << endl;
    return 0;
}