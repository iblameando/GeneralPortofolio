#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t; // test case
	
	while (t--) {
		int n;
		cin >> n;
		
		int a[n+1];
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		
		int tahun = 0;
		
		for (int i = 1; i <= n; i++) {
			int sisa = tahun%a[i];
			int tambah = a[i]-sisa;
			tahun += tambah;
		}
		
		cout << tahun << endl;
	}
}
