// Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,int>; // (jarak, node)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, q;
    if(!(cin >> n >> m >> p >> q)) return 0;

    // 1) adjacency list (1-based). PENTING: ukurannya harus n+1
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // graf tak berarah
    }

    // 2) dist: jarak terbaik sementara dari p ke setiap node
    const ll INF = (1LL<<60);
    vector<ll> dist(n+1, INF);
    dist[p] = 0;

    // 3) priority queue (min-heap) menyimpan pair (jarak, node)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, p});

    // 4) MAIN LOOP DIJKSTRA
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        ll d = cur.first;   
        int u = cur.second; 

        // 4a) STALE CHECK
        if (d != dist[u]) continue;
        // optional early exit utk optimization:
        if (u == q) break;

        // 4b) RELAXATION: cek semua tetangga u, coba perbaiki dist[v]
        for (auto edge : adj[u]) {
            int v = edge.first;       // tetangga
            int w = edge.second;      // bobot edge u->v
            ll nd = d + (ll)w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    // 5) keluarkan jawaban
    cout << dist[q] << '\n';
    return 0;
}

