#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans=0;
    map<ll,ll> freq;
    for(int j=0;j<n;j++){
        ll trg=j+1-a[j];
        if(freq.count(trg)) ans+=freq[trg];
        freq[j+1+a[j]]++;
    }
    cout << ans << "\n";
}

