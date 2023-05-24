#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c=0;
    cin >> n;
    int x[n+2], z[150002]={0};
    z[0]=1;
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    sort(x, x+n);
    for (int i=0; i<n; i++) {
        int y = x[i];
        if(!z[y-1]) {
            c+=1;
            z[y-1]=1;
        } else if ( !z[y] ) {
            c+=1;
            z[y]=1;
        } else if (!z[y+1]) {
            c+=1;
            z[y+1]=1;
        }
    }
    cout << c;
}