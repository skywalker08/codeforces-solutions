#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int m1=0, m2=0;
    char s;
    int x, y;
    int f;
    for (int i=0;i<n;i++) {
        scanf(" %c", &s);
        scanf("%d%d", &x, &y);
        if (x < y) {
            f=x;
            x=y;
            y=f;
        }
        if(s == '+') {
            m1=max(m1, x);
            m2=max(m2, y);
        } else {
            if (x < m1 || y < m2) {
                printf("%s", "NO\n");
            } else {
                printf("%s", "YES\n");
            }
        }
    }
    return 0;
}