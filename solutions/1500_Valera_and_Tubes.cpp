#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int x=1, y=1, c=2, t=0, a=1;
    for (int i=1; i<=k; i++) {
        if (i==k) {
            c = n*m - t;
        }
        cout << c;
        while (c>0) {
            cout << " " << x << " " << y;
            if (a%2) {
                y++;    
            } else { y--; }
            if (y > m || y < 1) {
                if (a%2) { y-=1; }
                else { y+=1; }
                x++;
                a^=1;
            }
            c--;
            t++;
        }
        cout << endl;
        c=2;
    }
}