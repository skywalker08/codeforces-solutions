#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    int n=a.size(), ans=0;
    for (int i=0;i<n - 1;i++) {
        int f=-1, fa=-1, fb=-1;
        for (int j=i; j<i+2; j++) {
            if (a[j]=='0' && b[j]=='0' && f==-1) {
                f=j;
            } else if (a[j]=='0') {
                fa=j;
            } else if (b[j]=='0') {
                fb=j;
            }
        }
        if (f>-1 && (fa>-1 || fb>-1)) {
            ans+=1;
            a[f]='X', b[f]='X';
            a[fa]='X', b[fb]='X';
        }
    }
    cout << ans;
    return 0;
}