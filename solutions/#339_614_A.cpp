#include <bits/stdc++.h>

using namespace std;
const long long lim=10e9;

int main() {
    long long l,r,k;
    cin >> l >> r >> k;
    long long x = 1;
    int f=1;
    while (x <= r) {
        if (l <=x ) {
            cout << x << " ";
            f = 0;
        }
        if (r / k >= x) {
            x*=k;
        } else break;
    }
    if (f) {
        cout << -1 << endl;
    }
    return 0;
}