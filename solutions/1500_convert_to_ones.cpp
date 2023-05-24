#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    string a;
    cin >> a;
    long long c=0, f=0;
    for (int i=0;i<n;i++) {
        if (a[i]=='0') {
            if (!f) c++;
            f=1;
        } else {
            f=0;
        }
    }
    if (c==0) {
        cout << c;
        return 0;
    }
    if (x>=y) {
        cout << c*y;
    } else {
        cout << (c-1)*x + y;
    }
    return 0;
}