#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n=a.size();
    int m=b.size();
    if (n!=m ) {
        cout << "NO" << endl;
        return 0;
    }
    int f1=0, f2=0;
    for (int i=0;i<n;i++) {
        if (a[i]=='1') {
            f1=1;
        }
        if (b[i]=='1') {
            f2=1;
        }
    }
    if (f1 == f2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}