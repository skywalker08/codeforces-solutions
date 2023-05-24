#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    long long dish[n], cost[n];
    long long x;
    for (int i=0;i<n;i++) {
        scanf("%lld", &x);
        dish[i]=x;
    }
    for (int i=0;i<n;i++) {
        scanf("%lld", &x);
        cost[i]=x;
    }
    int sortedindex[n];
    iota(sortedindex, sortedindex+n, 0);
    stable_sort(sortedindex, sortedindex+n, [&cost](int i, int j) {return cost[i] < cost[j];});
    int j=0;
    long long y;
    for (int i=0;i<m;i++) {
        long long ans=0;
        scanf("%d%lld", &x, &y);
        x-=1;
        if (dish[x] > 0) {
            if (dish[x] >= y) {
                dish[x] -= y;
                ans+=cost[x] * y;
                y=0;
            } else {
                ans += dish[x] * cost[x]; 
                y -= dish[x];
                dish[x]=0;
            }
        }        
        while (y>0 && j<n) {
            x=sortedindex[j];
            if (dish[x] > 0) {
                if (dish[x] >= y) {
                    dish[x]-=y;
                    ans += cost[x] * y;
                    y=0;
                } else {
                    ans += dish[x] * cost[x]; 
                    y -= dish[x];
                    dish[x]=0;
                }
            } else {
                j+=1;
            }
        }
        if (y>0) {
            ans=0;
        }
        cout << ans << endl;
    }

    return 0;
}