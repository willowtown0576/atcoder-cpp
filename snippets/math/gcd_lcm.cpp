#include <bits/stdc++.h>

using namespace std;

/**
 * 最大公約数
 */
int gcd(int a, int b) {
  while (a >= 1 && b >= 1) {
    if (a >= b) {
      a = (a % b);
    } else {
      b = (b % a);
    }
  }
  if (a != 0)
    return a;
  return b;
}

/**
 * 最小公倍数
 */
int lcm(int a, int b) { return a * b / gcd(a, b); }
