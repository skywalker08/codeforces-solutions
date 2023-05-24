#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// vector<int> v;

int ans;
int n, k;
set<ll> arr;
set<ll>::iterator itr;


void add(int f, ll x) {
    ll z=x*k;
    if (arr.find(z) != arr.end() && k!=1) {
        if(f) {
            add(0, z);
        } else {
            add(1, z);
        }
    }
    if (f) {
        // v.push_back(x);
        ans+=1;
    }
    arr.erase(x);
}

int main() {
    ll x;
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> x;
        arr.insert(x);
    }
    ;
    while(arr.size()>0) {
        itr=arr.begin();
        x=*itr;
        add(1, x);
    }
    // for (int i=0;i<v.size();i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    cout << ans;
    return 0;
}