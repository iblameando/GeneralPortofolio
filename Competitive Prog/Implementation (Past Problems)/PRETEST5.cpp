#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    vector<ll> dp1(n), dp2(n);
    dp1[0] = A[0];
    dp2[0] = B[0];

    for (int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i-1], dp2[i-1] + A[i]);
        dp2[i] = max(dp2[i-1], dp1[i-1] + B[i]);
    }

    cout << max(dp1[n-1], dp2[n-1]) << endl;
}

