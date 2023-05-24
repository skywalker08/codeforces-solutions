#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, a, l;
    cin >> n >> b >> a;
    int arr[n+2];
    int cb=b, ca=a;
    int x;
    for (int i=0;i<n; i++ ) {
        cin >> arr[i];
    }
    int ans=n;
    for (int i=0;i<n;i++) {
        if (i==0) {
            ca-=1;
            continue;
        }
        if (arr[i]) {
            if (ca < a && cb > 0) {
                cb-=1;
                ca+=1;
                continue;
            }
            ca-=1;
        } else {
            if (ca>0) {
                ca-=1;
            } else {
                cb-=1;
            }
        }
        if (ca==0 && cb==0) {
            ans=i+1;
        }
    }
    cout << ans << endl;
}