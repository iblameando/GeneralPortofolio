// Range Counting with Binary Search

#include <bits/stdc++.h>
#define hatsune ios::sync_with_stdio(0);
#define miku cin.tie(0);
using namespace std;

int main() {
    hatsune miku

    int N;
    cin >> N;
	
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
	
    // Sorts the values so range boundaries can be found efficiently.
    sort(A.begin(), A.end());
	
    int M;
    cin >> M;
	
    vector<pair<int, int>> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i].first >> B[i].second;
    }
    
    for (int i = 0; i < M; i++) { 
        int trg1 = B[i].first;
        int trg2 = B[i].second;

        // Finds the first value not smaller than the lower bound.
        int l = lower_bound(A.begin(), A.end(), trg1) - A.begin();
        // Finds the first value greater than the upper bound.
        int r = upper_bound(A.begin(), A.end(), trg2) - A.begin();

        // The difference gives the count of values in the inclusive range.
        cout << (r - l) << '\n';
    }
}

