#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;            
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;            
    vector<int> rawr(k + 1, 1e9); 
    rawr[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int koin : a) {
            if (i - koin >= 0) {
                rawr[i] = min(rawr[i], rawr[i - koin] + 1);
            }
        }
    }
    if (rawr[k] == 1e9) cout << -1;
    else cout << rawr[k];
}

