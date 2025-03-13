#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int sz = 1e6;

int seg_tree[sz];

void build_tree(int l, int r, int ind, vector<int>& a) {
  if (l > r)
    return;
  if (l == r) {
    seg_tree[ind] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build_tree(l, mid, 2 * ind, a);
  build_tree(mid + 1, r, 2 * ind + 1, a);
  seg_tree[ind] = min(seg_tree[2 * ind], seg_tree[2 * ind + 1]);
}

int query(int l, int r, int tl, int tr, int ind) {
  if (l > r)
    return INT_MAX;
  if (tl >= l && tr <= r) {
    return seg_tree[ind];
  }
  int t_mid = (tl + tr) / 2;
  int op1 = query(l, min(r, t_mid), tl, t_mid, 2 * ind);
  int op2 = query(max(l, t_mid + 1), r, t_mid + 1, tr, 2 * ind + 1);
  return min(op1, op2);
}

void update(int i, int val, int tl, int tr, int ind) {
  if (tl > tr)
    return;
  if (tl == tr) {
    seg_tree[ind] = val;
    return;
  }
  int t_mid = (tl + tr) / 2;
  if (i <= t_mid) {
    update(i, val, tl, t_mid, 2 * ind);
  } else {
    update(i, val, t_mid + 1, tr, 2 * ind + 1);
  }
  seg_tree[ind] = min(seg_tree[2 * ind], seg_tree[2 * ind + 1]);
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build_tree(0, n - 1, 1, a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int ind, val;
      cin >> ind >> val;
      ind--;
      update(ind, val, 0, n - 1, 1);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << query(l, r, 0, n - 1, 1) << endl;
    }
  }
  return 0;
}
