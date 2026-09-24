#include <bits/stdc++.h>
using namespace std;
struct State{int val,w,prev,item;};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    vector<State> dp(n+1,{0,0,-1,-1});
    for(int idx=1;idx<=k;idx++){
        int w,h;cin>>w>>h;
        for(int cap=n;cap>=w;cap--){
            int nv=dp[cap-w].val+h, nw=dp[cap-w].w+w;
            if(nv>dp[cap].val || (nv==dp[cap].val && (nw<dp[cap].w || (nw==dp[cap].w && idx<dp[cap].item)))){
                dp[cap]={nv,nw,cap-w,idx};
            }
        }
    }
    int best=0;
    for(int cap=1;cap<=n;cap++)
        if(dp[cap].val>dp[best].val || (dp[cap].val==dp[best].val && dp[cap].w<dp[best].w))
            best=cap;
    vector<int> ans;
    for(int c=best;c>0 && dp[c].item!=-1;c=dp[c].prev) ans.push_back(dp[c].item);
    sort(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<"\n";
}

