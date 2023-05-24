#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int c = n-1;
        for (int i=0; i<n; i++) {
            int x = c;
            int a = 1;
            if ( !(i&1) && !(n&1) )  {
                cout << 0 << " ";
                x--;
                a = 0;
            }
            while (x) {
                if (a & 1) {
                    cout << 1 << " ";
                } else { cout << -1 << " ";}
                a ^= 1;
                x--;
            }
            c-=1;
        }
    }
}