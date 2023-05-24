#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[n+5], ans[n+5], vis[n+5]={0};
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x) {
            vis[x] = 1;
        }
        arr[i]=x;
    }
    list<int> z, m;
    for (int i=1; i<=n; i++) {
        if (!vis[i] && !arr[i]) {
            m.push_back(i);    
            ans[i]=-1;
            continue;
        }
        else if (!vis[i]) {
            z.push_back(i);
        }    
        ans[i]=arr[i];
    }
    if (m.size() == 1) {
        m.push_back(z.front());
        z.pop_front();
        z.push_back(m.front());
        m.pop_front();
    }
    for (int i=1; i<=n; i++) {
        x=ans[i];
        if (x==-1) {
            if (m.front() == i) {
                x=m.back();
                m.pop_back();
            }
            else {
                x=m.front();
                m.pop_front();
            }
        }
        else if (!x) {
            x=z.front();
            z.pop_front();
        }
        cout << x << " ";
    }
    return 0;
}