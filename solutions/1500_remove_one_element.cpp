#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, n, ans=0;
    cin >> a;
    int arr[a+2], cnt[a+2]={0}, cnt2[a+2]={0};
    int pren, pre2n;
    for(int i=1; i<=a; i++) {
        cin >> arr[i];
    }
    arr[0]=0;
    for (int i=1; i<=a; i++) {
        n=arr[i];
        pren=arr[i-1];
        if ( n > pren) {
            cnt2[i]=cnt2[i-1]+1;
            cnt[i]=cnt[i-1]+1;
        }
        else  {
            cnt2[i]=1;
            if (arr[i-2] < n || arr[i+1]>arr[i-1]) {cnt[i]=cnt2[i-1];}
            else {
                cnt[i]=1;
            }
        }
        ans=max(cnt[i],ans);
    }
    cout << ans << endl;
}