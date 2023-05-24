#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int i=0, k=0, ans=1;
        string s = s1;
        while (i<n) {
            if (k) {
                if (s[i]-'0' <= 2) {
                    ans=0;
                    break;
                }
                i+=1;
                k=0;
            }
            else if (s[i]-'0' > 2) {
                if (s == s1) { s=s2; }
                else { s=s1; }
                k=1;
            }
            else { 
                i+=1;
            }
        }
        if (s==s1) ans=0;
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}