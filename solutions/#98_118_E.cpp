#include <bits/stdc++.h>
#include <vector>
//BertownRoads2000_dfs.cpp
using namespace std;

const int maxe = 1e5+5;
vector<vector<int>> node(maxe), ans(maxe);
int depth[maxe]={0}, low[maxe];

void dfs(int u, int d, int p) {
    depth[u] = d;
    low[u]=d;
    for (auto v:node[u]) if (v != p) {            
        if(depth[v]) {
            if (depth[v] < depth[u] ) ans[v].push_back(u);
        } else {
            dfs(v, d + 1, u);
            ans[v].push_back(u);
        }
        low[u] = min(low[u], low[v]);
    }
    if (p && low[u]==depth[u]) {
        cout << 0 << endl;
        exit(0);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dfs(1, 1, 0);
    for (int i=1;i<=n;i++) {
        for (auto v : ans[i]) {
            cout << i << " " << v <<endl;
        }
    }
    return 0;
}
