#include <bits/stdc++.h>

using namespace std;

const int maxe=2e3+5;
int arr[maxe];
int main() {
    int n, ans=1e5;
    cin >> n;
    map<int, int> c;
    for (int i=0;i<n;i++) {
        cin >> arr[i];        
    }
    int j=n;
    while (0<=j) {
        j--;
        if (c[arr[j]]<1) {
            c[arr[j]]+=1;
        } else {
            break;
        }
    }
    for (int i=0;i<n;i++) {
        ans=min(ans, j-i+1);
        c[arr[i]]+=1;
        while (j < n && c[arr[i]] > 1) {
            j+=1;
            c[arr[j]]-=1;
        }
        if (c[arr[i]]>1) {
            break;
        }
    }
    cout << ans;
}