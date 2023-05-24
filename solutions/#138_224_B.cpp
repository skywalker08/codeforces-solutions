#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int used[100005]={0}, a[n], x, c=0;
    for (int i=0;i<n;i++) {
        scanf("%d", &x);
        a[i]=x;
        if (!used[x]) {
            c+=1;
        }
        used[x]+=1;
    }
    if (c<k) {
        cout << -1 << " " << -1;
        return 0;
    }
    int l, r, f=1;
    for (int i = 0; i < n; i++) {
        if (f) {
            used[a[i]]--;
        }
        if (used[a[i]] <= 0 && f) {
            l=i+1;
            f=0;
            k--;
            if (k==0) {
                r = l;
                break;
            }
            continue;
        }
        if (used[a[i]] > 0 && f==0) {
            used[a[i]] = 0;
            k--;
        }
        if (k <= 0) {
            r = i + 1;
            break;
        }
    }
    cout << l << " " << r;
    return 0;
}