#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(ll k, ll n) {
    ll sum=0;
    ll c=n;
    while (c>0) {
        ll d=min(k, c);
        sum += d;
        c-=d;
        c-=c/10;
    }
    return sum >= (n+1) / 2;

}

int main() {
    ll n;
    cin >> n;
    ll l=1, r=n;
    ll ans=r;

    while (l <= r) {
        ll k=(l + r) /2;
        if (check(k, n)) {
            ans=k;
            r = k - 1;
        } else {
            l = k + 1;
        }
    }

    cout << ans << endl;
}