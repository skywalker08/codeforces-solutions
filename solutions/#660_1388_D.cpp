#include <bits/stdc++.h>
 
const int MAXE=2e5+5;
long long a[MAXE];
int vp[MAXE];
std::deque<int> anss;
int lock[MAXE];
bool vis[MAXE];
 
void dfsp(int u) {
    vis[u] = true;
    int v = vp[u];
    if (v==0) {
        anss.push_back(u);
        return;
    }
    lock[v]--;
    if (a[u] >= 0) {
        anss.push_back(u);
        a[v] += a[u];
    }
    if (lock[v]==0) {
        dfsp(v);
    }
}
 
void dfsn(int u) {
    vis[u] = true;
    int v = vp[u];
    if (v == 0) {
        return;
    }
    if (a[v] < 0 && vis[v]==false) {
        dfsn(v);
    }
    anss.push_back(u);
}
 
 
 
int main() {
    int n;
    scanf("%d", &n);
    memset(vp, 0, sizeof(vp));
    memset(lock, 0, sizeof(lock));
    memset(vis, false, sizeof(vis));
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    } int x;
    for (int i=1; i<=n; i++) {
        scanf("%d", &x);
        if (x==-1) {
            continue;
        }
        vp[i] = x;
        lock[x]++;
    }
    for (int i=1; i<=n; i++) {
        if (lock[i]==0 && vis[i] == false) {
            dfsp(i);
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i=1; i<=n; i++) {
        if (a[i] < 0 && vis[i] == false) {
            dfsn(i);
        }
    }
    long long ct=0;
    for (int i=1; i<=n; i++) {
        ct += a[i];
    }
    printf("%lld\n", ct);
    for (int i=1; i<=n; i++) {
        printf("%d ", anss.front());
        anss.pop_front();
    }
}