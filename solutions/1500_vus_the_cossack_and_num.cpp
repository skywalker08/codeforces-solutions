#include <bits/stdc++.h>

using namespace std;

bool isint(double x) {
    int n=x;
    double m=n-x;
    if (m) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    double x;
    std::cout << std::setprecision(5);
    int ans[n][2];
    memset(ans, 0, sizeof ans);
    int sum=0;
    for (int i=0;i<n;i++) {
        cin >> x;
        int y=floor(x);
        ans[i][0]=y;
        if (isint(x)) {
            ans[i][1]=1;
        }
        sum+=y;
    }
    sum*=-1;
    for (int i=0;i<n;i++) {
        if (sum && ans[i][1]==0) {
            cout << ans[i][0] + 1 << endl;
            sum-=1;
            continue;
        }
        cout << ans[i][0] <<endl;
    }
    
    return 0;
    
}