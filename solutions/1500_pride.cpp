#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int c=0;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        if (arr[i]==1) {
            c+=1;
        }
    }
    if (c>0) {
        cout << n-c << endl;
        return 0;
    }
    int i=0;
    vector<int> t;
    int ans=2001;
    for(int i=0;i<n-1;i++) {
        int x = __gcd(arr[i], arr[i+1]);
        for (int j=i+1;j<n;j++) {
            if (__gcd(x, arr[j])==1) {
                ans=min(ans, j-i);
                break;
            }
        }
    }
    if (ans==2001) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans + n-1 << endl;
}