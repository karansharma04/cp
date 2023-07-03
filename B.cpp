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

int MOD = 1e9 + 7;
#define PI 3.1415926535897932384626433832
// pi = 2*acos(0.0);

bool debugging = false;
#define Cerr        \
  if (!debugging) { \
  } else            \
    cerr
#define deb(x) Cerr << #x << "=" << x << "\n";
#define darr(a, n)                                              \
  Cerr << #a << "="                                             \
       << "{";                                                  \
  for (int i = 0; i < n; i++) Cerr << a[i] << ",}"[i == n - 1]; \
  Cerr << "\n";
#define dv(v)                                                                 \
  Cerr << #v << "="                                                           \
       << "{";                                                                \
  for (int i = 0; i < v.size(); i++) Cerr << v[i] << ",}"[i == v.size() - 1]; \
  Cerr << "\n";

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int powerWithoutModulus(int n, int p) {
  if (p == 0) return 1;
  int res = powerWithoutModulus(n * n, p / 2);
  if (p % 2) res *= n;
  return res;
}

int powerWithModulus(int n, int p) {
  if (p == 0) return 1;
  int res = powerWithModulus((n * n) % MOD, p / 2);
  if (p % 2) res = (res * n) % MOD;
  return res;
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

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

//****************************************************************************************

void test(int tc) {
  cout<<"hello world\n";
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
    test(i);
  }
  return 0;
}

/*

*/
