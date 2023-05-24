#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int stairs[n+1];
    for (int i=1;i<=n;i++) {
        scanf("%d", &stairs[i]);
    }
    int m;
    cin >> m;
    int w, h;
    long long max=0;
    for (int i=0;i<m;i++) {
        scanf("%d%d", &w, &h);
        if (stairs[w]>max) {
            printf("%d\n", stairs[w]);
            max=stairs[w]+h;
        } else {
            printf("%I64d\n", max);
            max=max+h;
        }
    }
}