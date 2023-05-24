#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<int> adj[N];
int cats[N], vis[N]={0}, ans=0;
void dfs(int p, int v, int maxcat, int m, int cat) {
    vis[v]=1;
    if (cats[p] && cats[v]) {cat+=1;}
    else {cat=0;}
    maxcat=max(maxcat,cat);
    for (auto u : adj[v]) {
        if (!vis[u]) dfs(v , u, maxcat, m, cat);
        else {
            if (adj[v].size() == 1) ans += maxcat < m;
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> cats[i];
    }
    cats[0]=0;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,1, 0, m, 0);
    cout << ans;
}
