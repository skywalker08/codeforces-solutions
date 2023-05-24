#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x, t=0, bt, mt, ind, f=1, m=0;
    cin >> n;
    map<int,int> map1;
    map1[0]+=1;
    int arr[n], ans[n+5];
    for (int i=0;i<n-1;i++) {
        cin >> x;
        arr[i]=x;
        t+=x;
        map1[t]+=1;
        if (x >= n || x * -1>=n) {
            f=0;
        }
    }
    for (auto &item : map1 ) {
        if (item.second > 1 || item.first>=n || item.first*-1 >= n) {
            f=0;
            break;
        }
    }
    ans[0]=n;
    for (int i=0;i<n-1; i++) {
        ans[i+1] = ans[i] + arr[i];
        if (ans[i+1] < 0) {
            f=0;
        }
        if (ans[i+1]>n) {
            m = max(m, ans[i+1]-n);
        }
    }
    for (int i=0; i<n; i++) {
        ans[i]-=m;
        if (ans[i] < 1) {
            f=0;
        }
    }
    if (f) {
        for (int i=0;i<n;i++) {
            cout << ans[i] << " ";
        }
    }
    else { cout << -1 << " ";}
    return 0;
}