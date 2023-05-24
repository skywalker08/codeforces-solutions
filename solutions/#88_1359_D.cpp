#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    long long ans=0;
    for (int mx=0;mx<31;mx++) {
        long long best = 0;
        long long cur = 0;
        for (int i=0;i<n;i++) {
            if (a[i] > mx) {
                cur += -INF;
            } else {
                cur += a[i];
            }
            best = min(best, cur);
            ans = max(ans, (cur - best) - mx);
        }
    }
    cout << ans;
    return 0;
}