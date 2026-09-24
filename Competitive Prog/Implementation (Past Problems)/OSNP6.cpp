#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
	ll n, m; cin >> n >> m;
	if (n<m) swap(n,m);
	ll h1=n*(n+1)/2;
	ll h2=(m-1)*(n+m);
	cout << h1 + h2;
}

