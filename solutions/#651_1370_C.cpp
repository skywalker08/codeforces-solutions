#include <bits/stdc++.h>

using namespace std;

bool isitprime(int n) {
    bool r = true;
    for (int i=3; i * i<=n; i+=2) {
        if (n%i==0) {
            r = false;
            break;
        }
    }
    return r;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        string winner[2]={"Ashishgup", "FastestFinger"};
        int i=0;
        int n;
        cin >> n;
        if (n%2==0) {
            int x=n;
            int ct=0;
            while (x) {
                if (x%2) {
                    ct++;
                }
                x>>=1;
            }
            if (ct>1) {
                n>>=1;
                if (n%2==1) {
                    if (isitprime(n)) {
                        i^=1;
                    }
                }
            } else {
                if ((n>>1) != 1) {
                    i^=1;
                }
            }
        } else {
            if (n==1) {
                i^=1;
            }
        }
        cout << winner[i] << endl;
    }
    return 0;
}