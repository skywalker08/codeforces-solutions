#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    long long x;
    long long arr[n], sorted[n];
    for (int i=0; i<n; i++) {
        cin >> x;
        arr[i]=x;
        sorted[i]=x;
    }
    sort(sorted, sorted+n, greater<long long>());
    map<long long, int> cta;
    long long minn=sorted[m*k-1];
    long long ansct=0LL;
    for (int i=0;i<m*k;i++){
        cta[sorted[i]]++;
        ansct+=sorted[i];
    }
    int c=0;
    vector<int> ans;
    for (int i=0;i<n;i++){
        if (arr[i] >= minn) {
            if (cta[arr[i]]>0) {
                c+=1;
                cta[arr[i]]--;
            }
            if ( c == m) {
                ans.push_back(i+1);
                c=0;
            }
        }
        if (ans.size()==k-1) {
            break;
        }
    }
    cout << ansct << endl;
    for (int i=0; i<k-1;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}