#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt=0, y=0;
    cin >> n;
    int arr[n];
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    v.push_back(arr[n-1]);
    int x = n/2;
    for (int i = x-1; i>=0; i--) {
        if (i+x==n-1) { y=arr[i]; continue;}
        if (arr[i]<arr[i+x]) cnt+=1;
        v.push_back(arr[i]);
        v.push_back(arr[i+x]);
    }
    cout << cnt << endl;
    if (y) { v.push_back(y); }
    for (int i=0; i<n; i++ ) {
        cout << v[i] << " ";
    }
    return 0;
}