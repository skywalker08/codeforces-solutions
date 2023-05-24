#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0=0, cnt1=0;    
    int ans=0;
    int balance[200005];
    memset(balance, -1, sizeof(balance));
    int x=100001;
    balance[x] = 0;
    for (int i=1;i<=n;i++) {
        if(s[i-1]=='1') {
            cnt1++;
        }else {
            cnt0++;
        }
        if (balance[x + cnt1-cnt0] < 0) {
            balance[x + cnt1-cnt0] = i;
        } else {
            ans=max(ans, i - balance[x+cnt1-cnt0]);
        }
    }
    cout << ans;
}