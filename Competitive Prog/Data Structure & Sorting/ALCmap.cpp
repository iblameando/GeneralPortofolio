// Map Algorithm: Store and Query Key-Value Pairs.

#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    
    // Stores each string key with its integer value.
    map<string, int> A;
    for (int i = 0; i < N; i++) {
        string key;
        int value;
        cin >> key >> value;
        A[key] = value;
    }
    
    // Looks up and prints the value for each queried key.
    for (int i = 0; i < M; i++) {
        string key;
        cin >> key;
        cout << A[key] << '\n';
    }
}
