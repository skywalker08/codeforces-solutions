#include <bits/stdc++.h>

using namespace std;

int main() {
    string num;
    cin >> num;
    int n=num.size(), ans=0, sp=-1;
    for (int i=0;i<n;i++) {
        int z=0;
        int f=0;
        for (int j=i; j>sp; j--) {
            z+=num[j]-'0';
            if (z%3==0) {
                f=1;
                break;
            }
        }
        if(f) {
            sp=i;
            ans+=1;
        }
    }
    cout << ans << endl;

}