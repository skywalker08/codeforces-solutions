#include <bits/stdc++.h>

using namespace std;

int sum(long long num) {
    int sum=0;
    while (num > 0) {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int s;
        long long n, c=10, y, x, ans=0;
        cin >> n >> s;
        while (sum(n) > s) {
            x=n%c;
            x/=c/10;
            if ( x > 0) {
                y = (10 - x) * (c/10);
                ans += y;
                n += y;
            }
            c *= 10;
        }
        cout << ans << endl;
    }
    return 0;
}

