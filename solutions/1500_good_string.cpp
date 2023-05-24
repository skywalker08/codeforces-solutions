#include <bits/stdc++.h>

using namespace std;

int dp[131074], cnt[17*17];


void dac(string str, int bot, int top, int chr, int ans) {
    int mid=(bot+top)/2;
    for (int i=bot; i<top; i++) {
        if (!dp[i]) {cnt[ans] += dp[i] == chr ? 1 : 0;}
        else {int x = str[i];cnt[ans]+= x == chr ? 1 : 0; dp[i]=x; }
    }
    dac(str, mid, top, chr+1, ans);
    dac(str, bot, mid, chr+1, ans);

}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a;
        cin >> a;
        string str;
        cin >> str;
        dac(str, 0, a/2, , 97, 1)
        dac(str, a/2, a, , 97, 18)
        return 0;
    }
}