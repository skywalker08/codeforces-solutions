#include <bits/stdc++.h>

using namespace std;

const int maxe=1e6+100;
int ct[maxe+1];

int main() {
    int n;
    scanf("%d", &n);
    int x, ans=0;
    for (int i=0;i<n;i++) {
        scanf("%d", &x);
        ct[x] += 1;
    }
    for (int i=0;i<=maxe;i++) {
        ct[i+1] += ct[i]>>1; 
        ans += ct[i] & 1;
    }
    cout << ans;
    return 0;
}