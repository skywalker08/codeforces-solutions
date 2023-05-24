#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int box = 1;
    int ct=0;
    string str;
    stack<int> s;
    for (int i=0; i < n * 2; i++) {
        cin >> str;
        if (str[0] == 'r') {
            if (!s.empty()) {
                if (s.top() == box) {
                    s.pop();
                } else {
                    ct++;
                    while(!s.empty()) s.pop();
                }
            }
            box++;
        } else {
            int x;
            cin >> x;
            s.push(x);
        }
    }
    cout << ct;
    return 0;
}