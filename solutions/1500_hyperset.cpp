#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int ans=0;
    string str1, str2;
    map<string, int> find;
    for (int i=0;i<n-1;i++) {
        str1=arr[i];
        for (int j=i+1; j<n; j++) {
            str2=arr[j];
            string str3;
            for (int z=0;z<k;z++) {
                if (str1[z]==str2[z]) {
                    str3+=str1[z];
                }
                else if (str1[z]!=str2[z]) {
                    if (str1[z]!='S' && str2[z]!='S') {
                        str3+='S';
                    } else if (str1[z]!='T' && str2[z]!='T') {
                        str3+='T';
                    }
                    else {
                        str3+='E';
                    }
                    
                }
            }
            find[str3]+=1;      
        }
    }

    for (int i=0;i<n;i++) {
        if (find[arr[i]]>0) {
            ans+=find[arr[i]];
            find[arr[i]]=0;
        }
    }
    cout << ans / 3 << endl;
}