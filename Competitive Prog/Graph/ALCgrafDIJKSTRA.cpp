// Dijkstra's Algorithm for Single-Source Shortest Paths

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,int>
#define panjangbet 1e18
using namespace std;

int n, m;
vector<pll> g[100005];
ll d[100005];

void dik() {
    priority_queue<pll> q;
    // Initializes all distances to infinity and starts from vertex 1.
    for (int i = 1; i <= n; i++) d[i] = panjangbet;
    d[1] = 0; q.push({0,1});
    while (!q.empty()) {
        ll du = -q.top().first; int u = q.top().second; q.pop();
        // Skips an outdated queue entry.
        if (du > d[u]) continue;
        for (int i = 0; i < g[u].size(); i++) {
            int w = g[u][i].first, v = g[u][i].second;
            // Relaxes the edge when a shorter path is found.
            if (du + w < d[v])
                d[v] = du + w, q.push({-d[v], v});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        // Stores each directed weighted edge in the graph.
        g[u].push_back({w,v});
    }
    dik();
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}

