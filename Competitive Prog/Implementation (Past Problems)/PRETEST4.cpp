#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;

int main () {
	int N, M;
	cin >> N >> M;
	
	vector<ll> A(N);
	vector<vector<int> > B(N);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		B[u].pb(v);
		B[v].pb(u);
	}
	
}
