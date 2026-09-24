// Codeforces Problem 158A - Next Round

#include <bits/stdc++.h>
using namespace std;

int main () {
	// Reads the number of participants and the qualifying position.
	int n; cin >> n;
	int k; cin >> k;
	// Stores the number of participants who advance.
	int sum = 0;
	// Stores all participant scores.
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		// Reads a score and checks whether the participant qualifies.
		cin >> a[i];
		if (a[i] >= a[k-1] && a[i] > 0) {
			// Counts positive scores that meet or exceed the kth score.
			sum++;
		}
	}
	// Prints the total number of participants advancing to the next round.
	cout << sum;
}
