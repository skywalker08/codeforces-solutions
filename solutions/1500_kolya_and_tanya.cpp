#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll powi(ll x, ll y) {
    ll r=1;
    for (int i=0; i<y; i++) {
        r = (x * r) % mod;
    }
    return r;
}

int main() {
    ll n, x=3, y=7;
    cin >> n;
    ll ans;
    ans = powi(x, n*x) - powi(y, n) + mod;
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}