#include <bits/stdc++.h>

using namespace std;
set<int> st;
int arr[79];

int check() {
    int r=0;
    for (int u: st) {
        if (arr[u]>0) {
            r+=1;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans=n;    
    for (int i=0; i<n; i++) {
        st.insert(str[i]-'0');
    }
    int x = st.size();
    int l=0;
    for (int r=0; r<n && ans != x; r++) {
        arr[str[r]-'0']+=1;
        while(x == check()) {
            ans=min(ans, r-l+1);
            arr[str[l]-'0']-=1;
            l+=1;
        }
    }
    cout << ans;
}