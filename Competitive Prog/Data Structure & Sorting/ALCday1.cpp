// Queue Algorithm
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main () {
	int N;
	cin >> N;
	
	// Stores each operation and its value, if present.
	vector<pair<int, int> > A;
	
	for (int i = 0; i < N; i++) {
		int lumping, kuda= -1;
		cin >> lumping;
		// Type 1 operations provide a value to be printed later.
		if (lumping == 1) cin >> kuda;
		A.pb({lumping, kuda});
	}
	
	// Collects values from all type 1 operations in their original order.
	vector<int> B;
	for (int i = 0; i < N; i++) {
		if (A[i].first == 1) B.pb(A[i].second);
	}
	
	// Prints the next stored value for each type 2 operation.
	int b = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].first ==  2) cout << B[b++] << "\n";
	}
}
