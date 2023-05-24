#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int answer[n+2]={0};
    set<int> alive;
    for (int i = 0; i < n; i++)
        alive.insert(i);
    
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--, r--, x--;        
        set<int>::iterator it = alive.lower_bound(l);
        vector<int> toErase;        
        while(it != alive.end()){
            int cur = *it;            
            if(cur > r)
                break;                
            if(cur != x){    
                toErase.push_back(cur); answer[cur] = x+1;
            }
            it++;
        }

        for (size_t j = 0; j < toErase.size(); j++)
            alive.erase(toErase[j]);
    }

    for (int i=0; i<n;i++) {
        cout << answer[i] << " ";
    }
}