#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> p;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    stable_sort(p.begin(), p.end(), [] (auto &i, auto &j) {return i.first < j.first;});
    int m=0;
    int ans=0;
    for (int i=0; i<n; i++) {
        if (p[i].second > m) {
            m=p[i].second;
            continue;
        }
        if (p[i].second!=m) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}