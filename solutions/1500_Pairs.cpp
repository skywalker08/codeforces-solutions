#include <bits/stdc++.h>

using namespace std;

const int maxe=300007;
vector<vector<int>> v(maxe);
int vis[maxe]={0};

void dfs(int p) {
    vis[p]=1;
    for (auto c: v[p]) {
        if (!vis[c]) dfs(c);
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    set<int> s;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        
    }
    return 0;
}