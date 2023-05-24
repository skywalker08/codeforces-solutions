#include <bits/stdc++.h>

using namespace std;

int ispali(string str) {
    int a = 1;
    for (int i=0;i<=str.size()/2; i++) {
        if (str[i]!=str[n-1-i]) {
            a=0;
        }
    }
    return a;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x;
        string s, str="", ans;
        vector<char> prefix, prefix1;
        stack<char> suffix, suffix1;
        string pre, suf;
        int n = s.size();
        cin >> s;
        for (int i=0; i<=n/2; i++) {
            if (s[i]==s[n-1-i]) {
                pre+=s[i];
                suf+=s[n-1-i];
                prefix.push_back(s[i]);
                suffix.push(s[n-1-i]);
            }
            else {
                break;
                x=i;
            }
        }
        for (int i=x; i<=n-1-x; i++) {
            str+=s[i];
            if (ispali(str)) {
                ans=str;
            }
        }
        if (ispali(pre+ans)) {
            if ((pre+ans).size() > pre+ans+)
        }
        
        // for (int i=0;i<prefix.size();i++) {
        //     pre+=prefix[i];
        //     suf+=suffix.top();
        //     suffix.pop();
        // }


    }
}