#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[102], c[102]={0};
    for (int i=0;i<n;i++) {
        cin >> x;
        arr[i]=x;
        c[x]+=1;
    }
    int c1=0, flag=0;
    for (int i=0;i<n;i++) {
        if (c[arr[i]]==1) {
            c1+=1;
        } else if (c[arr[i]]>2) {
            flag=1;
        }
    }
    char ans[2]={'A','B'};
    int j=1;
    char ansarr[102], z;
    memset(ansarr, 'x', 102);
    if (c1%2) {
        if (flag==0 || n==3) {
            cout << "NO" << endl;
            return 0;
        }
        int flag2=0;
        cout << "YES" << endl;
        for (int i=0;i<n;i++) {
            if (c[arr[i]]>2 && flag2==0) {
                flag2=1;
                if (ans[j]=='B') {
                    z='A';
                }
                else {
                    z='B';
                }
                ansarr[i]=ans[j];
                j=(j+1)%2;
            } else if(c[arr[i]]==1) {
                ansarr[i]=ans[j];
                j=(j+1)%2;
            }
        }
    } else {
        if ((c1 && n==3)) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for (int i=0;i<n;i++) {
            if(c[arr[i]]==1) {
                cout << ans[j];
                j=(j+1)%2;
            } else {
                cout << 'A';
            }
        }
        return 0;
    }
    for (int i=0;i<n;i++) {
        if (ansarr[i]=='x') {
            cout << z;
            continue;
        }
        cout << ansarr[i];
    }
}