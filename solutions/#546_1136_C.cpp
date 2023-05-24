#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int x;
    int firstn, lastn;
    map<int, vector<int>> numbers1;
    map<int, vector<int>> numbers2;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {   
            cin >> x;
            if (i==0 && j==0) {
                firstn=x;
            } else if (i==n-1 && j==m-1) {
                lastn=x;
                
            }else numbers1[j+i].push_back(x);
            
        }
    }
    for (int i=1; i<(n-1+m-1); i++) {
        sort(numbers1[i].begin(),numbers1[i].end());
    }
    int flag=1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {   
            cin >> x;
            if (i==0 && j==0) {
                if (firstn!=x) flag=0;
                
            } else if (i==n-1 && j==m-1) {
                if (lastn!=x) flag=0;
            }else numbers2[j+i].push_back(x);
            
        }
    }
    if (flag==0){
        cout << "NO";
        exit(0);
    }
    for (int i=1; i<(n-1+m-1); i++) {
        sort(numbers2[i].begin(),numbers2[i].end());
    }
    for (int i=0;i<(n-1+m-1);i++) {
        for (int j=0; j<numbers1[i].size(); j++) {
            if (numbers1[i][j] != numbers2[i][j]) {
                cout << "NO";exit(0);
            }
        }
    }
    cout << "YES";
    return 0;
}