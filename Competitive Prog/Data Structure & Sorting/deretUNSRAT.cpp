#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Deret UNSRAT
// Reads n values, sums them, and prints each element as part of a simple sequence process.

int main () {
	ll n; cin >> n;
	ll sum = 0;
	vector<ll>a(n);
	priority_queue<ll>pq;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; i++) {
		pq.push(sum - a[i]);
		cout << a[i];
	}
}
