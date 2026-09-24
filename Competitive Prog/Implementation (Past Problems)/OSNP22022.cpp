#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

int main () {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    ll k; 
    cin >> k;
    vector<pair<ll, ll> > kandang(k);
    
    for (int i = 0; i < k; i++) cin >> kandang[i].first;
    for (int i = 0; i < k; i++) cin >> kandang[i].second;
    
    sort(kandang.begin(), kandang.end(), cmp);
    
    ll n; 
    cin >> n;
    priority_queue <ll> bebeq;
    for (int i = 0; i < n; i++) {
        ll b; 
        cin >> b;
        bebeq.push(b);
    }
    
    ll total = 0;
    for (int i = 0; i < k; i++) {
    	ll kapasiti = kandang[i].first;
    	ll harga = kandang[i].second;
    	while (kapasiti > 0 && !bebeq.empty()) {
    		ll berat = bebeq.top();
    		bebeq.pop();
    		total += berat * harga;
    		kapasiti--;
		}
	}
	
	cout << total << '\n';
}

