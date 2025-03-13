#include <bits/stdc++.h>
using namespace std;

// arr[i], arr[2*i+1], arr[2*i+2]
template<typename T>
class MaxHeap {
public:
    MaxHeap() {
        m_sz = 0;
    }

    MaxHeap(const vector<T>& arr) : m_sz(arr.size()) , m_arr(arr) {
        for (int i = m_sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }

    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent_ind = (ind - 1) / 2;
        if (m_arr[parent_ind] < m_arr[ind]) {
            swap(m_arr[parent_ind] , m_arr[ind]);
            heapify_up(parent_ind);
        }
    }

    void heapify_down(int ind) {
        int largest_ind = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        if (left<m_sz && m_arr[left]>m_arr[largest_ind]) {
            largest_ind = left;
        }
        if (right<m_sz && m_arr[right]>m_arr[largest_ind]) {
            largest_ind = right;
        }
        if (largest_ind != ind) {
            swap(m_arr[largest_ind] , m_arr[ind]);
            heapify_down(largest_ind);
        }
    }

    void insert(T el) {
        if (m_arr.size() == m_sz) {
            m_arr.push_back(el);
            m_sz++;
        }
        else {
            m_sz++;
            m_arr[m_sz - 1] = el;
        }
        heapify_up(m_sz - 1);
    }

    T extract_top() {
        if (m_sz == 0) return -1;
        T top_el = m_arr[0];
        swap(m_arr[0] , m_arr[m_sz - 1]);
        m_arr.pop_back();
        m_sz--;
        heapify_down(0);
        return top_el;
    }

    T top() {
        if (m_sz == 0) return -1;
        return m_arr[0];
    }

    int size() {
        return m_sz;
    }

    ~MaxHeap() {
        m_sz = 0;
    }
private:
    vector<int> m_arr;
    int m_sz;
};

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    MaxHeap<char> h;
    for (int i = 0;i < 26;i++) h.insert('a' + i);
    while (h.size()) {
        cout << h.extract_top() << endl;
    }
    cout << endl;
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = end_time - start_time;
    cout << "Time taken by custom pq: " << duration.count() << endl;
    return 0;
}