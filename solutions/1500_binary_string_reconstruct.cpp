#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        string str;
        cin >> str;
        int n = int(str.size());
        
        int x, arr[n], ans=1, c;
        cin >> x;
        int i = 0; 
        while ( i - x < 0 ) {
            arr[i] = str[i+x] - '0';
            i++;
        }
        while ( i + x < n) {
            
            if ( str[i+x] == str[i-x] ) {
                arr[i] = str[i+x]-'0';
            }
            else { ans=0; break; }
            i++;
        }
        while (i < n) {
            arr[i]=str[i-x] - '0'; 
            i++;
        }
        if (ans) {
            for (int i=0; i<n; i++) {
                cout << arr[i];
            }
        }
        else {
            cout << -1;
        }
        cout << endl;
    }

}