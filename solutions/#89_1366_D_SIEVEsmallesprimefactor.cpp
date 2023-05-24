#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7+1;

int spf[MAXN];
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

int main() {
    int n; cin >> n;
    int a;
    int ans1[n], ans2[n];
    sieve();
    for (int i=0;i<n;i++) {
        scanf("%d", &a);
        int s = spf[a];
        if (s == a) {
            ans1[i] = -1;
            ans2[i] = -1;
            continue;
        }
        while (a % s == 0) {
            a /= s;
        }
        if (a>1) {
            ans1[i]=a;
            ans2[i]=s;
        } else {
            ans1[i]=-1;
            ans2[i]=-1;
        }
    }
    for (int i=0; i<n; i++) {
        cout << ans1[i] << " ";
    } 
    cout << "\n";
    for (int i=0; i<n; i++) {
        cout << ans2[i] << " ";
    }
    return 0;
}