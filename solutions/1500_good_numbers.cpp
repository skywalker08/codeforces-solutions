#include <bits/stdc++.h>

using namespace std;

unsigned long long int ipow( unsigned long long int base, int exp )
{
    unsigned long long int result = 1LL;
    while( exp )
    {
        if ( exp & 1 )
        {
            result *= base;
        }
        exp >>= 1;
        base *= (unsigned long long int)base;
    }
    return result;
}

int main() {
    int arr[100]={0};
    int tt;
    cin >> tt;
    while (tt--) {
        memset(arr, 0, 100);
        unsigned long long n;
        cin >> n;
        unsigned long long z = n, v = 1LL, sum = 0, p;
        int x = 100;
        while ( x>0 && z>0 ) {
            for (int i=0; i < x; i++) {
                if (ipow(3, (i+1)) > z || i == x-1) {  
                    z=z - ipow(3,i);
                    x = i;
                    arr[i]=1;
                }
            }
        }
        if ( !z ) {
            cout << n << endl;
        } else if ( z > 0 ) {
            for (int i=0; i<100; i++) {
                p=ipow(3, i);
                if (arr[i]) {
                    sum += p;
                }
                else if ( p > n ) {
                    cout << p << endl;
                    break;
                } else if (  n + p - sum - z >= n) {
                    cout << p + n - sum - z << endl;
                    break;
                }
            }
        }
    }
}