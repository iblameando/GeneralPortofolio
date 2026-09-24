#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define hatsune ios::sync_with_stdio(0);
#define miku cin.tie(0);

int main() {
	hatsune miku

    int n;
    cin >> n;

    vector<ll> f(n + 1);

    f[0] = 0;
    if (n >= 1) f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    for (int i = 0; i <= n; i++) {
        cout << f[i] << " ";
    }
}

