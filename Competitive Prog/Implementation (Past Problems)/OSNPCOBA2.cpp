#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n;
    string s; cin >> s;
    ll o=0, os=0, osn=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='O') o++;
        else if(s[i]=='S') os+=o;
        else if(s[i]=='N') osn+=os;
    }
    cout << osn;
}

