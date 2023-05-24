#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    if (n<=2) {
        cout << 0;
        return 0;
    }
    int ans=n+1;
    for (int x=arr[0]-1; x<=arr[0]+1; x++) {
        for (int y=arr[1]-1; y<=arr[1]+1; y++) {
            auto s = arr;
            s[0] = x, s[1] = y;
            bool f=false;
            for (int i=2;i<n;i++) {
                s[i] = s[i-1] + (y - x);
                if (abs(s[i] - arr[i]) > 1) {
                    f=true;
                    break;
                }
            }
            if (!f) {
                int ct=0;
                for (int i=0;i<n;i++)  if (s[i]!=arr[i]) {ct++;}
                ans=min(ans, ct);
            }
        }
    }
    if (ans<=n) {cout << ans;}
    else cout << -1;
    return 0;





}
