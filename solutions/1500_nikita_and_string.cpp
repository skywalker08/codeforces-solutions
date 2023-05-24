#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int n=str.size();
    int dp[2][n+2]; // [0][n] = count of a, [1][n] = count of b
    str = " " + str;
    memset(dp, 0, sizeof dp);
    for (int i=1;i<=n;i++) {
        if (str[i]=='a') {
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1];
        } else {
            dp[1][i] = dp[1][i-1] + 1; 
            dp[0][i] = dp[0][i-1];
        }
    }

    int ans = max(dp[0][n], dp[1][n]); // full of a or b
    
    for (int i=1;i<=n;i++) { // ab, ba
        ans=max(ans, dp[0][i] + (dp[1][n] - dp[1][i]) );
        ans=max(ans, dp[1][i] + (dp[0][n] - dp[0][i]) );
    }

    for (int i=1;i<=n;i++) { // aba
        for (int j=i+1; j<=n; j++) {
            int a1 = dp[0][i];
            int b = dp[1][j] - dp[1][i];
            int a2 = dp[0][n] - dp[0][j];
            ans=max(ans, a1 + b + a2);
        }
    }

    cout << ans << endl;
}