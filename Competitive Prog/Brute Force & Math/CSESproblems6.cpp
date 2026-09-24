#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	int N;
	cin >> N;

	vector<pair<ll, ll> > A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	for (int i = 0; i < N; i++) {
		ll y = A[i].first;
		ll x = A[i].second;
		ll n = max(x, y);
		ll n2 = n * n;
		ll ans;

		if (n % 2 == 0) {
			if (y == n)
				ans = n2 - x + 1;
			else
				ans = (n - 1) * (n - 1) + y;
		} else {
			if (x == n)
				ans = n2 - y + 1;
			else
				ans = (n - 1) * (n - 1) + x;
		}
		
		cout << ans << '\n';
	}

	return 0;
}

