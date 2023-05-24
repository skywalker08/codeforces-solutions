#include <bits/stdc++.h>

using namespace std;

int main(){ 
    const int maxe=1e5+2;
    int n, x, a, z;
    long long ans=0;
    cin >> n >> x;
    map<int, int> arr;
    for (int i=0;i<n;i++) {
        cin >> a;
        z=a^x;
        if (arr[z]) {
            ans+=arr[z];
        }
        arr[a]+=1;
    }
    cout << ans << endl;
    return 0;

}