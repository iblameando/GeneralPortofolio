#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N;
    cin >> N;

    long long sum = 1LL * N * (N + 1) / 2;

    if (sum %2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<long long> set1, set2;
    long long target = sum / 2;

    for (int i = N; i >= 1; --i) {
        if (i <= target) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";
    
}

