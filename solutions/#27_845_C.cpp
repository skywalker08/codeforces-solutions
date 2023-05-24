#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> shows(n);
    int a,b;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        shows[i] = make_pair(a, b);
    }
    sort(shows.begin(), shows.end(), []( auto &i, auto &j) {return i.first < j.first;});
    string ans="YES";
    int tv1=-1, tv2=-1;
    for (int i=0 ; i < n; i++) {
        // cout << tv1 << "x" << shows[i].first << " ";
        if (tv1 < shows[i].first) {
            tv1 = shows[i].second;
        } else {
            // cout << tv2 << "x" << shows[i].first << " ";
            if (tv2 < shows[i].first) {
                tv2=shows[i].second;
            } else {
                ans="NO";
            }
        }
    }
    cout << ans;
    return 0;

}