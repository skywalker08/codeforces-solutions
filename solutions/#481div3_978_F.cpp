#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int skill[n][2];
    for (int i=0;i<n;i++) {
        cin >> skill[i][0];
    }
    int sortedskill[n];
    iota(sortedskill, sortedskill+n, 0);
    stable_sort(sortedskill, sortedskill+n, [&skill] (int i, int j) {return skill[i][0] < skill[j][0];});
    skill[sortedskill[0]][1]=0;
    for (int i=1;i<n;i++) {
        int x = sortedskill[i];
        int y = sortedskill[i-1];
        if (skill[x][0] > skill[y][0]) {
            skill[x][1]=i;
        } else {
            skill[x][1] = skill[y][1];
        }
    }
    int x, y;
    for (int i=0;i<k;i++) {
        cin >> x >> y;
        x-=1;
        y-=1;
        if (skill[x][0] > skill[y][0]) {
            skill[x][1]-=1;
        } else if (skill[x][0] < skill[y][0]) {
            skill[y][1]-=1;
        }
    }
    for (int i=0;i<n;i++) {
        cout << skill[i][1] << " ";
    }
    return 0;
}