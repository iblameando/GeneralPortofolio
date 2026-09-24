#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ll p, q, r; cin >> p >> q >> r;
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % p == 0 && a[i] % q == 0 && a[i] % r == 0) {
			cout << "YA\n";
		} else {
			cout << "TIDAK\n";
		}
	}
}
