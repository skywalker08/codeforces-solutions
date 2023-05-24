#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    s += 'b';
    int n=s.size();
    for (int i=1;i < n;i++) {
        if (s[i] != s[i-1]) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
}