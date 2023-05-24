#include <unordered_map>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

unordered_map<ll, ll> m;
ll LCA(ll v, ll u, ll w = 0) { // Lowest Common Ancestor
    ll r = 0;
    while (v != u) {
        if (v < u) {
            ll temp = u;
            u = v;
            v = temp;
        }
        if (m.find(v) != m.end()) r += m[v];
        if (w) m[v] += w;
        v >>= 1;
    }
    return r;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int typ;
        ll v, u;
        cin >> typ;
        scanf("%lld%lld", &v, &u);
        if (typ == 1) {
            ll w;
            cin >> w;
            LCA(v, u, w);
        }
        else {
            cout << LCA(v, u) << "\n";
        }
    }
    return 0;
}