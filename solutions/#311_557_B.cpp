#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    float w;
    cin >> n;
    cin >> w;
    int ma=n*2;
    int pots[ma];
    float zero, middle, x;
    for (int i=0; i < ma; i++) {
        cin >> pots[i];
    }
    sort(pots, pots+ma);
    zero = pots[0];
    middle = pots[n];
    float ans = w;
    float t;
    x = w / (3 * n);
    if (x > zero) {
        t = zero * 2;
        if ( t <= middle) {
            ans = 3*zero*n;
        } else if ( t > middle) {
            ans = (3 *middle*n) / 2;
        }
    } else if (x * 2 > middle) {
        t=middle/2;
        if ( t <= zero) {
            ans = (3 *middle*n) / 2;
        } else if ( t > zero) {
            ans = 3 * zero * n;
        }
    } cout << setprecision(10);
    cout << fixed;
    cout << ans;
    return 0;
}