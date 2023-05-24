#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k=0;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    for (int i=0; i<n; i++) {
        if (k<=0) {
            k+=arr[i];
        }
        else {
            k-=arr[i];
        }
    }
    if (!k) { cout << "YES" << endl;   }
    else {cout << "NO" << endl; }
    return 0;
}