#include <bits/stdc++.h>
using namespace std;

const int maxe = 1e5+1;
int n, k;
int a[maxe * 2];

bool check(int m, int cc) {
    int size = 0;
    for (int i=0;i<n;i++) {

        if (!cc) {
            size++;
            cc^=1;
        } 
        else {
            if (a[i] <= m) {
                cc^=1;
                size++;
            }
        }
    }

    if (size >= k) { return true; }
    return false;

}

int binse(int l, int r) {
    while(l < r) {
        int m=(l+r)/2;
        if (check(m, 0) || check(m, 1)) {
            r = m;
        } else {
            l = m + 1;
        } 
    }
    return l;
}

int main() {
    
    cin >> n >> k;    
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = binse(0, 1e9);
    cout << ans;
    return 0;
}