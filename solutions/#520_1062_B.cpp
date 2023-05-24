#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int x=n, i = 2, maxc=0,f=0;
    vector<int> v;
    while (x>1) {
        int c=0;
        while (x%i == 0) {
            x /= i;
            c+=1;
        }
        if (c>0) {
            v.push_back(i);
        }
        i++;
        if (c!=maxc && maxc>0 && c>0) {
            f=1;
        }
        maxc=max(maxc,c);
    }
    int ans1=1;
    for (int j=0; j<v.size(); j++) {
        ans1 = ans1 * v[j];
    }
    double k=0;
    if(maxc>1){
        k = (double)(log2(maxc));
    }
    int ans2=k;
    if (ans2 != k) {
        ans2 += 2;
    } else {
        ans2+=f;
    }
    cout << ans1 << " " << ans2;
    return 0;


}