#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a, x, cnt=0, ans=0;
        cin >> a;
        for (int i=0; i<a; i++) {
            cin >> x;
            if (x) {
                if (!i) {ans+=1; continue;}
                cnt+=1;
            }
            else {
                ans+=cnt/3;
                cnt=0;
            }
        }
        ans+=cnt/3;
        cout << ans << endl;
    }
    return 0;
}