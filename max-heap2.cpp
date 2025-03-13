#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    MaxHeap() {}
    MaxHeap(vector<int>& v) : arr(v) {
        int sz = arr.size();
        for (int i = sz / 2;i >= 0;i--) {
            heapify_down(i);
        }
    }
    int extract_top() {
        int top_el = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        heapify_down(0);
        return top_el;
    }
    void push(int el) {
        arr.push_back(el);
        heapify_up(arr.size() - 1);
    }
    int size() {
        return arr.size();
    }
private:
    void heapify_up(int ind) {
        if (ind == 0) return;
        int parent = (ind - 1) / 2;
        if (arr[parent] < arr[ind]) {
            swap(arr[parent] , arr[ind]);
            heapify_up(parent);
        }
    }
    void heapify_down(int ind) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int largest = ind;
        if (left<arr.size() && arr[left]>arr[largest]) {
            largest = left;
        }
        if (right<arr.size() && arr[right]>arr[largest]) {
            largest = right;
        }
        if (largest == ind) return;
        swap(arr[largest] , arr[ind]);
        heapify_down(largest);
    }
    vector<int> arr;
};

int main() {
    // vector<int> v;
    MaxHeap h;
    for (int i = 0;i < 10;i++) {
        h.push(rand() % 100);
    }
    // MaxHeap h(v);
    while (h.size()) {
        cout << h.extract_top() << endl;
    }
    return 0;
}