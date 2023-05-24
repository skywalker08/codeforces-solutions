#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, k;
    cin >> n;
    int cnt[n+6]={0};
    pair<int, int> p[n];
    for (int i=0; i<n-1; i++) {
        cin >> x >> y;
        p[i].first=x;
        p[i].second=y;
        cnt[x]+=1;
        cnt[y]+=1;
        if (cnt[x]==3) {
            k=x;
        }
        else if (cnt[y]==3) {
            k=y;
        }
    }
    int z=0, w=n;
    for (int i=0; i<n-1; i++) {
        if (p[i].first==k || p[i].second==k) {
            cout << z << endl; z+=1;
        }
        else {
            cout << w-2 << endl; w-=1;
        }
    }
    return 0;

}