#include <algorithm>
#include <atcoder/all>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using namespace atcoder;

// ---- fast io & formatting ----
struct Init {
  Init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(13);
  }
} init;

// ---- aliases ----
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// ---- constants ----
constexpr int INF = numeric_limits<int>::max() / 4;
constexpr ll LINF = numeric_limits<ll>::max() / 4;

// ---- macros ----
#define rep(i, x, limit) for (ll i = (ll)(x); i < (ll)(limit); i++)
#define rrep(i, x, limit) for (ll i = (ll)(limit) - 1; i >= (ll)(x); i--)
#define REP(i, x, limit) for (ll i = (ll)(x); i <= (ll)(limit); i++)
#define RREP(i, x, limit) for (ll i = (ll)(limit); i >= (ll)(x); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el '\n'

// ---- debug ----
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << el
#else
#define debug(x) ((void)0)
#endif

// ---- helpers ----
inline void Yes() { cout << "Yes\n"; }
inline void No() { cout << "No\n"; }
inline void YES() { cout << "YES\n"; }
inline void NO() { cout << "NO\n"; }

template <class T> inline bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T> inline bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T> vector<T> read_vec(int n) {
  vector<T> v(n);
  for (auto &x : v)
    cin >> x;
  return v;
}

template <class T> void print_vec(const vector<T> &v, char sep = ' ') {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i)
      cout << sep;
    cout << v[i];
  }
  cout << el;
}

// ---- snippets paste zone ----

// ---- solve ----
static void solve() {
  int n;
  cin >> n;
  vi a = read_vec<int>(n);

  vi p(n + 1, 0);
  p[1] = a[0];
  REP(i, 2, n) { p[i] = max(p[i - 1], a[i - 1]); }

  vi q(n + 1, 0);
  q[n] = a[n - 1];
  RREP(i, 1, n - 1) { q[i] = max(q[i + 1], a[i - 1]); };

  // print_vec(p);
  // print_vec(q);

  int d;
  cin >> d;

  rep(i, 0, d) {
    int l, r;
    cin >> l >> r;
    cout << max(p[l - 1], q[r + 1]) << el;
  }
}

// ---- main ----
int main() {
  solve();
  return 0;
}
