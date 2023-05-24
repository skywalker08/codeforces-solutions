#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int l1=0, r1=0, l2=0, r2=0, x, y;
        vector<int> two;
        for (int i=0;i<n;i++) {
            cin >> x >> y;
            if (i==0) {
                l1=x;
                r1=y;
            }
            if (x>r1 || y<l1) {
                if (l2==0) {
                    l2=x;
                    r2=y;
                    two.push_back(i);
                }
                else if (x>r2 || y<l2) {
                    if (x>r2)
                } else {
                    l2=max(l2, x);
                    r2=max(r2, y);
                    two.push_back(i);
                }
            }
            else {
                if (!(x>r2 || y<l2)) {
                    l2=0;
                    r2=0;
                    two.clear();
                }
                l1=max(l1, x);
                r1=max(r1, y);
            }
        }
        int ans[n+1];
        if (two.empty()) {
            cout << -1 << endl;
            continue;
        }
        for (int i=n;i>=1;i--) {
            if (!two.empty()) {
                if (i != two.back() + 1) {
                    ans[i]=1;
                } else {
                    ans[i]=2;
                    two.pop_back();
                }
            } else {
                ans[i]=1;
            }
        }
        for (int i=1;i<=n;i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}