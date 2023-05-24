#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a=0, b=0, ab, ba, ans=0;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> vab, vba;
    for (int i=0;i<n;i++) {
        if (str1[i]=='a') {
            a+=1;
            if (str2[i]=='a') {
                a+=1;
            } else {
                b+=1;
                vab.push_back(i+1);
            }
        }
        else {
            b+=1;
            if (str2[i]=='b') {
                b+=1;
            } else {
                a+=1;
                vba.push_back(i+1);
            }
        }
    }
    if ((!(a%2) && !(b%1) && n>1) || a==0 || b==0 ) {
        int x=0;
        if (vab.size()%2) {
            ans+=1;
            x = vab.back();
            vab.pop_back();
            vba.push_back(x);
        }
        cout << ans+vab.size()/2+vba.size()/2 << endl;
        if (x>0) {
            cout << x << " " << x << endl;
        }
        for (int i=0; i < vab.size(); i+=2) {
            cout << vab[i] << " " <<vab[i+1] << endl;
        }
        for (int i=0; i < vba.size(); i+=2) {
            cout << vba[i] << " " << vba[i+1] << endl;
        }
    }
    else { cout << -1 << endl; }
    return 0;
}