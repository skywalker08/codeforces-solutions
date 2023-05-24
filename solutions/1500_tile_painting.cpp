#include <bits/stdc++.h>

using namespace std;

long long findprimes(long long x) {
    long long y=x, z;

    if (x%2==0) {
        z=x;
        while (z % 2==0 ) {
            z/=2;
        }
        if (z==1) {
            y=2;
        }
        else {
            return 1;
        }
    }

    for (long long i=3; i * i <= x; i+=2) {
        z=x;
        while (z % i == 0 ) {
            z/=i;
        }
        if (z==1) {
            return i;
        }
        else if (z!=x) {
            return 1;
        }
    }
    
    return y;
}

int main() {
    long long n;
    cin >> n;
    cout << findprimes(n);
    return 0;    
}