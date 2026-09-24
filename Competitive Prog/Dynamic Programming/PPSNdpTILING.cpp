#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n = 1e6, mod = 1e9+7;
	int f[n+5];
	f[0]=1,f[1]=1;
	for(int a=2;a<=n;a++) {
		f[a]=f[a-1]+f[a-2];
		f[a]%=mod;
	}
	int tc; cin >> tc;
	for (int t=1; t<=tc;t++) {
		int n;
		cin >> n;
		cout<<f[n]<<endl;
	}
}
