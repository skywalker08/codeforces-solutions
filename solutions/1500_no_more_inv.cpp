#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        int a = n-k;
        int i;
        for (i=1; i<k-a; i++) {
            cout << i << " ";
        }
        for (int j=k; j>=i; j--) {
            cout << j << " ";
        }
        cout << endl;
       
    }
     return 0;
}