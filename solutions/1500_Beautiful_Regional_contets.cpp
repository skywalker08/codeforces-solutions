#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin>>n;
        int arr[n+2];
        for (int i=n; i>=1;i--) {
            cin >> arr[i];
        }
        int g=1, gm=arr[n], s=0, sm=1, b=0;
        int m=n+1;
        int minn = arr[m/2];
        for (int i=n-1; i>m/2; i--) {
            if ( ((arr[i]<sm && s>g ) || sm==0) && minn<arr[i] ) {
                b+=1;
                sm=0;
            } else if ( gm==0 && minn<arr[i] ){
                s+=1;
                sm=arr[i];
            }
            if (arr[i]<gm && gm>0) {
                s+=1;
                sm=arr[i];
                gm=0;
            }
            else if (gm>0) {
                g+=1;
            } 
            
        }
        if (b>g) {
            cout << g << " " <<  s<< " " << b << endl;
        } else {
            cout << 0 << " " << 0  << " " << 0 << endl;
        }
    }
}