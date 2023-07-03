#include <bits/stdc++.h>
using namespace std;

class MinHeap {
  vector<int> m_arr;
  int m_sz;
  public:
  MinHeap(vector<int> arr) {
    m_sz = arr.size();
    m_arr = arr;
    for(int i=m_sz/2;i>=0;i--) {
      heapify(i);
    }
  }
  void heapify(int ind) {
    int min_ind = ind;
    if(2*ind+1<m_sz) {
      if(m_arr[2*ind+1]<m_arr[ind]) {
        min_ind = 2*ind+1;
      }
    }
    if(2*ind+2<m_sz) {
      if(m_arr[2*ind+2]<m_arr[min_ind]) {
        min_ind = 2*ind+2;
      }
    }
    if(min_ind!=ind) {
      swap(m_arr[min_ind], m_arr[ind]);
      heapify(min_ind);
    }
  }
  int getSize() {
    return m_sz;
  }
  int extractTop() {
    int tp = m_arr[0];
    deleteElement(0);
    return tp;
  }
  void deleteElement(int ind) {
    swap(m_arr[ind], m_arr[m_sz-1]);
    m_sz--;
    heapify(ind);
  }
};


int main() {
  MinHeap m_heap({4, 1, 3, 2, 3,  5});
  while(m_heap.getSize()) {
    cout<<m_heap.extractTop()<<' ';
  }
  cout<<endl;
  return 0;
} 