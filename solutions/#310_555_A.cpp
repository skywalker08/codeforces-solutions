#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int m, ans=0;
    for (int i=0;i<k;i++) {
        cin >> m;
        int x, px=0, ct=1, f=1;
        for (int j=0;j<m;j++) {
            cin >> x;
            if (x-1 > px && f) {
                if (j>0) {
                    ct = m - j + 1;    
                } else {
                    ct = m - j;
                }
                f = 0;
            }
            px=x;
        }
        ans += ct + ct - 1;
    }
    cout << ans - 1;
    return 0;
}