#include <algorithm>
#include <atcoder/all>
#include <bits/stdc++.h>
#include <map>

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
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using maxpq = priority_queue<T>;
template <class T> using minpq = priority_queue<T, vector<T>, greater<T>>;

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

// ---- direction ----
enum Dir4 { DOWN, RIGHT, UP, LEFT, DIR4_CNT };
enum Dir8 { D, DR, R, UR, U, UL, L, DL, DIR8_CNT };
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// ---- helpers ----
inline void Yes() { cout << "Yes" << el; }
inline void No() { cout << "No" << el; }
inline void YES() { cout << "YES" << el; }
inline void NO() { cout << "NO" << el; }
inline void print_double(double x, int n = 10) {
  cout << fixed << setprecision(n) << x << el;
}

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

// ---- problem functions ----

// ---- solve ----
static void solve() {
  int n;
  cin >> n;

  vi t = read_vec<int>(n);

  map<int, int> m;

  rep(i, 0, n) { m[t[i]] = i + 1; }

  sort(all(t));

  rep(i, 0, 3) {
    cout << m[t[i]];
    if (i == 2) {
      cout << el;
    } else {
      cout << " ";
    }
  }
}

// ---- main ----
int main() {
  solve();
  return 0;
}
