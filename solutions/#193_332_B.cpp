#include <bits/stdc++.h>

using namespace std;

pair<long long, int> maxsum[200005];

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n+1];
    for(int i=0;i < n; i++) {
        cin >> arr[i];
    }
    vector<long long> sum;
    long long x=0;
    for (int i=0; i<n; i++) {
        x += arr[i];
        if (i == k - 1) {
            sum.push_back(x);
        }
        if (i > k - 1) {
            x -= arr[i - k];
            sum.push_back(x);    
        }
    }
    int m = sum.size();
    long long totalsum=0;
    int a1=0, a2=0;
    for (int i = m - 1; i>=0; i--) {
        long long s = sum[i];
        maxsum[i] = maxsum[i+1];
        if (s >= maxsum[i].first) {
            maxsum[i].first = s;
            maxsum[i].second = i;
        }
        if (totalsum <= s + maxsum[i + k].first) {
            totalsum=s + maxsum[i+k].first;
            a1 = i;
            a2 = maxsum[i+k].second;
        }
    }
    cout << a1+1 << " " <<  a2+1;
    return 0;
}