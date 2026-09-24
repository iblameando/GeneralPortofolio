// Undirected Weighted Graph Algorithm

#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int arr[10];
	// Stores each vertex's connected neighbors and edge weights.
	vector<pair <int, int> > adj[n+3];
	
	// Reads the undirected weighted edges into the adjacency list.
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	// Prints every vertex directly connected to x.
	int x;
	cin >> x;
	for (int i = 0; i < adj[x].size(); i++) {
		cout << x << " terhubung dengan " << adj[x][i].first << " dengan bobot " << adj[x][i].second << endl;
 	}
}
