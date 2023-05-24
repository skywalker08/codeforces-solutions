#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x, ans;
    cin >> n >> k;
    set<int> m;
    int arr[n+2];
    for (int i=0; i<n; i++) {
        cin >> x;
        arr[i]=x;
        m.insert(x);
        while ( x>0 ) {
            x/=2;
            m.insert(x);
        }
    }
    ans=1e5;
    sort(arr, arr+n);
    for (auto u: m) {
        int c=0;
        int cplus=0;
        int t=0;
        for (int i=0;i<n;i++) {
            x=arr[i];
            cplus=0;
            while (x>u) {
                x/=2;
                cplus+=1;
            }
            if (x==u) {
                c+=cplus;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                t+=1;
            }
            if (t==k) {
                ans=min(ans, c);
                break;
            }
        }
    }
    cout << ans;
}