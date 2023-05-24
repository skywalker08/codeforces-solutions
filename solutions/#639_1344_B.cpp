#include <bits/stdc++.h>
using namespace std;

const int maxe = 1002;
int matrix[maxe][maxe];
int row[maxe]={0}, column[maxe]={0};
int vis[maxe][maxe];

void dfs(int i ,int j) {
    vis[i][j]=1;
    if (matrix[i+1][j] && vis[i+1][j]==0) {
        dfs(i+1, j);
    } if (matrix[i][j+1] && vis[i][j+1]==0) {
        dfs(i, j+1);
    } if (matrix[i-1][j] && vis[i-1][j]==0) {
        dfs(i-1, j);
    } if (matrix[i][j-1] && vis[i][j-1]==0) {
        dfs(i, j-1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    char c;
    int ans=0;
    memset(matrix, 0, sizeof(matrix));
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf(" %c", &c);
            if (c=='#') {
                matrix[i][j]=1;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (matrix[i][j]==1) {
                if (column[j]==0) column[j]=1;
                if (column[j]==2) ans=-1;
                if (row[i]==0) row[i]=1;
                if (row[i]==2) ans=-1;
            } else {
                if (row[i]==1) row[i]=2;
                if (column[j]==1) column[j]=2;
            }
        }
    }
    int f1=0, f2=0;
    for (int i=1; i<=n; i++) {
        if (row[i]==0) {
            f1=1;
        }
    }
    for (int i=1; i<=m; i++) {
        if (column[i]==0) {
            f2=1;
        }
    }
    if ((f1 && f2==0) || (f1==0 && f2)) {
        ans=-1;
    }
    if (ans!=-1) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (vis[i][j]==0 && matrix[i][j]==1) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}