#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;cin >> tt; while (tt--) {
        long long n;
        cin >> n;
        long long x, xo=1e9, xe=1e9, co=n, ce=n;
        long long t1=0;
        long long ans = 1e17;
        for (long long i=1;i<=n; i++) { 
            cin >> x;
            t1+=x;
            if (i%2)xo=min(xo,x), co-=1;
            else xe=min(xe,x), ce-=1;
            ans=min(ans, t1+xe*ce+xo*co);
        }
        cout << ans << endl;
    }
}