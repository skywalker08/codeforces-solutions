#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r, x, m, f=0;
        cin >> l >> r >> m;
        long long a, b, c;
        long long y = r-l;
        for (long long i=l; i<=r; i++) {
            x = m%i;
            if (x <= y) {
                a=i;
                break;
            }
            else if (i-x <= y) {
                x = i-x;
                a=i;
                f=1;
                break;
            }
        }
        if (m<l) {
            a=l;
            x=l-m;
            c=l+x;
            b=l;
        }
        else if (f==1) {
            c=l + x;
            b=l;
        }
        else {
            b=l + x;
            c=l;
        }
        cout << a << " " << b << " "  << c << endl;
    }
}