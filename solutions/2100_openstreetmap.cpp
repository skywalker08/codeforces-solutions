#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<deque<ll>> deq;

void ins(deque<ll>& de, ll val) {
    while (!de.empty() && val < de.back()) {
        de.pop_back();
    }
    de.push_back(val);
}

void del(deque<ll>& de, ll val) {
    if (!de.empty() && de.front() == val) {
        de.pop_front();
    }
}

int main() {
    ll n, m, a, b, g, x, y, z;
    cin >> n >> m >> a >> b >> g >> x >> y >> z;
    int map[n][m];
    deq.resize(m);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            map[i][j]=g;
            g = (g*x+y) % z;
        }
    }

    for (int j=0; j<m; j++) {
        for (int i=0; i<a; i++) {
            ins(deq[j], map[i][j]);
        }
    }
    deque<ll> ct;
    ll ans=0;
    for (int i = 0; i < b; i++) {
        ins(ct, deq[i].front());
    }
    ans += ct.front();
    for (int i=b; i<m; i++) {
        ins(ct, deq[i].front());
        del(ct, deq[i - b].front());
        ans+=ct.front();
    }
    for (int i=a;i<n;i++) {
        for (int j=0; j<m; j++) {
            del(deq[j], map[i - a][j]);
            ins(deq[j], map[i][j]);
        }
        deque<ll> ct;
        for (int i = 0; i < b; i++) {
            ins(ct, deq[i].front());
        }
        ans += ct.front();
        for (int i=b; i < m; i++) {
            del(ct, deq[i - b].front());
            ins(ct, deq[i].front());
            ans+=ct.front();
        }
    }
    cout << ans << endl;
}