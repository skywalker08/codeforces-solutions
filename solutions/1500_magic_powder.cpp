#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
const int maxe = 1e5+5;
int b[maxe], a[maxe], c[maxe], powder[maxe];

int ans=0;
bool sortF(int x, int y) {
    return b[x] < b[y];
}

void binsearch(int l, int r) {
    if (r>=l) {
        ll mid = (r+l) / 2;
        ll ke=k;
        ll t = b[c[mid]];
        ll flag=1;
        ll div=0;
        for (int i=0; i < mid; i++) {
            ke -= (t * a[c[i]]) - powder[c[i]];
            if (ke<0) {
                flag=0;
                break;
            }
        }
        if (flag) {
            binsearch(mid+1, r);
        } else {
            binsearch(l, r-1);
        }
    } 
    else {
        ll ke = k;
        ll div = a[c[r]];
        ll t = b[c[r]];
        ll sum=0;
        for (int i=0;i<l-1;i++) {
            ke -= (t * a[c[i]]) - powder[c[i]];
            div += a[c[i]];
        }
        ke += powder[c[r]] % a[c[r]];
        sum = ke / div;
        ans = t + sum;
    }
}

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        powder[i]=x;
        b[i] = x / a[i];
    }
    iota(c, c+n, 0);
    sort(c, c+n, sortF);
    binsearch(0, n-1);
    cout << ans;
    return 0;
}