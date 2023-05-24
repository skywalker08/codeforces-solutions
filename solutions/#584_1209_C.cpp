#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int arr[n];
        for (int i=0;i<n;i++) {
            arr[i]=str[i]-'0';
        }
        int ansflag=0;
        string ans;
        for (int x=1; x < 10 && ansflag==0; x++) {
            ans="";
            int flag=1;
            for (int i=0; i<n; i++) {
                ansflag=1;
                if (arr[i] == x) {
                    if (flag) {
                        ans+='2';
                    } else ans+='1';
                } else if (arr[i] > x) {
                    flag = 0;
                    ans+='2';
                } else {
                    ans+='1';
                }
            }
            // cout << ans << endl;
            int n1, n2, p1=-1, p2=-1;
            for (int i=0; i<n; i++) {
                if (ans[i]=='1') {
                    n1=arr[i];
                    if (n1 < p1) {
                        ansflag=0;
                    }
                    p1=n1;
                } else {
                    n2=arr[i];
                    if (n2 < p2) {
                        ansflag=0;
                    }
                    p2=n2;
                }
            }
        }
        if (ansflag==0) {
            cout << "-" <<endl;
            continue;
        } 
        cout << ans << endl;
    }

}