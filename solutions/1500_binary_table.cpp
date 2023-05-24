#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        string line;
        int table[n][m];
        for (int i=0;i<n;i++) {
            cin >> line;
            for (int j=0;j<m;j++) {
                table[i][j]=line[j]-'0';
            }
        }
        int i=0, j;
        int k=0;
        vector<int> ans;
        while (i<n) {
            j=0;
            if (i==n-1) {
                i-=1;
            }
            while (j<m) {
                if (j==m-1) {
                    j-=1;
                }
                vector<int> ones, zeros; 
                int ct=0;
                for (int y=i; y<i+2; y++) {
                    for (int x=j; x<j+2; x++) {
                        if (table[y][x]==1) {
                            ct+=1;
                            ones.push_back(y+1);
                            ones.push_back(x+1);
                            table[y][x]=0;
                        } else {
                            zeros.push_back(y+1);
                            zeros.push_back(x+1);
                        }
                    }
                }
                if (ct==1) {
                    k+=3;
                    ans.push_back(ones[0]);
                    ans.push_back(ones[1]);
                    ans.push_back(zeros[0]);
                    ans.push_back(zeros[1]);
                    ans.push_back(zeros[2]);
                    ans.push_back(zeros[3]);
                    ans.push_back(ones[0]);
                    ans.push_back(ones[1]);
                    ans.push_back(zeros[0]);
                    ans.push_back(zeros[1]);
                    ans.push_back(zeros[4]);
                    ans.push_back(zeros[5]);
                    ans.push_back(ones[0]);
                    ans.push_back(ones[1]);
                    ans.push_back(zeros[2]);
                    ans.push_back(zeros[3]);
                    ans.push_back(zeros[4]);
                    ans.push_back(zeros[5]);
                } else if (ct==2) {
                    k+=2;
                    ans.push_back(ones[0]);
                    ans.push_back(ones[1]);
                    for (int z=0;z<4;z++) {
                        ans.push_back(zeros[z]);
                    }
                    ans.push_back(ones[2]);
                    ans.push_back(ones[3]);
                    for (int z=0;z<4;z++) {
                        ans.push_back(zeros[z]);
                    }
                } else if (ct==3) {
                    k+=1;
                    for (int z=0;z<6;z++) {
                        ans.push_back(ones[z]);
                    }
                } else if (ct==4) {
                    k+=4;
                    for (int z=0;z<6;z++) {
                        ans.push_back(ones[z]);
                    }
                    ans.push_back(ones[6]);
                    ans.push_back(ones[7]);
                    ans.push_back(ones[0]);
                    ans.push_back(ones[1]);
                    ans.push_back(ones[2]);
                    ans.push_back(ones[3]);
                    ans.push_back(ones[6]);
                    ans.push_back(ones[7]);
                    ans.push_back(ones[2]);
                    ans.push_back(ones[3]);
                    ans.push_back(ones[4]);
                    ans.push_back(ones[5]);
                    ans.push_back(ones[0]);
                    ans.push_back(ones[1]);
                    ans.push_back(ones[4]);
                    ans.push_back(ones[5]);
                    ans.push_back(ones[6]);
                    ans.push_back(ones[7]);
                }
                j+=2;
            }
            i+=2;
        }
        cout << k << endl;
        n=ans.size();
        for (int i=0;i<n;i++) {
            cout << ans[i] << " ";
            if ((i+1)%6==0) {
                cout << endl;
            }
        }
    }
    return 0;
}