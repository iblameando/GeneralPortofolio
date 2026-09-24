#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long B, C, D;
    cin >> B >> C >> D;

    // Case 1: Impossible because remainder can't be bigger than the dividend
    if (D > C) {
        cout << 0;
        return 0;
    }

    // Case 2: If remainder == C, that means:
    // C % n = C  only happens if n > C.
    // So all integers > C up to B are valid.
    if (C == D) {
        cout << max(0LL, B - C);
        return 0;
    }

    // diff = C - D. We know that if C % n = D, then:
    // C - D is divisible by n  (i.e., n divides diff)
    long long diff = C - D;

    vector<long long> divisors;

    // We only need to find divisors of 'diff',
    // and we can do it in O(sqrt(diff)) instead of O(B) to avoid TLE.
    for (long long i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            divisors.push_back(i);
            if (i != diff / i) divisors.push_back(diff / i);
        }
    }

    long long count = 0;
    for (long long n : divisors) {
        // n must be <= B (we cannot have more ducks than B)
        // and must satisfy the exact remainder condition.
        if (n <= B && C % n == D) {
            count++;
        }
    }

    cout << count;
    return 0;
}

