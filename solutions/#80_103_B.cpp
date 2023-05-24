#include <bits/stdc++.h>

using namespace std;

const int maxe = 1e4+1;
int vis[maxe]={0};
vector<vector<int>> edges(maxe);
int c=0;


void dfs(int v, int p) {
    vis[v]=1;
    for (int u : edges[v]) if (u!=p) {
        if (vis[u]) {
            c+=1;
        } else {
            dfs(u, v);
        }    
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x,y;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    if (n!=m) {
        cout << "NO";
        return 0; 
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i])dfs(i, 0);
    }
    if (c>2) {
        cout << "NO";
    } else {
        cout << "FHTAGN!";
    }
    return 0;
}