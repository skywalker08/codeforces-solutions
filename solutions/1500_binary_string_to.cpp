#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, cnt=0, x;
        string str;
        cin >> n;
        cin >> str;
        stack<int> st1, st0;
        int arr[n];
        for (int i=0; i<n; i++) {
            if( str[i]=='1' ) { 
                if (st1.empty()) {
                    cnt+=1;
                    arr[i]=cnt;
                    st0.push(cnt);
                }
                else {
                    x = st1.top();
                    st0.push(x);
                    st1.pop();
                    arr[i]=x;
                }
            }
            else  {
                if (st0.empty()) {
                    cnt+=1;
                    arr[i]=cnt;
                    st1.push(cnt);
                }
                else {
                    x = st0.top();
                    st1.push(x);
                    st0.pop();
                    arr[i] = x;
                }
            }
        }
        cout << cnt << endl;
        for (int i=0; i<n; i++) {
            cout << arr[i] <<  " ";
        }
        cout << endl;
    }
    return 0;
}