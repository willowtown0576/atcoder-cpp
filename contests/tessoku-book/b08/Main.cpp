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
  int n;
  cin >> n;

  vector<vector<int>> grid(1502, vector<int>(1502, 0));
  rep(i, 0, n) {
    int x, y;
    cin >> x >> y;

    grid[x][y]++;
  }

  vector<vector<int>> acc(1502, vector<int>(1502, 0));

  // 横方向に累積和を取る
  REP(i, 1, 1500) {
    REP(j, 1, 1500) { acc[i][j] = acc[i][j - 1] + grid[i][j]; }
  }

  // 縦方向に累積和を取る
  REP(j, 1, 1500) {
    REP(i, 1, 1500) { acc[i][j] = acc[i - 1][j] + acc[i][j]; }
  }

  // 答え
  int q;
  cin >> q;

  rep(i, 0, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << acc[c][d] + acc[a - 1][b - 1] - acc[c][b - 1] - acc[a - 1][d] << el;
  }
}

// ---- main ----
int main() {
  solve();
  return 0;
}
