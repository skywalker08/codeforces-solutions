#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, q, mxi, x, mx=0;
    cin >> n >> q;
    deque<int> arr(n);
    for (int i=0;i<n;i++) {
        cin >> x;
        arr[i]=x;
        mx=max(mx,x);
        if (x==mx) {
            mxi=i;
        }
    }
    vector<pair<int, int>> anss;
    for (int i=0;i<mxi;i++) {
        anss.push_back(make_pair(arr[0], arr[1]));
        if (arr[0] > arr[1]) {
            x=arr[0];
            arr.push_back(arr[1]);
            arr.pop_front();
            arr.pop_front();
            arr.push_front(x);
        } else {
            arr.push_back(arr[0]);
            arr.pop_front();
        }
    }
    ll mj, index;
    vector<pair<int, int>> ans;
    for (int i=0;i<q;i++) {
        cin >> mj;
        if (mj>mxi) {
            index=(mj - (mxi+1)) % (n-1) + 1;
            ans.push_back(make_pair(mx, arr[index]));
        } else {    
            ans.push_back(anss[mj-1]);
        }
    }
    for (int i=0;i<q;i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}