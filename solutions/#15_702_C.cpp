#include <bits/stdc++.h>

using namespace std;



int main() {
    int n,m;
    cin >> n >> m;
    int c[n], t[m];
    int x;
    for (int i=0;i<n;i++) {
        scanf("%d", &x);
        c[i]=x;
    }
    for (int i=0;i<m;i++) {
        scanf("%d", &x);
        t[i]=x;
    }
    int ans=0, p=0;
    for (int i=0;i<n;i++) {
        while ((abs( c[i] - t[p] ) >= abs(c[i] - t[p + 1])) && (p < m-1) ) p++;
        ans=max(ans, abs(c[i] - t[p]));
    }
    cout << ans;

    return 0;

}