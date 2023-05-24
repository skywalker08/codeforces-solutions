#include <bits/stdc++.h>

using namespace std;

const int maxe=1e5+5;

int dp[maxe]={0};
int arr[maxe];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n; i++) {
        int x=arr[i];
        int sum=0;
        for (int j=1; j*j <= x; j++) {
            if (x%j==0) {
                if (j!=1) {
                    sum=max(sum, dp[j]);
                }
                sum=max(sum,dp[x/j]);
            }
        }
        sum++;
        for (int j=1; j*j <=x; j++) {
            if (x%j==0) {
                dp[j]=sum;
                dp[x/j]=sum;
            }
        }
    }
    cout << *max_element(dp, dp+maxe);
}