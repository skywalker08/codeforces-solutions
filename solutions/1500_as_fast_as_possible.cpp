#include <bits/stdc++.h>

using namespace std;

int main() {
    float n, l, v1, v2, k, pp=0.0f, ans=0.0f, tb1, pob;
    cin >> n >> l >> v1 >> v2 >> k;
    pob=l;
    while (n && pp<l) {
        tb1=pob/v2;
        cout << tb1 << "tb1";
        pp+=tb1*v1;
        cout << pp << "pp";
        ans+=tb1;
        n-=k;
        if (n>0 && pp<l) {
            tb1=(l-pp) / (v2+v1);
            ans+=tb1;
            pp+=tb1*v1;
            pob=pp;
        } else { break; }
    }
    printf("%f", ans);
}