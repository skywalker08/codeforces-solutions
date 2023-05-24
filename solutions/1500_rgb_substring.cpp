#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        const string rgb="RGB";
        cin>> n >> x;
        string str;
        cin >> str;
        int ans=n;
        for (int offset=0; offset<3; offset++) {
            int w[n]={0};
            int atm=0;
            for (int i=0; i<n; i++) {
                w[i] = (rgb[ (offset + i) % 3 ] != str[i]);
                atm+=w[i];
                if (i>=x) {
                    atm -= w[i-x];
                    ans = min(ans, atm);
                }
                if (i>=x-1) {
                    ans=min(ans, atm);
                }
            }
            
        }
        cout << ans << endl;
    }
}