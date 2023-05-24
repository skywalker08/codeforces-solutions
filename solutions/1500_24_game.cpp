#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n<4) {
        cout << "NO" <<endl;
        return 0;
    }
    cout << "YES" << endl;
    int f=0, ct=0;
    while (n > 5) {
        ct+=1;
        printf("%d - %d = %d\n", n-1, n, -1);
        n-=2;
    }
    int b = ct%2;
    int z=n;
    while (ct > b) {
        printf("%d * %d = %d\n", z, -1, z * -1);
        z *= -1;
        ct-=1;
    }
    if (z == 5) {
        if (b) {
            printf("%d * %d = %d\n", -1, 1, -1);
            printf("%d + %d = %d\n", 5, -1, 4);
        } else {
            printf("%d - %d = %d\n", 5, 1, 4);
        }
        printf("%d - %d = %d\n", 4, 2, 2);
    }
    if (z == 4) {
        if (b) {
            printf("%d + %d = %d\n", -1, 1, 0);
            printf("%d + %d = %d\n", 4, 0, 4);
        } else {
            printf("%d * %d = %d\n", 4, 1, 4);
        }
    }
    printf("%d * %d = %d\n", 4, 2, 8);
    printf("%d * %d = %d\n", 8, 3, 24);
    return 0;

}