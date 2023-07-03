#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fi first
#define se second
#define ld long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define vi vector<ll>
#define pi pair<ll, ll>
#define vpi vector<pi>
#define vvi vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>

int MOD = 998244353;
#define PI 3.1415926535897932384626433832
// pi = 2*acos(0.0);

bool debugging = false;
#define Cerr        \
  if (!debugging) { \
  } else            \
    cerr
#define deb(x) Cerr << #x << "=" << x << "\n";
#define dar(a, n)                                               \
  Cerr << #a << "="                                             \
       << "{";                                                  \
  for (int i = 0; i < n; i++) Cerr << a[i] << ",}"[i == n - 1]; \
  Cerr << "\n";
#define dv(v)                                                          \
  Cerr << #v << "="                                                    \
       << "{";                                                         \
  for (int i = 0; i < n; i++) Cerr << v[i] << ",}"[i == v.size() - 1]; \
  Cerr << "\n";

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

ll powerWithoutModulus(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return (powerWithoutModulus((a * a), b / 2));  // binary exponentiation
  else
    return (powerWithoutModulus((a * a), b / 2) * a);
}

ll powerWithModulus(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return (powerWithModulus((a * a) % MOD, b / 2)) % MOD;
  else
    return (powerWithModulus((a * a) % MOD, b / 2) * a) % MOD;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void swap(int& a, int& b) {
  int t = b;
  b = a;
  a = t;
}

ll inv_mod(ll n) { return powerWithModulus(n, MOD - 2); }

//*************************************************************************

void test() {
  int n; cin>>n;
  vector<vector<int>> a(n, vector<int> (2));
  for(int i=0;i<n;i++) cin>>a[i][0];
  for(int i=0;i<n;i++) cin>>a[i][1];
  sort(a.begin(), a.end());
  map<vi, int> f;
  set<int> s;
  for(auto x: a) {
    f[x]++;
    s.insert(x[0]);
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    f[a[i]]--;
    int up_lim = (2*n)/a[i][0] + 1;
    auto it = s.lower_bound(a[i][0]);
    while(it!=s.end() && *it<=up_lim) {
      int num = a[i][0]*(*it) - a[i][1];
      if(f.find({*it, num})!=f.end()) ans += f[{*it, num}];
      it++;
    }
  }
  cout<<ans<<'\n';
}

bool multipleTests = true;

int32_t main() {
#ifndef ONLINE_JUDGE
  debugging = true;
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  if (multipleTests) cin >> t;
  for (int i = 1; i <= t; i++) {
    test();
  }
  return 0;
}
