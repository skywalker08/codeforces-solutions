#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long int n;
    cin >> n;
    if (n<3) {
        cout << -1;
        return 0;
    }
    if (n%2) {
        unsigned long long int x=(n*n)/2;
        cout << x << " " << x+1; 
    }
    else {
        unsigned long long int x=(n*n)/4;
        cout << x-1 << " " << x+1;
    }
}