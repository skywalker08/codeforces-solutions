#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll ipow(ll b, ll t) {
    ll r=1;
    while(t) {
        if(t&1){r = r * b % mod;}
        b= b * b % mod;
        t>>=1;
    }
    return r;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll x = ipow(2, m) - 1;
    ll ans = ipow(x, n);
    cout << ans;
}