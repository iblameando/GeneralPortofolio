// BFS Algorithm Implementation

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    // Stores the undirected graph as adjacency lists.
    vector<int> adj[n+3];

    // Reads each edge and adds it in both directions.
    for(int i = 0;i < m;i++){
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Tracks whether each vertex has already been visited.
    bool vis[n+1];
    memset(vis, 0, sizeof vis);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        else
            // A new unvisited vertex starts another component.
            ans++;

        // Traverses the current component with BFS.
        queue<int> q;
        vis[i] = 1;
        q.push(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            // Visits every unvisited neighbor of the current vertex.
            for(int i = 0;i < adj[u].size();i++){
                int v = adj[u][i];
                if(vis[v] == 0){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    cout << ans <<endl;
} 
