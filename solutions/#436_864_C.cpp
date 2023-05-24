#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int pos=0;
    int b1 = b;
    int ct = 0;
    while (k>0) {
        if (b1 < f && pos == 0)  {
            cout << "-1";
            return 0;
        } else if ( b1 < (a - f) && pos==1) {
            cout << "-1";
            return 0;
        }
        int x = b1 % a;
        int y = b1 / a;
        k = k - y;
        if (k <= 0) {
            break;
        }
        if ( (y+pos) % 2) {
            if (x >= a - f) {
                b1 = b - f;
                if (b < f) {
                    cout << -1;
                    return 0;
                }
                pos=0;
                ct++;
                k--;
            } else {
                b1 = b - (a-f);
                pos=1;
                ct++;
            }
        } else {
            if (x >= f) {
                b1 = b - (a - f);
                if (b < (a-f)) {
                    cout <<-1;
                    return 0;
                }
                pos=1;
                ct++;
                k--;
            } else {
                b1 = b - f;
                pos=0;
                ct++;
            }
        }
    }
    cout << ct;
    return 0;
}