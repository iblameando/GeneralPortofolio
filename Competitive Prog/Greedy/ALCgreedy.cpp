// Greedy Interval Processing

#include <bits/stdc++.h>
#define hatsune ios::sync_with_stdio(0);
#define miku cin.tie(0);
using namespace std;

bool sapi(pair<int, int> a, pair<int, int> b) {
    // Orders intervals by their ending value.
    return a.second < b.second;
}

int main () {
    hatsune miku

    int T;
    // Reads the number of test cases.
    cin >> T;

    while (T--) {
        int N;
        // Reads the number of intervals in the current test case.
        cin >> N;

        // Stores each interval as a pair of values.
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first >> A[i].second;
        }
        
    }
}

