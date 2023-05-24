#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int arr[n];
        int x, px=-1, c=0, l=0, f=1,e=0, ma=0;
        for (int i=0;i<n;i++) {
            cin >> x;
            ma = max(ma, x);
            if (px>-1) {
                if (px > x) {
                    if (c) {
                        if (px-x != c) f=0;
                    } else {
                        c = px - x;
                    }
                } else if (px < x) {
                    if (l) {
                        if (x - px != l) f=0;
                    } else {
                        l = x - px;
                    }
                } else if (px==x) {
                    
                    e=1;
                }
            }
            px=x;
        }
        int m = c + l;
        if (f==0) {
            cout << -1 << endl;
        } else if (e) { 
            if (l || c) {
                cout << -1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if ( c==0 || l==0 ) {
            cout << 0 << endl;
        } else  if (ma >= m) {
            cout << -1 << endl;
        } else {
            cout << m << " " << l << endl; 
        }
    }
}