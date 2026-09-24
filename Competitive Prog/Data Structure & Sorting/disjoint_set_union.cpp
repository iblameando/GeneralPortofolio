#include <bits/stdc++.h>
using namespace std;
struct DSU{ vector<int> p,s; DSU(int n):p(n),s(n,1){ iota(p.begin(),p.end(),0);} int f(int x){return p[x]==x?x:p[x]=f(p[x]);} void u(int a,int b){a=f(a);b=f(b); if(a==b) return; if(s[a]<s[b]) swap(a,b); p[b]=a; s[a]+=s[b];}};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M,K; if(!(cin>>N>>M>>K)) return 0;
    vector<long long>B(N),G(M);
    for(int i=0;i<N;i++) cin>>B[i];
    for(int i=0;i<M;i++) cin>>G[i];
    sort(G.begin(),G.end());
    DSU d(N);
    for(int i=0;i<K;i++){ int a,b; cin>>a>>b; d.u(a-1,b-1); }
    vector<vector<long long>> grp(N);
    for(int i=0;i<N;i++) grp[d.f(i)].push_back(B[i]);
    long long ans=0;
    for(int i=0;i<N;i++){
        auto &v=grp[i]; if(v.empty()) continue;
        sort(v.begin(),v.end());
        int sz=v.size();
        vector<long long> pref(sz+1,0);
        for(int j=0;j<sz;j++) pref[j+1]=pref[j]+v[j];
        long long best=LLONG_MAX;
        long long med1=v[(sz-1)/2], med2=v[sz/2];
        long long meds[2]={med1,med2};
        for(long long m:meds){
            auto it=lower_bound(G.begin(),G.end(),m);
            if(it!=G.end()){
                long long g=*it;
                int idx=upper_bound(v.begin(),v.end(),g)-v.begin();
                long long cost=g*(long long)idx - pref[idx] + (pref[sz]-pref[idx]) - g*(long long)(sz-idx);
                best=min(best,cost);
            }
            if(it!=G.begin()){
                long long g=*(it-1);
                int idx=upper_bound(v.begin(),v.end(),g)-v.begin();
                long long cost=g*(long long)idx - pref[idx] + (pref[sz]-pref[idx]) - g*(long long)(sz-idx);
                best=min(best,cost);
            }
        }
        ans += best;
    }
    cout<<ans<<"\n";
    return 0;
}

