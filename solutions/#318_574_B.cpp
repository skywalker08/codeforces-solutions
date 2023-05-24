#include <bits/stdc++.h>

using namespace std;

const int maxe = 4001;
int m;
int ans = 4000;
int flag = 1;
int vis[maxe] = {0};
vector<vector<int>> grap(maxe);

void dfs(int v, int p, int gp, int psize, int gpsize, int depth) {
    int vsize = grap[v].size();
    int sizep = grap[p].size();
    for (int u : grap[v])   {
        if (u != p) {
            if (depth<2) {
                if (p != -1) { dfs(u, v, p, vsize, sizep, depth + 1); }
                else { dfs(u, v, p, vsize - 1, -1, depth + 1); }
            }
            if (u == gp) {
                ans = min(ans, (psize + gpsize + vsize - 6)); 
                flag = 0;
            }
        }
        
    }
}

int main() {
    int n;
    cin >> n >> m;
    int x,y;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        grap[x].push_back(y);
        grap[y].push_back(x);
    }
    
    for (int i=1; i<=n; i++) {
        dfs(i, -1, -1, -1, -1, 0);
    }
    if (flag) {
        cout << -1;
        return 0;
    }
    cout << ans << endl;
    return 0;

}