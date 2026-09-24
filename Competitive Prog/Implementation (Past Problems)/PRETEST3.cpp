#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll damage(const vector<ll>& a, ll k) {
    ll total = 0;
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        total += min(k, a[i + 1] - a[i]);
    }
    total += k;
    return total;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll left = 1, right = h, ans = h;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (damage(a, mid) >= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

