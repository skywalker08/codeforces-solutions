#include <bits/stdc++.h>
// 1800_Going_home.cpp
using namespace std;

int main() {
    int x,y,sum;
    string ans="NO";
    vector<int> v(x),vsum,vi,vj;
    for (int i=0; i<x; i++) {
        cin >> y;
        v.push_back(y);
    }
    for (int i=0; i<x-1 && ans=="NO"; i++) {
        for (int j=0; j<x; j++) {
            if (i==j) { continue; }
            if (vi.size()>3) { ans="YES"; }
            sum = v[i]+v[j];
            vsum.push_back([i,j,sum]);
            for (int z=0; z<vsum.size()-1; z++) {
                if (sum == v[z][2]) {
                    if (i==v[z][1]) continue;
                    if ( i==v[z][0] ) {vj.push_back(j);}
                    else if (j==v[z][1]) {vi.push_back(i);}
                    else {ans="YES"; vi.clear(); vi.push_back(i);vi.push_back(j);vi.push_back(v[z][1]);vi.push_back(v[z][0]);}
                }
            }
        }
        vj.clear();
    }
    if (ans=="YES") {
        cout << ans << endl;
        if (vi.size()>3) {
            for(int i = 0; i<vi.size(); i++) {
                cout << vi[i] << " ";
            }
        } else {
            for(int i = 0; i<vi.size(); i++) {
                cout << vj[i] << " ";
            }
        }
    } else { cout << ans << endl;}
}
