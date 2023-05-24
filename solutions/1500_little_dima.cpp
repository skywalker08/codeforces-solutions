#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll s(ll x) {
    if (x<0) return -1;
    ll y=0;
    while (x) {
        y+=x%10;
        x/=10;
    }
    return y;
}

ll powi(ll a, ll b) {
    ll r=1;
    for (int i=0; i<b; i++) {
        r *= a;
    }
    return r;
}

int main() {
    ll a,b,c;
    ll x;
    cin >> a >> b >> c;
    vector<ll> v;
    int co=0;
    for (ll i=1; i <= 81; i++) {
        x = b * powi(i, a) + c;
        if ( s(x)==i && x < 1000000000 ) { 
            v.push_back(x);
            co++;
        }
    }
    cout << co << endl;
    for (int i=0; i<co; i++) {
        cout << v[i] << " ";
    } 
}