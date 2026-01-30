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
  vi a = read_vec<int>(n);

  // 問題の制約より最小が1秒、最大が1000000000秒として、その範囲で印刷された紙の枚数を二分探索で求めていく。
  int l = 1, r = 1'000'000'000;
  while (l < r) {
    int mid = (l + r) / 2;

    ll sum = 0;
    // mid秒までに印刷された紙の枚数は、
    // `mid秒 / その印刷機の印刷ペース`で求められる。
    // すべてのaについてそれを計算し、合算する。
    rep(i, 0, n) { sum += mid / a[i]; }

    // mid秒までに印刷された紙の総数sumが、目標とするk枚以上であれば、r=midとして次のループへ。
    // 二分探索の左側を次の探索先にするイメージ。
    if (sum >= k) {
      r = mid;
    } else {
      // sumがk未満であれば、mid秒ではk枚以上印刷できなかったということ。
      // l=mid+1で、二分探索の右側を次の探索先にするイメージ。
      l = mid + 1;
    }
  }

  // ここまでくるとl=rになっているはずなので、それが答え。
  cout << l << el;
}

// ---- main ----
int main() {
  solve();
  return 0;
}
