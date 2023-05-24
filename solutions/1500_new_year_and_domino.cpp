#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    string line;
    char table[h+2][w+2];
    memset(table, '0', sizeof table);
    for (int i=1; i<=h; i++) {
        cin >> line;
        line = " " + line;
        for (int j=1; j<=w; j++) {
            table[i][j] = line[j];
        }
    }
    int dph[h+3][w+3];
    int dpv[h+3][w+3];
    int dp[h+3][w+3];
    int c=0;
    memset(dp, 0, sizeof dp);
    memset(dpv, 0, sizeof dpv);
    memset(dph, 0, sizeof dph);
    for (int y=1; y<=h; y++) {
        for (int x=1; x<=w; x++) {
            c=0;
            if (table[y][x]=='.') {
                if (table[y+1][x] == '.' && y != h) {
                    c+=1;
                    dpv[y][x]=1;
                } if (table[y][x+1] == '.' && x != w) {
                    dph[y][x]=1;
                    c+=1;
                }
            }
            dp[y][x] = dp[y][x-1] + c;
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int y1, x1, y2 ,x2, x, y, ans=0;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int y=y1; y<y2; y++) {
            ans+=dp[y][x2-1] - dp[y][x1-1];
        }
        for (int x=x1; x<x2; x++) {
            ans+=dph[y2][x];
        }
        for (int y=y1; y<y2; y++) {
            ans+=dpv[y][x2];
        }
        cout << ans << endl;
    }
    return 0;
}