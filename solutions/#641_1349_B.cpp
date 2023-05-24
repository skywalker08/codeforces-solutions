#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int tt=1;
    cin >> tt;
    while (tt--){
        int n, k;
        scanf("%d%d", &n, &k);
        int x=0, a[n+10]={0};
        for (int i=2;i<=n+1;i++) {
            scanf("%d", &a[i]);
            if (k == a[i]) {
               x=1; 
            }
        }
        if (x&&n==1) {
            printf("yes\n");
            continue;
        }
        int i=2, f = 0;
        while (i<=n+1) {
            if (a[i]>=k) {
                if (a[i-2] >= k || a[i-1] >= k ||a[i+1] >= k || a[i+2] >= k) {f=1; break;}
            }
            i++;
        }
        if (f&&x) printf("yes\n");
        else printf("no\n");
    }
}