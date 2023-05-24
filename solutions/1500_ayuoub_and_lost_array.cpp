#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 7;

int main() {
    long long n, l, r, x;
    cin >> n >> l >> r;
    long long d0=0, d1=0, d2=0;
    long long dp[n+2][3];
    d0 = r/3 - l/3 + (l%3==0);
    d1 = r/3 - l/3;
    d1 = d1 + (r%3>0) - (l%3==2);
    d2 = r/3 - l/3;
    d2 = d2 + (r%3==2);
    dp[0][0]=d0;
    dp[0][1]=d1;
    dp[0][2]=d2;
    for (int i=1; i<n; i++) {
        dp[i][0] = ((dp[i-1][0] * d0)%mod + (dp[i-1][1] * d2)%mod + (dp[i-1][2] * d1)%mod)%mod;
        dp[i][1] = ((dp[i-1][0] * d1)%mod + (dp[i-1][1] * d0)%mod + (dp[i-1][2] * d2)%mod)%mod;
        dp[i][2] = ((dp[i-1][0] * d2)%mod + (dp[i-1][1] * d1)%mod + (dp[i-1][2] * d0)%mod)%mod;
    }
    cout << dp[n-1][0] << endl;
}