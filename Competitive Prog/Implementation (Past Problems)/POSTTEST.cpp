#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(1){
        int n; cin>>n;
        if(!n) break;
        int a,b,c;
        cin>>a>>b>>c;
        int p0=1e9,p1=b,p2=1e9;
        for(int i=1;i<n;i++){
            cin>>a>>b>>c;
            int np0=a+min(p0,p1);
            int np1=b+min({p0,p1,p2});
            int np2=c+min(p1,p2);
            p0=np0; p1=np1; p2=np2;
        }
        cout<<t++<<". "<<p1<<"\n";
    }
}

