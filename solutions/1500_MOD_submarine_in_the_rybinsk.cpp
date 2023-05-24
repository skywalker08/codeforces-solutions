#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;
vector<int> pw10;
int add(int a, int b) {
    a += b;
    if (a>=MOD) a-=MOD;
    if (a < 0) a+=MOD;
    return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int f(int a) {
    int pos=0;
    int res=0;
    while (a > 0) {
        int rem = a%10;
        a/=10;
        res = add(res, mul(rem, pw10[2 * pos]));
		res = add(res, mul(rem, pw10[2 * pos + 1]));
		++pos;
    }
    return res;
}

int main() {
    pw10 = vector<int>(30);
	pw10[0] = 1;
	for (int i = 1; i < 30; ++i) {
		pw10[i] = mul(pw10[i - 1], 10);
	}

    int n;
    cin >> n;
    int ct=0, a;
    for (int i=0;i<n;i++) {
        scanf("%d", &a);
        ct =  add(ct, f(a));
    }
    int ans = mul(ct, n);
    cout << ans << endl; 
}