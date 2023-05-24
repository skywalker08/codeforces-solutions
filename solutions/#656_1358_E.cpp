#include <bits/stdc++.h>

using namespace std;

const int maxe = 2e5+5;
vector<int> vis;
vector<vector<int>> adj;
vector<int> ord(maxe);


void dfs(int v) {
    vis[v] = 1;

    for (auto u : adj[v]) if (!vis[u]) {
        dfs(u);
    }

    ord.push_back(v);

}

int main() {
    int tt;
    cin >> tt; 
    while (tt--) {
        int n, m;
        cin >> n >> m;
        adj = vector<vector<int>>(n);
        vector<pair<int,int>> ansv;
        vis = vector<int>(n);

        for (int i=0; i < m; i++) {
            int t, x, y;
            cin >> t >> x >> y;
            x--, y--;
            if (t) {
                adj[x].push_back(y);
            }
            ansv.push_back(make_pair(x, y));
        }
        
        ord.clear();

        for (int i=0; i<n; i++) if (vis[i] == 0) {
            dfs(i);
        }

        vector<int> pos(n);
        bool ans=true;
        reverse(ord.begin(), ord.end());
        
        for (int i=0; i<n; i++) {
            pos[ord[i]] = i;
        }

        for (int i=0; i<n; i++) {
            for (auto x : adj[i] ) {
                if (pos[i] > pos[x] ) {
                    ans = false;
                }
            }
        }

        if (ans == false) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (auto [x, y] : ansv) {
                if (pos[x] < pos[y]) {
                    cout << x + 1 << " " << y + 1 << endl;
                } else {
                    cout << y + 1 << " " << x + 1 << endl;
                }
            }
        }
    }
    return 0;
}