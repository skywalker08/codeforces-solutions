#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, ans=1e9;
    cin >> n >> m;
    int arr1[n], arr2[n];
    for (int i=0;i<n;i++) {
        cin >> arr1[i];
    }
    for (int i=0;i<n;i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);
    int j, z, flag, f, px=-1, x;
    for (int i=0;i<n;i++) {
        if (arr2[0]>=arr1[i]) {
            x=arr2[0]-arr1[i];
        }
        else {
            x=(m-arr1[i])+arr2[0];
        }
        if (px==x){
            continue;
        }
        px=x;
        j=i+1;
        z=1;
        flag=1;
        while (z<n) {
            if (j==n) {
                j=0;
            }
            if ((arr1[j]+x) % m != arr2[z]) {
                flag=0;
                break;
            }
            j+=1;
            z+=1;
        }
        if (flag) {
            ans=min(ans,x);
        }
    }
    cout << ans;
}