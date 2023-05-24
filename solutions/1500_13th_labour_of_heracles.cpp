#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt; while (tt--){
        int we, n, x, y, t=0;
        cin >> n;
        int w[n+5], c[n+5]={0};
        vector<int> v[n+5];
        for (int i=1; i<=n; i++) {
            cin >> we;
            w[i]=we;
            t+=we;
        }
        for (int i=0;i<n-1;i++) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
            c[x]+=1;
            c[y]+=1;
        }
        int pu=0, pv, px;
        cout << t << " "; 
        for (int i=0; i<n-2; i++) {
            for (int j=1; j<=n; j++) {
                if (c[j] == 1) {
                    for (auto u: v[j]) {
                        if (c[u] > 0) {
                            pu = max(w[u], pu);
                            if (pu == w[u]) { pv=j; px = u; }
                        }
                    }
                }
            }        
            c[px]-=1;
            c[pv]-=1;
            t+=w[px];
            pu=0;
            cout << t << " ";
        }
    }
}