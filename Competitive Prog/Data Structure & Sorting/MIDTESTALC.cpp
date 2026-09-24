#include <bits/stdc++.h>
#define hatsunemiku ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
using namespace std;

// MIDTESTALC
// Keep at most k unique IDs using a deque and set.

int main () {
	hatsunemiku
	int n, k; cin >> n >> k;
	deque<int> dq; // stores the current unique IDs in order
	set<int> s;    // tracks whether an ID is already present

	while (n--) {
		int id; cin >> id;
		if (s.count(id)) continue; // skip duplicates
		if (dq.size() == k) {
			s.erase(dq.back()); // remove the oldest ID
			dq.pop_back();
		}
		dq.push_front(id); // add the newest ID to the front
		s.insert(id);
	}

	cout << dq.size() << '\n';
	for (int x : dq) cout << x << ' ';
}

