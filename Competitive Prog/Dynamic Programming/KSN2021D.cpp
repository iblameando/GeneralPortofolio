#include <bits/stdc++.h>
using namespace std;
#define ll long long

// KSN 2021 D - Max Vitamin Value
// Dynamic programming solution for the vitamin optimization problem.

int main () {
    ll n, m; 
    cin >> n >> m;

    vector<ll> dp(m + 1, 0); // dp[i] = maximum value using budget i

    while (n--) {
        int h, k, d; 
        cin >> h >> k >> d;

        if (d == 1) {
            // 0/1 knapsack: iterate backward to avoid reusing the same item.
            for (int j = m; j >= h; j--) {
                dp[j] = max(dp[j], dp[j - h] + k);
            }
        } else {
            // Unbounded knapsack: iterate forward to allow multiple uses of the same item.
            for (int j = h; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - h] + k);
            }
        }
    }

    cout << dp[m] << endl;
    return 0;
}

