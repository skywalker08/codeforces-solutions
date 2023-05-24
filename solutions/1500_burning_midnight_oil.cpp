#include <bits/stdc++.h>

using namespace std;
long long n,k;

int bs(long long a) {
    
    long long s=0;
    while (a) {
        s+=a;
        a/=k;
    }
    return s>=n;

}

int main() {
    cin >> n >> k;
    long long l=0, r=(10e9), mid;
    while (l<=r) {
        mid = (l+r)/2;
        if (bs(mid)) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << mid;
}