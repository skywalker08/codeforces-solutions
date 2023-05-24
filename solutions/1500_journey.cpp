#include <bits/stdc++.h>
 
using namespace std;

const int maxE = 1e5+2;

int vis[maxE];
vector<int> adj[maxE];

double dfs(int p) {

    double x=0;
    int y=0;
    vis[p]=1;

    for (auto u : adj[p]) {
        if (!vis[u]) { x+=dfs(u);y+=1; }
    }
    if (!y) return 1;
    return (x / y) + 1;
}

int main() {
    cout << fixed;
    cout << setprecision(15);
    int a, x, y;
    cin >> a;
    
    for (int i=0; i<a-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(1)-1;
    return 0;
}
 