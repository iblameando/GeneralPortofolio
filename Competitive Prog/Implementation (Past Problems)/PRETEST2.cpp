#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	vector<ll> results;
	int N;
	while (cin >> N && N != 0) {
		vector<ll> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
	
		ll kerjah = 0;
		ll imbang = 0;
		for (int i = 0; i < N; i++) {
			imbang += A[i];
			kerjah += abs(imbang);
		}

		results.push_back(kerjah);
	}
	
	cout << "\n[output]\n";
	for (ll r : results) {
		cout << r << '\n';
	}
	return 0;	
}

