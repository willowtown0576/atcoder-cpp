FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

# ============================================================
# 基本パッケージ + Python + 各種ツール（補完など）
# ============================================================
RUN apt-get update && apt-get install -y \
    curl wget git unzip \
    build-essential software-properties-common \
    ca-certificates gnupg lsb-release tzdata \
    python3 python3-pip python3-venv \
    make \
    time \
    gdb clang-format \
    bash-completion \
    less \
    && rm -rf /var/lib/apt/lists/*

# clangd を新しくする（clangd-18）
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor > /usr/share/keyrings/llvm.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/llvm.gpg] http://apt.llvm.org/jammy/ llvm-toolchain-jammy-18 main" \
    > /etc/apt/sources.list.d/llvm.list

RUN apt-get update && apt-get install -y clangd-18 \
    && update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-18 180 \
    && rm -rf /var/lib/apt/lists/*

# ============================================================
# bash補完・操作性向上（Tab補完・履歴）
# ============================================================
RUN cat <<'EOF' >> /etc/bash.bashrc

# ===== bash completion (enabled by default) =====
if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
fi

# ===== history =====
export HISTCONTROL=ignoreboth
export HISTSIZE=100000
export HISTFILESIZE=200000
shopt -s histappend
EOF

# ============================================================
# プロンプト設定
# 例: root@devcontainer:/workspace/contests/abc350/a $
# ============================================================
RUN cat <<'EOF' >> /etc/bash.bashrc

# ===== colored prompt =====
export PS1="\[\e[32m\]\u@\h\[\e[0m\]:\[\e[34m\]\w\[\e[0m\] \$ "
EOF

# ============================================================
# --- C++23設定：g++-13 ---
# ============================================================
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test \
    && apt-get update && apt-get install -y g++-13 gcc-13 \
    && rm -rf /var/lib/apt/lists/*

# g++/gccのデフォルトを13に
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 130 \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 130

# ============================================================
# Node.js 18.x（acc用）
# ============================================================
RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash - \
    && apt-get update && apt-get install -y nodejs \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

# ============================================================
# atcoder-cli / online-judge-tools / aclogin
# ============================================================
RUN npm install -g atcoder-cli \
    && pip3 install --no-cache-dir online-judge-tools aclogin

# ============================================================
# （任意）AtCoder Library
# ============================================================
RUN git clone --depth 1 https://github.com/atcoder/ac-library.git /opt/ac-library \
    && ln -s /opt/ac-library/atcoder /usr/local/include/atcoder

# ============================================================
# acc 設定ディレクトリ / テンプレ
# ============================================================
RUN mkdir -p /root/.config/atcoder-cli-nodejs/cpp

COPY <<'EOF' /root/.config/atcoder-cli-nodejs/cpp/template.json
{
  "task": {
    "program": ["Main.cpp"],
    "submit": "Main.cpp",
    "testdir": "test",
    "cmd": "ln -sf /workspace/Makefile Makefile"
  }
}
EOF

COPY <<'EOF' /root/.config/atcoder-cli-nodejs/cpp/Main.cpp
#include <atcoder/all>
#include <bits/stdc++.h>

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
inline void Yes(){ cout << "Yes\n"; }
inline void No(){ cout << "No\n"; }
inline void YES(){ cout << "YES\n"; }
inline void NO(){ cout << "NO\n"; }

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
  // TODO: write your solution here
}

// ---- main ----
int main() {
  solve();
  return 0;
}
EOF

RUN acc config default-task-choice all
RUN acc config default-template cpp

CMD ["/bin/bash", "-l"]
