#include <bits/stdc++.h>
#define hatsune ios::sync_with_stdio(0);
#define miku cin.tie(0);
#define ll long long
using namespace std;

int n;
ll a[100+5];

ll f(ll k) {
	ll damage = 0;
	for (int i = 1; i <= n; i++) {
		damage += min(a[i+1]-a[i],k);
	}
	
	damage += k;
	
	return damage;
}

int main () {
	hatsune miku
	
	int t; cin >> t;
	
	while (t--) {
		ll h;
		cin >> n >> h;
		
		ll a[n+1];
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		
		ll l = 1, r = 1e18;
		
		while (l > r) {
			ll mid = (l+r)/2;
			
			if (h > f(mid)) {
				l = mid+1;
			} else {
				r = mid;
			}
		}
		
		cout << l << endl;
	}
}  
