#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, l, r, m;
        cin >> n >> l >> r;
        int moresock[n+2]={-1}, sock[n+2]={-1}, ms, s; 
        if (l>r) {
            for (int i=0;i<l;i++) {
                cin >> moresock[i];
            }
            for (int i=0;i<r;i++) {
                cin >> sock[i];
            }
            ms=l;
            s=r;
        } else {
            for (int i=0;i<l;i++) {
                cin >> sock[i];
            }
            for (int i=0;i<r;i++) {
                cin >> moresock[i];
            }
            ms=r;
            s=l;
        }
        
        sort(moresock, moresock+ms);
        sort(sock, sock+s);
        int ans=0;
        int last=0;
        for (int i=0; i<s; i++) {
            int y=sock[i];
            while (moresock[last]<=y){
                if ( moresock[last] == y ) {
                    moresock[last] = -1;
                    sock[i] = -1; 
                    last+=1;
                    break;
                }
                last+=1;
            }
        }
        for (int i=0;i<s;i++) {
            if (sock[i]!=-1) {
                ans+=1;
            }
        }
        int sockleft=ms-s;
        for (int i=0;i<ms && sockleft;i++) {
            if (moresock[i]!=-1) {
                if (moresock[i]==moresock[i+1]) {
                    ans+=1;
                    moresock[i]=-1;
                    moresock[i+1]=-1;
                    sockleft-=2;
                }
            }
        }
        ans+=sockleft;
        cout << ans << endl;
    }
}