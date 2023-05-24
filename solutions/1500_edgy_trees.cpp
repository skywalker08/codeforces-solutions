#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxE= 1e5+1;
const long long mod = 1e9+7;

int pinkvis[maxE], pinkc=1;
vector<pair<int, int>> adj[maxE];

long long dfs(int v) {
    pinkvis[v] = 1;
    long long pinkc=0;
    for (auto u: adj[v]) {
        if (!pinkvis[u.first]) {
            if (u.second==0) {
                pinkvis[u.first]=1;
                pinkc += dfs(u.first);
            }
        }
    }
    return pinkc+1;
}

ll ipow(ll b, ll t) {
    ll r=1;
    while(t) {
        if(t&1) {r = (r * b) % mod;}
        b = (b * b) % mod;
        t>>=1;
    }
    return r;
}

int main() {
    int n, k;
    cin >> n >> k;
    int x, y, z;
    long long ans=0, count, anst;
    for (int i=0; i<n-1; i++) {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    for (int i=1; i<=n; i++) {
        if (pinkvis[i]==0) {
            anst=0;
            count = dfs(i);
            for (int j=2; j<=k; j++) {
                ll w = k-1-k+j-1;
                ll r = k-j;
                ll v = n;
                anst+=((ipow(v, r) * ( v-count )) % mod  * ipow(count, w)) % mod;
            }
            ans = ans + (count * anst);
            ans+=mod;
            ans%=mod;

        }
    }
    cout << ans << endl;

}