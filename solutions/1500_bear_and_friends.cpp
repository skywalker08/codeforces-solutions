#include <bits/stdc++.h>

using namespace std;
string ans="YES";
const int maxe=2e5;
vector<int> adj[maxe];
int vis[maxe]={0};

int solve(int x) {
    vis[x]=1;
    int c=0;
    for (auto u : adj[x]) {
        if (!vis[u]) c += solve(u);
        if (adj[u].size() != adj[x].size()) ans="NO";
    }
    return c+1;
}

int main() {

    int n, m, x, y;
    cin >> n >> m;
    set<int> s;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        s.insert(x);
        s.insert(y);
    }
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++) {
        if (!vis[*itr]) { 
            if( adj[*itr].size() != solve(*itr)-1 ) { 
                ans="NO"; 
            }
        }
    }

    cout << ans << endl;
    return 0;

}