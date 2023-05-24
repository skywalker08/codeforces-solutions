#include <bits/stdc++.h>
#include <math.h>


using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, cnt=0;
        cin >> n;
        for (int i=2; i*i<= 2 * n - 1 ; i++) {
            if ( (i * i)%2 ) {
                cnt+=1;
            }
        }
        cout << cnt << endl;
    }
    return 0;

}