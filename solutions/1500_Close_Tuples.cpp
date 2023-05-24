#include <bits/stdc++.h>

using namespace std;



int main(){
    int tt; cin >> tt;
    while (tt--) {
        int x, n;
        long long y, z, w, t=0, t1, t2, t3;
        cin >> n;
        vector<long long> f(n+5);
        for (int i=0; i<n; i++) {
            cin >> x;
            f[x]+=1;
        }
        for (int i=1; i<=n; i++) {
            w=f[i]; y=f[i+1]; z=f[i+2];
            t1=w*(w-1)/2;
            t2=y*(y-1)/2;
            t3=z*(z-1)/2;
            t+=t1*y;
            t+=t1*z;
            t+=w*t2;
            t+=w*t3;
            t+=w*(w-1)*(w-2)/6;
            t+=w*y*z;
        }
        cout << t << endl;
    }
}