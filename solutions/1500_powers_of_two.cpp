#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[n];
    int ans=0;
    for (int i=0;i<n;i++ ){
        cin >> arr[i];
    }
    for (int i=0; i<n;i++) {
        for (int j=i+1; j<n; j++) {
            x = arr[i] + arr[j];
            if (! ( x & (x-1) ) ) {
                ans+=1;
            } 
        } 
    }
    cout << ans << endl;
}