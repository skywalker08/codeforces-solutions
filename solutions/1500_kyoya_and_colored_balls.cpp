#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll comb[1005][1005];
int main() {
    comb[0][0]=1;
    for (int i=1; i<1005; i++) {
        comb[i][0]=1;
        comb[i][i]=1;
        for (int j=1; j < i; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            comb[i][j]= comb[i][j] % mod;
        }
    }
    ll c, cnt=0, ans=1;
    int k;
    cin >> k;
    for (int i=1;i<=k;i++) {
        cin >> c;
        ans *= comb[cnt + c - 1][c-1];
        ans = ans %  mod;
        cnt+=c;
    }
    cout << ans << endl;
    return 0;
    

}