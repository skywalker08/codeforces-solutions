#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int tt; 
    cin >> tt;
    while (tt--) {
        ll n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;
        ll top=0, ans=b, i=0;
        while(i<n) {
            if (top) {
                if (str[i+1]=='1') {
                    ans+=2*b + a;
                    i+=1;
                }
                else {
                    ans+=2*b + a;
                    i+=1;
                    ll c0=0;
                    while (str[i]=='0' && i<n)
                    {
                        c0+=1;
                        i+=1;
                    }
                    if (c0>1) {
                        if (((c0-1)*b) > 2*a || i == n) {
                            ans += c0 * b + c0 * a + 2 * a;
                            ans+=b;
                            if (i==n) {
                                ans-=a;
                                ans-=b;
                            }
                        } 
                        else {
                            ans+= (c0) * (b*2) + c0 * a;
                        }
                    }
                    else {
                        ans+=2*b + a;
                        if (i==n) {
                                ans-=b;
                                ans+=a;
                            }
                    }

                }   
            } else {
                if (str[i+1]=='1') {
                    ans+=2*b + 2*a;
                    top=1;
                    i+=1;
                }
                else {
                    ans+=b+a;
                    i+=1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}