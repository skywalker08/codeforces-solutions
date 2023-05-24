#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n;
        int arr[n], ansmin[n], ansmax[n], usedmi[n+1]={0};
        for (int i=0; i<n;i++) {
            cin >> x;
            arr[i]=x;
        }
        stack<int> usable;
        int y, z=1;
        for (int i=0; i<n; i++) {
            if (i==0) {
                y=arr[i];
                for (int j=1; j<y; j++) {
                    usable.push(j);
                }
                ansmin[i]=y;
                ansmax[i]=y;
                usedmi[y]=1;
            }
            else if (arr[i]>y) {
                for (int j=y+1; j<arr[i]; j++) {
                    usable.push(j);
                }
                y=arr[i];
                ansmin[i]=y;
                ansmax[i]=y;
                usedmi[y]=1;
            }
            else {
                ansmax[i]=usable.top();
                usable.pop();
                while (true) {
                    if (usedmi[z]<1) {
                        ansmin[i]=z;
                        z+=1;
                        break;
                    }
                    z+=1;
                }
            }
        }
        for (int i=0;i<n;i++) {
            cout << ansmin[i] << " ";
        }
        cout <<  endl;
        for (int i=0;i<n;i++) {
            cout << ansmax[i] << " ";
        }
        cout <<  endl;
    }
    return 0;
}