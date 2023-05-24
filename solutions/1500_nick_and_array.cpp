#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[n];
    int ma=-10e6, mi=10e6;
    for (int i=0;i<n;i++) {
        cin >> x;
        if (x>=0) {
            arr[i]=x*(-1)-1;
        } else {
            arr[i]=x;
        }
        mi=min(arr[i],mi);
    }
    int flag=0;
    if (n%2) {
        flag=1;
    }
    for (int i=0;i<n;i++) {
        if (flag && arr[i]==mi) {
            cout << arr[i] * (-1)-1 << " ";
            flag=0;
            continue;
        }
        cout << arr[i] << " ";
    }
    return 0;
}