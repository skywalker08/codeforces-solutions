#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, l=-1;
    cin >> n >> k;
    int arr[2000]={0};
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        if (arr[i] && i<k) {
            l=i;
        }
    }
    if (l==-1) {
        cout << -1;
        return 0;
    }
    int r=k-1;
    int ans=1;
    while (l < n - k ) {
        int pl=l;
        int m = l + k + k -1;
        for (int i=r+1; i <= m; i++) {
            if (arr[i]) {
                l=i;
            }
        }
        if (pl == l) {
            cout << -1;
            return 0;
        }
        ans+=1;
        r=m;
    }
    cout << ans;
    return 0;
}