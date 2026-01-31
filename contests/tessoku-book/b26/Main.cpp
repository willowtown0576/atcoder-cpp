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
/**
 * エラトステネスの篩
 * O(n lot log n)
 */
vector<int> sieve(int n) {
  vector<bool> v(n + 1, true);
  v[0] = v[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (!v[i])
      continue;

    for (int j = i * i; j <= n; j += i) {
      v[j] = false;
    }
  }

  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (v[i])
      primes.push_back(i);
  }

  return primes;
}

// ---- solve ----
static void solve() {
  int n;
  cin >> n;

  using vi = vector<int>;

  vi primes = sieve(n);
  rep(i, 0, primes.size()) { cout << primes[i] << el; }
}

// ---- main ----
int main() {
  solve();
  return 0;
}
