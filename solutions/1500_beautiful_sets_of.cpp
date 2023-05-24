#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,x,y,z;
    cin >> n >> m;
    x=0;
    z=min(n,m);    
    cout << z+1 << endl;
    for (int i=0; i<=z; i++) {
        cout << x << " " << m << endl;
        x+=1;
        m-=1;        
    }
    
    return 0;
}