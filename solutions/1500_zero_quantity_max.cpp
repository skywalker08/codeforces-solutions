#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long double arr1[n+1], arr2[n+1];
    for (int i=0;i<n;i++) {
        cin >> arr1[i];
    }
    for (int i=0;i<n;i++) {
        cin >> arr2[i];
    }

    unordered_map<long double, int> c;
    int zero=0, ans=0, sum=0;

    for (int i=0;i<n;i++) {
        if (arr2[i]!=0) {
            long double x = arr1[i]/arr2[i];
            c[x]+=1;
            if (arr1[i]==0) {
                continue;
            }
            ans=max(ans, c[x]);
        } else {
            zero+=1;
            if  (arr1[i]==0) {
                sum+=1;
                continue;
            } 
        }
         
    }
    ans+=sum;
    cout << ((ans>=zero) ? ans : zero) << endl;
}