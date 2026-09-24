// Math Movement in Steps of Five

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ll n; cin >> n;
	ll res = 0;
	// Finds the smallest multiple of five that is at least n.
	for (int i = 0; i < n; i+=5) {
		res += 5;
	}
	// Handles exact multiples of five separately.
	if ((res-n) == 0) {
		cout << 1;
	} else {
		cout << res - n;
	}
}
