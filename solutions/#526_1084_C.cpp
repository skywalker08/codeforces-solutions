#include <bits/stdc++.h>

using namespace std;

const long long MOD=1e9+7;

long long add(long long a, long long b) {
    a += b;
    if (a>=MOD) a-=MOD;
    if (a < 0) a+=MOD;
    return a;
}

long long mul(long long a, long long b) {
	return a * b % MOD;
}

int main() {
    string str;
    cin >> str;
    int n=str.size();
    int f=0, ct=0;
    vector<long long> cts;
    for(int i=0;i<n;i++) {
        if (str[i]=='a') {
            ct+=1;
            f=1;
        } else if (str[i]=='b' && f) {
            cts.push_back(ct);
            ct=0;
            f=0;
        }
    }
    if (ct>0) cts.push_back(ct);
    long long ans=0;
    for (int i=0;i<cts.size(); i++) {
        ans = add(ans,mul(cts[i],ans));
        ans = add(ans,cts[i]);       
    }
    cout << ans;
    return 0;
}