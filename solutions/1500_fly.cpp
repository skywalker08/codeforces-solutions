#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    double land[n+2], liftoff[n+2];
    double x;
    double f=0, fn;
    for (int i=1;i<=n;i++) {
        cin >> x;
        liftoff[i]=x;
        if (x==1) {
            f=-1;
        }
    }
    for (int i=1;i<=n;i++) {
        cin >> x;
        land[i]=x;
        if (x==1) {
            f=-1;
        }
    }
    if (f==-1) {
        cout << f << endl;
        return 0;
    }
    f=m/(land[1]-1);
    for (int i=n;i>0;i--) {
        fn=(f*liftoff[i] + m)/(liftoff[i]-1);
        f=fn;
        if (i>1) {
            fn=(f * land[i] + m)/(land[i]-1);
            f=fn;
        }
    }
    cout << fixed;
    cout << std::setprecision(10);
    cout << f;
    return 0;
}