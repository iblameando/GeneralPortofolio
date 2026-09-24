// Div & Conquer Algo

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000;

ll sapi(ll a, ll b) {
    // Keeps the product limited to its last six digits.
    return (a % MOD) * (b % MOD) % MOD;
}

ll modpow(ll base, ll exp) {
    // Computes the last six digits of base^exp efficiently.
    ll result = 1;
    base %= MOD;

    while (exp > 0) {
        // Includes the current power when the exponent bit is odd.
        if (exp % 2)
            result = sapi(result, base);
        // Squares the base for the next exponent bit.
        base = sapi(base, base);
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll A, B;
    cin >> A >> B;

    // Checks whether A^B has at least six digits.
    bool enam = (B * log10(A)) > 5.999;

    // Finds the last six digits of A^B.
    ll digits = modpow(A, B);

    if (enam) {
        // Adds leading zeroes when six digits are required.
        cout << setw(6) << setfill('0') << digits;
    } else {
        cout << digits;
    }
}

