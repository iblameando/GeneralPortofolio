// Greedy Selection Using a Priority Queue

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	
	while (N--) {
		int M;
		cin >> M;
		
		vector<int> A(M);
		for (int i = 0; i < M; i++) {
			cin >> A[i];
		}
		
		ll ans = 0;
		// Keeps positive values available for selection.
		priority_queue<int> B;
		
		for (int i= 0; i < M; i++) {
			if (A[i] > 0) {
				// Stores positive values in the max-heap.
				B.push(A[i]);
			} else {
				if (!B.empty()) {
					// Takes the largest available positive value.
					ans += B.top();
					B.pop();
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
