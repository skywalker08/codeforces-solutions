#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int xdec, yinc, xinc, ydec, minx=-1e5, maxx=1e5, miny=-1e5, maxy=1e5;
        int n, x, y, ch1=0,ch2=0,ch3=0,ch4=0;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> x >> y >> xdec >> yinc >> xinc >> ydec;
            if (!xdec) {
                minx=max(x, minx);
                ch1=1;
            } if (!xinc) {
                maxx=min(x, maxx);
                ch2=1;
            }
            if (!ydec) {
                miny=max(y, miny);
                ch3=1;
            } if (!yinc) {
                maxy=min(y, maxy);
                ch4=1;
            }
        }
        if ((minx > maxx && ch1 && ch2 ) || (miny > maxy && ch3 && ch4)) {
            cout << 0 << endl;
        } else {
            cout << 1 << " " << minx << " " << miny << endl;
        }
    }
    return 0;
}