#include <bits/stdc++.h>

using namespace std;


int main() {
    int n,m,ans=0;
    cin >> n >> m;
    string sarr[n];
    int col[m]={0};
    for (int i=0;i<n;i++){
        cin >> sarr[i];
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (sarr[i][j] > sarr[i+1][j]) {
                int flag=1;
                for (int j2 = j-1; j2>=0; j2--) {
                    if (sarr[i][j2] < sarr[i+1][j2] && col[j2]==0) {
                        flag=0;
                        break;
                    }
                }
                if (flag) {
                    ans+=1;
                    col[j]=1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}