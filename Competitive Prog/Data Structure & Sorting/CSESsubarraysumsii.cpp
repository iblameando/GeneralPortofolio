#include <bits/stdc++.h>
#define ll long long
using namespace std;

// CSES - Subarray Sum II
// Count subarrays with sum x using prefix sums.
// prefix[i] - prefix[j] = x means subarray j+1..i has sum x.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<ll, ll> mp; // prefix sum -> how many times it appears
    ll sum = 0, ans = 0;
    mp[0] = 1; // empty prefix sum before the array starts

    for (int i = 0; i < n; i++) {
        sum += a[i];

        // Count previous prefix sums such that prefix[i] - prefix[j] = x
        if (mp.count(sum - x)) {
            ans += mp[sum - x];
        }

        mp[sum]++; // add current prefix sum to the map
    }

    cout << ans << "\n";
    return 0;
}

