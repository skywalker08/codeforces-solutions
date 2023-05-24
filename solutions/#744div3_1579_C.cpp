#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        string row[n + 1];
        for (int i=1; i<=n; i++) {
            cin >> row[i];
        }
        string ans = "yes";
        int valid[n + 1][m]={0};
        for (int i=n; i>0; i--) {
            for (int j=0; j<m; j++) {
                if (row[i][j]=='*') {
                    int x = i - 1 , y = j - 1, h = 2, d = 0;
                    while( x > 0 && y >= 0) {
                        if (y + h < m) {
                            if (row[x][y]=='*' && row[x][y+h]=='*') {
                                d = i - x;
                            } else { break; }
                        } else { break; }
                        x--;
                        y--;
                        h+=2;
                    }
                    if (d >= k) {
                        x++;
                        y++;
                        h-=2;
                        while (d) {
                            d--;
                            valid[x][y]=1;
                            valid[x][y + h]=1;
                            x++;
                            y++;
                            h-=2;
                        }
                        valid[i][j]=1;
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                if (!valid[i][j] && row[i][j]=='*') {
                    ans="no";
                }
            }
        }
        cout << ans <<"\n";
    }
}