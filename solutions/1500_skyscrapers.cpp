#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ll n;
    cin >> n;
    ll arr[n+3]={0};
    for (int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    ll temp, t, mn=0, peak;
    for (int i=1;i<=n;i++) {
        t=arr[i];
        temp = arr[i];
        for (int j=i-1; j>=1; j--) {
            t+=min(temp, arr[j]);
            temp=min(temp, arr[j]);
        }
        temp=arr[i];
        for (int j=i+1; j<=n; j++) {
            t+=min(temp, arr[j]);
            temp=min(temp, arr[j]);
        }
        if (t>mn) {
            mn=t;
            peak=i;
        }
    }
    temp=arr[peak];
    for (int i=peak-1; i>=1; i--) {
        arr[i]=min(temp, arr[i]);
        temp=min(arr[i], temp);
    }
    temp=arr[peak];
    for (int i=peak+1; i<=n; i++) {
        arr[i]=min(temp, arr[i]);
        temp=min(arr[i], temp);
    }
    for (int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

