#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    deque<int> voted, voter;
    for (int i=0; i < n; i++) {
        if (str[i]=='D') {
            voted.push_back(i+1);
        } else {
            voter.push_back(i+1);
        }
    }
    while ((!voted.empty()) && (!voter.empty())) {
        // cout << voted[0] << "x" << voter[0] << " ";
        if (voted[0] < voter[0]) {
            voter.pop_front();
            int temp = voted[0];
            voted.pop_front();
            voted.push_back(temp+n);
        } else {
            voted.pop_front();
            int temp = voter[0];
            voter.pop_front();
            voter.push_back(temp+n);
        }
        
    }
    if (voted.empty()) {
        cout << 'R';
    } else {
        cout << 'D';
    }
    return 0;
}