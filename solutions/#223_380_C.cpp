#include <bits/stdc++.h>

using namespace std;

const int maxe=1e5+5;
int open[maxe], closed[maxe];

int main() {
    string str;
    cin >> str;
    memset(closed, 0, sizeof(closed));
    memset(open, 0, sizeof(open));
    int n = str.size();
    int ct=0;
    for (int i=0; i<n; i++) {
        if (str[i]=='(') {
            ct+=1;
            closed[i+1]=closed[i];
        } else {
            closed[i+1]=closed[i];
            if (ct>0) {
                closed[i+1]=closed[i]+1;
                ct--;
            }
        }
    }
    for (int i=n-1; i>=0; i--) {
        if (str[i]=='(') {
            open[i+1]=open[i+2]+1;
        } else open[i+1]=open[i+2];
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        int z=closed[y]-closed[x-1];
        int w=open[x]-open[y+1];
        cout << (min(z, w)*2) << endl;
    }
    return 0;
}