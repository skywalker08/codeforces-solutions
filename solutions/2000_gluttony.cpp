#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> ans;
    int arr[n], sortd[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        sortd[i]=arr[i];
    }
    sort(sortd, sortd+n);
    for (int i=0;i<n;i++) {
        ans[sortd[i]] = sortd[(i+1) % n];
    }
    for (int i=0;i<n;i++) {
        cout << ans[arr[i]] << " ";
    }
    return 0;
}