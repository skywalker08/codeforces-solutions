#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int countz(unsigned int a) {
    int ct=0;
    if (!(a&32)) 
        ct++;
    if (!(a&16)) 
        ct++;
    if (!(a&8)) 
        ct++;
    if (!(a&4))
        ct++;
    if (!(a&2))  
        ct++;
    if (!(a&1)) 
        ct++;
    return ct;
}   

const ll mod=1e9+7;

ll ipow(ll b, ll t) {
    ll r=1;
    while(t) {
        if(t&1){r = r * b % mod;}
        b= b * b % mod;
        t>>=1;
    }
    return r;
}

int main() {
    string str;
    cin >> str;
    int n = str.size();
    unsigned int a[n];
    for (int i=0;i<n;i++) {
        if (str[i]=='-')
            a[i]=62;
        else if (str[i]=='_')
            a[i]=63;
        else if (isdigit(str[i]))
            a[i]=str[i]-48;
        else if (isupper(str[i]))
            a[i]=str[i]-55;
        else if (islower(str[i]))
            a[i]=str[i]-61;
    }
    int ct=0;
    for (int i=0;i<n;i++) {
        // cout << a[i] << " ";
        ct += countz(a[i]);
    }
    printf("%lld", (ipow(3, ct)));
    return 0;
}