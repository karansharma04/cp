#include <bits/stdc++.h>
using namespace std;

bool dfs(int curr , vector<bool>& vis , vector<bool>& live_vis , const vector<vector<int>>& adjl , vector<int>& top_order) {
    vis[curr] = true;
    live_vis[curr] = true;
    for (auto x : adjl[curr]) {
        if (!vis[x]) {
            if (!dfs(x , vis , live_vis , adjl , top_order)) return false;
        }
        else {
            if (live_vis[x]) return false;
        }
    }
    top_order.push_back(curr);
    live_vis[curr] = false;
    return true;
}

int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0;i < m;i++) {
        int u , v;
        cin >> u >> v;
        adjl[u].push_back(v);
    }
    vector<int> top_order;
    vector<bool> vis(n + 1 , false) , live_vis(n + 1 , false);
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            if (!dfs(i , vis , live_vis , adjl , top_order)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    reverse(top_order.begin() , top_order.end());
    for (auto x : top_order) cout << x << ' ';
    cout << '\n';
    return 0;
}