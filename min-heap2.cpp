#include<bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    MinHeap() {}
    MinHeap(vector<int>& v) : arr(v) {
        int sz = arr.size();
        for (int i = sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }
    int extract_top() {
        int tp = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        heapify_down(0);
        return tp;
    }
    void push(int el) {
        arr.push_back(el);
        heapify_up(arr.size() - 1);
    }
    int size() {
        return arr.size();
    }
private:
    void heapify_down(int ind) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int smallest = ind;
        if (left < arr.size() && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < arr.size() && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest == ind) return;
        swap(arr[smallest] , arr[ind]);
        heapify_down(smallest);
    }
    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent = (ind - 1) / 2;
        if (arr[parent] > arr[ind]) {
            swap(arr[parent] , arr[ind]);
            heapify_up(parent);
        }
    }
    vector<int> arr;
};

int main() {
    vector<int> v;
    for (int i = 0;i < 1e5;i++) v.push_back(i);
    auto start = chrono::high_resolution_clock::now();
    MinHeap pq(v);
    while (pq.size()) {
        pq.extract_top();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    cout << "Time taken by custom heap: " << duration.count() << endl;
    start = chrono::high_resolution_clock::now();
    for (int i = 0;i < 1e5;i++) v.push_back(i);
    priority_queue<int> q(v.begin() , v.end());
    while (q.size()) {
        q.pop();
    }
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Time taken by built-in pq: " << duration.count() << endl;
    return 0;
}