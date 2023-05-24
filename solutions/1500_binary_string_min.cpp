#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll k, c=0;
        int n;
        cin >> n >> k;
        int i=0, j=0;
        string str;
        cin >> str;
        while (k>0) {
            if (str[i]=='1') {
                c+=1;
                i+=1;
            } else if ( i == n ) {
                break;
            } else {
                if (c>=k) {
                    j += c-k;
                    k=0;
                }
                k-=c;
                str[i]='1';
                str[j]='0';
                j+=1;
                i+=1;
            }
        }
        cout << str << endl;
    }
    return 0;
}