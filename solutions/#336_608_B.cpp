#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int ct0=0, ct1=0;
    for (int i=0; i + a.size() < b.size(); i++) {
        if (b[i]=='1') {
            ct1 += 1;
        } else if (b[i]=='0') {
            ct0 += 1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if ( b[(b.size() - a.size()) + i] == '0') ct0++;
        else ct1++;
        if ( a[i] == '0' ) ans += ct1;
        else ans += ct0;
        if ( b[i] == '0' ) ct0--;
        else ct1--;
    }
    cout << ans;
}