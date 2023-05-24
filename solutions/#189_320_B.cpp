#include <bits/stdc++.h>

using namespace std;

int a[111], b[111];
int vis[111];
int m, n=0;

void dfs(int v) {
    vis[v] = 1;
    for (int i = 1; i <= n; i++) {
        if ( vis[i] ) {
            continue;
        } else if ( a[v] > a[i] && a[v] < b[i] ) {
            dfs(i);
        } else if ( b[v] > a[i] && b[v] < b[i] ) {
            dfs(i);
        }
    }
}

int main() {
    cin >> m;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(vis, 0, sizeof(vis));
    int x, y, k;
    for (int i=0; i < m; i++) {
        cin >> k >> x >> y;
        if (k==1) {
            n++;
            a[n] = x;
            b[n] = y;
        } else {
            memset(vis, 0, sizeof(vis));
            dfs(x);
            if (vis[y]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    }
}