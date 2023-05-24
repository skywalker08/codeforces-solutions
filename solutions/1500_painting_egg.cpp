#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long a, b, sa=0, sb=0;
    string ans;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        if (llabs(a+sa-sb)<=500) {
            sa+=a;
            ans+='A';
        } else {
            sb+=b;
            ans+='G';
        }
    }
    cout << ans << endl;
    return 0;
}