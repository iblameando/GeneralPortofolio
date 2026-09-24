// Binary Search with Original-Index Tracking

#include <bits/stdc++.h>
#define hatsune ios::sync_with_stdio(0);
#define miku cin.tie(0);
using namespace std;

int main() {
    hatsune miku

    int N;
    cin >> N;
	
    // Stores each value together with its original index.
    vector<pair<int, int> > A(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A[i] = {x, i};
    }
	
    // Sorts values so binary search can be applied.
    sort(A.begin(), A.end());
	
    int M;
    cin >> M;
	
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < M; i++) {
        int trg = B[i];
        int l = 0, r = N-1;
        int ans = -1;
		
		// Finds the first sorted position containing the target.
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid].first == trg) {
                ans = mid;
                r = mid - 1;
            } else if (A[mid].first < trg) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
		
        if (ans == -1) {
            cout << -1 << '\n';
        } else {
            // Finds the smallest original index among duplicate matches.
            int min_idx = A[ans].second;
            while (ans - 1 >= 0 && A[ans - 1].first == trg) {
                ans--;
                min_idx = min(min_idx, A[ans].second);
            }
            cout << min_idx << '\n';
        }
    }
}

