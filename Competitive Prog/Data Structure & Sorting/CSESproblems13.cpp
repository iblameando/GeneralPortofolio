#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int total = 1 << n;

    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1);
        for (int j = n - 1; j >= 0; j--) {
            cout << ((gray >> j) & 1);
        }
        cout << '\n';
    }
}

