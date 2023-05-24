#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b;
        cin >> a >> b;
        long long x = max(a,b);
        b = min(a,b);
        a = x;
        long long i = 1, c = 0;
        while (a-b >= i ) {
            c += 1;
            b += i;
            i++;
        }
        cout << a << " "<<b <<" " << c << " " ;
        if (a-b) {
            c += (a-b) * 2;
        }
        cout << c << endl;
    }
    return 0;
}