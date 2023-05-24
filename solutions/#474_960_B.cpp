#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int a[n], b[n], x;
    for (int i=0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<long long> c(n);
    for (int i=0;i < n; i++) {
        scanf("%d", &b[i]);
        c[i]=abs(a[i]-b[i]);
    }
    int k=k1+k2;
    sort(c.begin(), c.end(), greater<int>());
    int z=1;
    int j, m;
    for (int i=0; i<n; i++) {
        if (i == n-1) {
            int d = c[i];
            k -= z * d;
            m=0;
            j=n;
            break;
        }
        int d = c[i]-c[i+1];
        k -= z * d;
        if (k <= 0) {
            m = c[i+1];
            j = i + 1;
            break;
        }
        z++;
    }
    // cout << j <<" " << m << " " << z << " " << k << " ";
    int t=0, f=0;
    if (k>0) {
        t = k % 2;
    }
    if (k < 0) {
        k = k * (-1);
        f = k / z;
        t = k % z;
    }
    for (int i = 0; i < j; i++) {
        c[i] = m + f;
        // cout << c[i] << " ";
    }
    // cout << t << " ";
    long long ans = 0;
    for (int i=0; i<n; i++) {
        if (t > 0) {
            c[i] += 1;
            t--;
        }
        ans += c[i] * c[i];
    }
    cout << ans;
}