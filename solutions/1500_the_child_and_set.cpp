#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum, n;
    cin >> sum >> n;
    vector<int> ans;
    int num, z;
    for (int i=n;i>0;i--) {
        num=i;
        z=1;
        while (num%2==0) {
            num = num >> 1;
            z *= 2;
        }
        if ((sum-z)>=0) {
            sum-=z;
            ans.push_back( i );
        } if (sum == 0) {
            break;
        }
    }
    if (sum>0) {
        cout << -1;
        return 0;
    }
    n=ans.size();
    cout << n << endl;
    for (int i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}