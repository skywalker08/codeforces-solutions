#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005], ans;
int vis[100005]={0};

int main() {    
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    priority_queue<int, vector<int>, greater<int> > Q;
    Q.push(1);
    vis[1]=1;
    while (!Q.empty()) {
        int j = Q.top();
        Q.pop();
        ans.push_back(j);
        for (auto u: adj[j]) {
            if (!vis[u]) {
                vis[u]=1;
                Q.push(u);
            }
        }
    }
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}