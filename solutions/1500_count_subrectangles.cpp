#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, c=0;
    vector<int> row;
    vector<int> column;
    for (int i=0;i<n;i++) {
        cin >> x;
        if (x==0) {
            if (c>0) {
                row.push_back(c);
            }
            c=0;
        } else {
            c+=1;
        }
    } 
    if (c>0) {
        row.push_back(c);
    }
    c=0;
    for (int i=0;i<m;i++) {
        cin >> x;
        if (x==0) {
            if (c>0) {
                column.push_back(c);
            }
            c=0;
        } else {
            c+=1;
        }
    }
    if (c>0) {
        column.push_back(c);
    }
    
    vector<pair<int, int>> divs;
    pair<int, int> p;
    for (int i=1; (i * i) <= k; i++) {
        if (k%i==0) {
            p = make_pair(i, k/i);
            divs.push_back(p);
        }
    }
    long long dp[n+1]={0};
    n=row.size();
    m=column.size();
    long long ans=0;
    long long save=0;
    for (int i=0;i<n;i++) {
        save = 0;
        if (dp[row[i]]>0) {
            ans+=dp[row[i]];
            continue;
        }
        for (int j=0; j<m; j++) {
            for (auto p : divs) {
                int flag=0;
                if (p.first <= row[i] && p.second <= column[j]) {
                    ans += (row[i]-p.first+1) * (column[j]-p.second+1);
                    save += (row[i]-p.first+1) * (column[j]-p.second+1);
                    flag=1;
                }
                if (p.first!=p.second) {
                    if (p.second <= row[i] && p.first <= column[j]) {
                        ans += (row[i]-p.second+1) * (column[j]-p.first+1);
                        save +=(row[i]-p.second+1) * (column[j]-p.first+1);
                        flag=1;
                    }
                }
                if (flag==0) {
                    break;
                }
            }
        }
        dp[row[i]] = save;
    }
    cout << ans << endl;
}