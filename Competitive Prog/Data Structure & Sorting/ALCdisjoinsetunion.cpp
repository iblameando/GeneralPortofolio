// Disjoint Set Union Algorithm

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int par[100005];

// Makes every element its own set representative.
void init(int n){
    for(int i=1;i<=n;i++) 
        par[i]=i;
}

// Finds the representative of a set using path compression.
int find(int x){
    if(par[x] == x ) return x;
    else{
        return par[x] = find(par[x]);
    }
}

// Merges the sets containing a and b.
void join(int a, int b){
    int tmpa = find(a);
    int tmpb = find(b);
    par[tmpa] = tmpb;
}

// Checks whether a and b belong to the same set.
bool cek(int a, int b){
    return find(a) == find(b);
}

int main(){
    int n,q;
    cin>>n>>q;
    init(n);
    while(q--){
        int t,a,b;
        cin >> t >> a >> b;
        if(t == 1){
            // Type 1 joins the two sets.
            join(a,b);
        }else{
            // Type 2 checks whether the two elements are connected.
            if(cek(a,b)) cout <<"Y\n";
            else cout <<"T\n";
        }
    }
}
