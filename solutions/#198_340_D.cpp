#include <bits/stdc++.h>

using namespace std;

const int maxe=1e5+5;
int a[maxe], b[maxe], f[maxe];


int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    memset(b, 0x7f, sizeof(b));
    b[0]=0;
    b[1]=a[1];
    f[1]=1;
    int ans = 0;
    for (int i=2; i<=n; i++) {
        int l = 0, r = i - 1;
        while (l <= r) {
            int mid=(l+r)/2;
            if ( b[mid] < a[i] ) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        f[i] = r + 1;
        b[f[i]] = min(b[f[i]], a[i]);
        ans = max(f[i], ans);
    }
    cout << ans;
    return 0;
}