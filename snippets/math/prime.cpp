#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
 * 素数判定
 * O(sqrt(n))
 */
bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n % 2 == 0)
    return false;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 2) {
      return false;
    }
  }
  return true;
}

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
