// Process Increment and Decrement Operations

#include <bits/stdc++.h>
using namespace std;

int main () {
	int n; cin >> n;
	string wow;
	int x = 0;
	// Processes each operation and updates the counter.
	for (int i = 0; i < n; i++) {
		cin >> wow;
		// Increases the counter for either increment notation.
		if (wow == "++X" || wow == "X++") {
			x++;
		// Decreases the counter for either decrement notation.
		} else if (wow == "--X" || wow == "X--") {
			x--;
		}
	}
	// Prints the final counter value.
	cout << x;
}
