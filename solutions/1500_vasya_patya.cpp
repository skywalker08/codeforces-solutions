#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, prime=1;
    cin >> n;
    vector<int> ans;
    for (int i=2; i<=n; i++) {
        for (int j=2; j <= i/2; j++) {
            if (!(i%j)) {
                prime=0;
            }
        }
        if (prime) {
            int x=i;
            while (x <= n) {
                ans.push_back(x);
                x*=i;
            }
        }
        prime=1;
    }
    int z = ans.size();
    cout << z << endl;
    for (int i=0; i<z; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}