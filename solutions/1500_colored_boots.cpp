#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string l, r;
    cin >> l;
    cin >> r;
    vector<stack<int>> ch(124);
    stack<int> q1;
    stack<int> q2;
    stack<pair<int, int>> ans;
    int b;
    for (int i=0;i<n;i++) {
        b=l[i]-'\0';
        if (b==63) {
            q1.push( i+1 );
        } else {
            ch[b].push( i+1 );
        }
        
    }    
    for (int i=0;i<n;i++) {
        b = r[i]-'\0';
        if (b==63) {
            q2.push(i+1);
        } else {
            if (ch[b].empty()) {
                if (!q1.empty()) {
                    ans.push(make_pair(q1.top(), i + 1));
                    q1.pop();
                }
            } else {
                ans.push(make_pair(ch[b].top(),i + 1));
                ch[b].pop();
            }
        }
    }    
    for (int i=97; i<123; i++) {
        if (!q2.empty()) {
            while(!ch[i].empty() && !q2.empty()) {
                ans.push(make_pair(ch[i].top(), q2.top()));
                ch[i].pop();
                q2.pop();
            }
        } else {
            break;
        }
    }
    while (!q2.empty() && !q1.empty()) {
        ans.push(make_pair(q1.top(), q2.top()));
        q1.pop();
        q2.pop();
    }
    n=ans.size();
    cout << n << endl;
    for (int i=0;i<n;i++) {
        cout << ans.top().first << " " << ans.top().second << endl;
        ans.pop();
    }
    return 0;
}