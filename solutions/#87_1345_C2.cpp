#include <bits/stdc++.h>

using namespace std;

const double PI = acos(0);

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        double n;
        cin >> n;
        n *= 2;
        double theta = PI / n;
        double ans = cos(theta / 2) / sin(theta);
        cout << setprecision(9);
        cout << fixed;
        cout << ans << endl;
    }
}