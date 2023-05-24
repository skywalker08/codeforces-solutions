#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n+3];
    int x;
    for (int i=1;i<=n;i++) {
        cin >> x;
        if (x<0) {x = x * (-1);}
        arr[i]=x;
    }
    sort(arr+1, arr+n+1);
    long long ans=0;
    int i=n,j=n-1;
    while (j>0) {
        while( (arr[i]+1)/2 <= arr[j] ) {
            if (j==1) {
                ans+=1;
                break;
            }
            j--;
        }
        ans += i-j-1;
        i--;
        if (i==j) {
            j--;
        }
    }
    cout << ans;

}