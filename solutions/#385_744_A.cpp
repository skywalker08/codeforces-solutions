#include <bits/stdc++.h>

using namespace std;

const int maxe=1e3+1;
vector<int> govern;
vector<vector<int>> adj(maxe);
int vis[maxe]={0};

struct depthandedge {
    int depth;
    int edge;
};

depthandedge dfs(int v, int p) {
    vis[v]=1;
    depthandedge result = {0,0};
    for (int u: adj[v]) if (u!=p) {
        result.edge += 1;
        if (!vis[u]) {
            depthandedge x = dfs(u, v);
            result.edge += x.edge;
            result.depth += x.depth;
        }
    }
    result.depth++;
    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    for (int i=0;i<k;i++) {
        cin >> x;
        govern.push_back(x);
    }
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    int maxdept=0, ans=0, edge;
    depthandedge z={0,0};
    for (int i=0;i<k;i++) {
        z = dfs(govern[i], 0);
        edge = (z.edge - (z.depth - 1)) / 2 + z.depth - 1;
        // cout << z.depth << "x" << z.edge << endl;
        maxdept = max(maxdept, z.depth);
        ans += (((z.depth - 1) * z.depth) / 2) - edge;
    }
    for (int i=1;i<=n;i++) if (vis[i]==0) {
        z = dfs(i, 0);
        // cout << z.depth << "y" << z.edge << endl;
        edge = (z.edge - (z.depth - 1)) / 2 + z.depth - 1;
        ans += (((z.depth - 1) * z.depth) / 2) - edge;
        ans+=maxdept * z.depth;
        maxdept+=z.depth;
    }
    cout << ans; 
    return 0;
}