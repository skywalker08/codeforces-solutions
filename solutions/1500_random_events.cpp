#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int arr[n];
        int lc=n;

        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }

        for (int i=n-1; i>=0; i--) {
            if (arr[i]==i+1) {
                lc-=1;
            } else {break;}
        }
        
        double ans=1.0;

        if (lc==0) {
            ans=0.0;
        }

        int r;
        double p;
        for (int i=0;i<m;i++) {
            cin >> r >> p;
            if (r>=lc) {
                ans *= (1-p);
            }
        }
        cout << setprecision(6) <<  1 - ans << endl;
    }
}