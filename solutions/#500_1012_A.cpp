#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n;
    n*=2;
    long long a[n];
    for (int i=0;i<n;i++) {
        scanf("%I64d", &a[i]);
    }
    sort(a, a+n);
    long long x, y;
    x = a[m-1] - a[0];
    y = a[n-1] - a[m];
    long long ans1 =  x * y;
    long long ans2 = 1e9+1;
    for (int i=1; i < m; i++) {
        ans2 = min(ans2, a[i + m - 1] - a[i]);
    }
    ans2 = ans2 * (a[n-1] - a[0]);
    cout << min(ans1, ans2);
    return 0;
}