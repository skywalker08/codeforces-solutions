#include <bits/stdc++.h>

using namespace std;

const int maxe = 3e5+5;

int arr[maxe][8];

int n, m;
int ans1, ans2;
bool can(int mid) {
    vector<int> msk(1 << m, -1);

    for (int i=0; i < n; i++) {
        int c = 0;
        for (int j=0; j<m; j++) {
            if (arr[i][j] >= mid) {
                c ^= (1 << j); 
            }
        }
        msk[c] = i;
    }
    
    if (msk[(1 << m) - 1] != -1) {
        ans1 = ans2 = msk[(1 << m) - 1];
        return true;
    } 
    for (int i=0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (msk[i] != -1 && msk[j] != -1 && (i | j) == (1 << m) - 1) {
                ans1 = msk[i];
                ans2 = msk[j];
                return true;
            }
        }
    }
    return false;
}


int main() {
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int l = 0;
    int r = int(1e9) + 9;
    while (l <= r) {
        int mid = (r + l) / 2;
        if (can(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans1 + 1 << " " << ans2 + 1;
}