#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<ll> kiamat;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll tahun = 0;
        for (int i = 0; i < n; i++) {
            tahun++;
            while (tahun % a[i] != 0) tahun++;
        }
        kiamat.push_back(tahun);
    }

    for (ll x : kiamat) cout << x << '\n';

    return 0;
}

