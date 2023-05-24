#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int maxe = 2e5+5;
long long int cost[maxe][2];
int mincosts[maxe][3]={0};
vector<vector<int>> adj(maxe);
long long int ans = -1;

pair<int,int> dfs(int u, int p) {
    pair<int,int> wants;
    wants.x = 0;  
    wants.y = 0; 
    if (cost[u][1] != -1) {
        if (cost[u][1] == 0) wants.x=1;
        else if (cost[u][1] == 1) wants.y=1;
    }
    for (int v : adj[u]) if (v != p) {
        pair<int,int> w = dfs(v, u);
        wants.x += w.x;
        wants.y += w.y;
    }
    mincosts[u][1] = wants.x;
    mincosts[u][2] = wants.y;
    return wants;
}



void solve(int u, int p, long long minv) {
    if (u==1) {

        long long x = min(mincosts[u][1], mincosts[u][2]);
        ans = cost[u][0] * x * (long long)2;

    }
    if (cost[u][0] < minv) {
        
        long long x = min(mincosts[u][1], mincosts[u][2]);
        if (x > 0) {
            ans -= x*(long long)2*minv;
            minv = cost[u][0];
            ans += x * (long long)2 * cost[u][0];    
        }
    }

    for (int v : adj[u]) if (v != p) {
        solve(v, u, minv);
    }

}

int main() {
    int n;
    cin >> n;
    int a, b, c;
    int has0=0, wants0=0, has1=0, wants1=0;
    memset(cost, -1, sizeof(cost));
    for (int i=1;i<=n;i++) {
        scanf("%d%d%d", &a, &b, &c);
        cost[i][0] = a;
        if (b != c) {
            cost[i][1] = c;
            if (b) {
                has1++;
            } else has0++;
            if (c) {
                wants1++;
            } else wants0++;
        }
    }
    int u, v;
    for (int i=0; i < n-1; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if ((has0 == wants0) && (has1 == wants1)) {
        dfs(1, 0);
        solve(1, 0, cost[1][0]);
    }
    cout << ans;
    return 0;
}