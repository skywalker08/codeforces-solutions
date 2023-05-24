#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, p, w, d, x, y, z;
    cin >> n >> p >> w >> d;
    ll k, b = p/w, e=min(n, p/d);
    int f=0;
    if (p%__gcd(w,d)==0) {
        for (k=b; k<=e; k++) {
            if(((p-(d*k))%(w-d)==0)&&((((w*k)-p)%(w-d)==0))) {
                y=((w*k)-p)/(w-d);
                x=(p-(d*k))/(w-d);
                f=1;
                if (x<0 || y<0) {
                    f=0;
                    continue;
                }
                break;
            }
        }
    }
    if (!f) {
        cout << -1 << endl;
    }
    else {
        cout << x << " " << y << " " << (n-k) << endl;
    }
    return 0;
}