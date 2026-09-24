#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	
	while (1) {
		int n;
		cin>>n;
		
		if (n == 0) {
			return 0;
		}
		
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		ll ans = 0; sel = 0;
		for (int i=0; i < n; i++) {
			sel+=a[i];
			ans+=abs(sel);
		}
		
		cout << ans << endl;
	}
}
