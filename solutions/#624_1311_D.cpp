#include <bits/stdc++.h>

using namespace std;


const int N = 1e4+32;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ra, rb, rc, res=N*3;
        for (int i=1; i<=N; i++) {
            for (int j=i; j<=N; j+=i) {
                if (abs(a-i) + abs(b-j) + min(c%j, j - c%j) < res) {
                    res = abs(a-i) + abs(b-j) + min(c%j, j - c%j);
                    ra=i, rb=j;
                    if (c%j < j-c%j) rc = c - c%j;
                    else rc = c + j-c%j;
                }
            }
        }
        printf("%d\n%d %d %d\n", res, ra, rb, rc);
    }

    return 0;
}