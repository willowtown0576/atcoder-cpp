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
  int mid = n / 2;

  // 配列aを前半、後半の二つに分けて、それぞれのカードの合計値のパターンを全列挙する

  // 前半
  vll p((1 << mid), 0);
  int index1 = 0;
  rep(bit, 0, (1 << mid)) {
    ll sum = 0;
    rep(i, 0, mid) {
      if (bit & (1 << i)) {
        sum += a[i];
      }
    }
    p[index1] = sum;
    index1++;
  }

  // 後半
  vll q((1 << (n - mid)), 0);
  int index2 = 0;
  rep(bit, 0, (1 << (n - mid))) {
    ll sum = 0;
    rep(i, mid, n) {
      if (bit & (1 << (i - mid))) {
        sum += a[i];
      }
    }
    q[index2] = sum;
    index2++;
  }

  // 後半用配列Qをソート（二分探索のため）
  sort(all(q));

  // k - p[i]がqに存在するかをチェックする。
  rep(i, 0, (1 << mid)) {
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
