#include <bits/stdc++.h>

using namespace std;

const int maxe=1e5+1;
vector<vector<int>> v(maxe);
int ans[maxe]={0}, n;
void dfs(int i, int d) {
    ans[d] ^= 1;
    for (auto u: v[i]) {
        dfs(u, d+1);
    }
}

int main() {
    cin >> n;
    int x;
    for (int i=2; i <= n; i++) {
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1, 1);
    int ct=0;
    for (int i=0; i<=n; i++) {
        ct+=ans[i];
    }
    cout << ct;
    return 0;
}