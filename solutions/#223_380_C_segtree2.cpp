#include <bits/stdc++.h>

using namespace std;
string str;

const int N = 1e6 + 13;
pair<int, int> items[4 * N];

void build(int v, int l, int r) {
    if (l == r-1) {
        items[v].first = str[l]=='(';
        items[v].second = str[l]==')';
        return;
    }

    int m = (l+r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);

    int t = min(items[2*v].first, items[2*v+1].second);
    items[v].first = items[2*v].first + items[2*v+1].first - t;
    items[v].second = items[2*v].second + items[2*v+1].second - t;
}

pair<int, int> get(int v, int l, int r, int L, int R) {
    if (l >= R || r <= L) {
        return {0, 0};
    } 

    if (l >= L && r <= R) {
        return items[v];
    } 

    int m=(l+r)/2;

    pair<int, int> item1 = get(2 * v, l, m, L, R);
    pair<int, int> item2 = get(2 * v + 1, m, r, L, R);
    pair<int, int> item3;

    int t = min(item1.first, item2.second);
    item3.first = item1.first + item2.first - t;
    item3.second = item1.second + item2.second - t;

    return item3;
}

int main() {
    cin >> str;
    int n = str.size();
    build(1, 0, n);
    int tt;
    cin >> tt;
    while (tt--) {
        int l, r;
        scanf("%d%d", &l, &r);
        pair<int, int> ans = get(1, 0, n, l - 1, r);
        cout << r - l + 1 - (ans.first + ans.second)  << "\n";

    }
    return 0;
}