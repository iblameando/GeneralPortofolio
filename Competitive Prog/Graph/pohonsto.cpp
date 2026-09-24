#include <bits/stdc++.h>
using namespace std;

int n, m, cat[100005], sum;
vector<int> adj[100005];
bool visited[100005];

void dfs(int node, int c) {
    if ((int)adj[node].size() == 1 && node != 1) sum++;
    for (size_t i = 0; i < adj[node].size(); i++) {
        int x = adj[node][i];
        if (!visited[x]) {
            if (cat[x] == 1 && c + 1 <= m) {
                visited[x] = 1;
                dfs(x, c + 1);
            } else if (cat[x] == 0) {
                visited[x] = 1;
                dfs(x, 0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cat[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int tmp = (cat[1] == 1) ? 1 : 0;
    visited[1] = 1;
    dfs(1, tmp);
    cout << sum << "\n";
    return 0;
}

