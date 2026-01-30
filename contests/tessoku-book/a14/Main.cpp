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
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// ---- constants ----
constexpr int INF = numeric_limits<int>::max() / 4;
constexpr ll LINF = numeric_limits<ll>::max() / 4;

// ---- macros ----
#define rep(i, x, limit) for (ll i = (ll)(x); i < (ll)(limit); i++)
#define REP(i, x, limit) for (ll i = (ll)(x); i <= (ll)(limit); i++)
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
  int n, k;
  cin >> n >> k;

  vll a = read_vec<ll>(n);
  vll b = read_vec<ll>(n);
  vll c = read_vec<ll>(n);
  vll d = read_vec<ll>(n);

  // 箱A, 箱Bからそれぞれ一枚選んだときの合計値のパターンを管理する配列P
  vll p(n * n, 0);
  int index1 = 0;
  rep(i, 0, n) {
    rep(j, 0, n) {
      p[index1] = a[i] + b[j];
      index1++;
    }
  }

  // 箱C, 箱Dからそれぞれ一枚選んだときの合計値のパターンを管理する配列Q
  vll q(n * n, 0);
  int index2 = 0;
  rep(i, 0, n) {
    rep(j, 0, n) {
      q[index2] = c[i] + d[j];
      index2++;
    }
  }

  // 配列Qをソート
  sort(all(q));

  // 二分探索で、k-p[i]がqに存在するかどうかを探索する
  rep(i, 0, p.size()) {
    ll target = k - p[i];
    if (binary_search(all(q), target)) {
      Yes();
      return;
    }
  }
  No();
}

// ---- main ----
int main() {
  solve();
  return 0;
}
